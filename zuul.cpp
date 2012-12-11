#include <iostream>
#include "zuul.h"

//define used variables
#define MAX_BYTES 101


char g_input[MAX_BYTES];

bool Zuul::g_quit = false;
bool next_turn = false;

std::vector<std::string> Zuul::g_commands;
std::vector<Command*> Zuul::g_command_vector;
std::vector<NPC*> Zuul::g_npc_vector;

Player* Zuul::g_player;
Map * map;

//std::multimap<std::string, void (Zuul::*)(std::vector<std::string>)> Zuul::g_commad_map;

Zuul::Zuul(){ }

Zuul::~Zuul(){ 
	delete g_player;
}

int Zuul::run(int argc, char** argv) {

	init();
	print_welcome_msg();
	get_adventurer_name();
	print_help_msg(g_commands);
	print_valid_directions();
	
	while(!g_quit) {
		read_command();
		exec_command();
		if(is_end_of_game())
			continue;
		if(next_turn){

			next_turn = false;
			//std::cout<<"debugg starting npc action"<<std::endl;
			npc_action();
			//std::cout<<"debugg finished npc action"<<std::endl;
			if(is_end_of_game())
				continue;
			look(g_commands);
		}
	}
	print_end_msg();
	return 1;
}
void Zuul::print_welcome_msg(void) const{
	std::cout << "Welcome to the World of Zuul!" << std::endl << std::endl;
	std::cout << "Your task is to destory the Skeleton King!" << std::endl << std::endl;
}
void Zuul::get_adventurer_name(void) {
	std::cout << "Please enter the name of your adventurer!" << std::endl;
	std::cin.getline (g_input, MAX_BYTES);
	g_player = new Player(map->get_starting_position());
	g_player->set_name(g_input);
}

void Zuul::print_help_msg(std::vector<std::string>& commands){
	print_valid_commands();
}
void Zuul::print_map(std::vector<std::string>& commands) {
	std::cout<<(*map);
}

void Zuul::print_valid_commands(void) const{
	std::cout << "Available game commands: ";
	bool first = true;
	for (auto it = g_command_vector.begin(); it != g_command_vector.end();++it) {
		if(first) {
			//std::cout << (*it).first ;
			std::cout << (*it)->get_name();
			first = false;
		}
		else {
			//std::cout << ", "<< (*it).first ;
			std::cout << ", "<< (*it)->get_name();
		}
	}
	std::cout << std::endl<< std::endl;
}

void Zuul::read_command(void) {
	std::cin.getline (g_input, MAX_BYTES);
}

void Zuul::init(void) {
	srand ( time(NULL) );
	init_map();
	init_npc();
	init_program_commands();
}
void Zuul::init_map(void) {
	map = new Map();
}
void Zuul::init_program_commands(void) {
	std::string s = "go";
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::go, this));
	s = "look";
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::look, this));
	s = "attack";
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::attack, this));
	s = "talk";
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::talk, this));
	s = "quit";
	//new GameCommand<void (Zuul::*)(std::vector<std::string> commands), Zuul*> command(s, &Zuul::quit, this);
	//g_command_vector.push_back(new (Zuul::*)(std::vector<std::string> commands), Zuul*> (s, &Zuul::quit, this));
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::quit, this));
	s = "help";
	//g_command_vector.push_back(GameCommand<void (Zuul::*)(std::vector<std::string> commands)>(s, &Zuul::print_help_msg));
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::print_help_msg, this));
	s = "map";
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::print_map, this));
	s = "info";
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string>& commands), Zuul*>(s, &Zuul::info, this));
	/*g_commad_map.insert(std::pair<std::string, void (Zuul::*)(std::vector<std::string> commands)>("quit", &Zuul::quit));
	g_commad_map.insert(std::pair<std::string, 
		void (Zuul::*)(std::vector<std::string> commands)>("help", &Zuul::print_help_msg));*/
	
}

void Zuul::print_valid_directions(void) const {
	std::string dir;
	g_player->get_current_tile().get_valid_directions(dir);
	std::cout<<"Valid directions: "<<dir<<std::endl<<std::endl;
}

void Zuul::go(std::vector<std::string>& commands) {
	if(commands.size() != 2){
		print_input_error_msg();
	}
	if(!g_player->move(commands[1])) {
		std::cout<<'"'<<commands[1]<<'"'<<" is not a valid direction."<<std::endl;
		
	}
	else {
		next_turn = true;
		print_valid_directions();
	}
}

void Zuul::look(std::vector<std::string>& commands) {
	bool found_something = false;
	auto it = g_npc_vector.begin();
	while(it != g_npc_vector.end()) {
		Tile temp_tile = (*it)->get_current_tile();
		if(temp_tile == g_player->get_current_tile()){
			std::cout<<"There is a "<<(*it)->get_name()<<" close to you."<<std::endl;
			found_something = true;
		}
		++it;
	}
	if(!found_something)
		std::cout<<"There is nothing special around you."<<std::endl;
}

void Zuul::attack(std::vector<std::string>& commands) {
	bool attacked = false;
	next_turn = true;
	auto it = g_npc_vector.begin();
	while(it != g_npc_vector.end()) {
		Tile temp_tile = (*it)->get_current_tile();
		if(temp_tile == g_player->get_current_tile()){
			attacked = true;
			if((*it)->get_attacked(*g_player)) {
				NPC* npc_p = (*it);
				std::cout<<"You have killed "<<npc_p->get_name()<<"!"<<std::endl;
				g_npc_vector.erase(it);
				//std::cout<<"debugg1"<<std::endl;
				delete npc_p;
				//std::cout<<"debugg2"<<std::endl;
				--it;
				//std::cout<<"debugg3"<<std::endl;
			} else {
				std::cout<<"You have injured "<<(*it)->get_name()<<"!"<<std::endl;
			}
		}
		++it;
	}
	if(!attacked) {
		std::cout<<"There was no one to attack!"<<std::endl;
	}
}
void Zuul::info(std::vector<std::string>& commands) {
	std::cout<<"Your health is "<<g_player->get_hp()<<" and you do "<< g_player->do_damage()<< " damage."<<std::endl;
}

void Zuul::talk(std::vector<std::string>& commands) {
	std::string input_name;
	bool first = true;
	for(unsigned int i = 1 ;i<commands.size();++i, first = false) {
		if(!first) {
			input_name.append(" ");
		}
		input_name.append(commands[i]);
	}
	bool talked = false;
	auto it = g_npc_vector.begin();
	while(it != g_npc_vector.end()) {
		Tile temp_tile = (*it)->get_current_tile();
		if(temp_tile == g_player->get_current_tile()){
			(*it)->talk(*g_player);
			next_turn = true;
			talked = true;
		}
		++it;
	}
	if(!talked) {
		std::cout<<"There was no one to talk to!"<<std::endl;
	}
}

void Zuul::quit(std::vector<std::string>& commands) {
	g_quit = true;
}
void Zuul::exec_command(void) {
	std::string input = g_input;

	g_commands = split(g_input,' ');
	if(g_commands.size()<1){
		print_input_error_msg();	
		return;
	}
	//debugg commands
	/*for(auto it = g_commands.begin();it !=g_commands.end();++it){
		std::cout<< (*it)<<std::endl;
	}*/

	//auto it = g_commad_map.find(g_commands[0]);
	Command value(g_commands[0]);
	auto it = g_command_vector.begin();
	auto last = g_command_vector.end();
	for ( ;it!=last; it++) if ( *(*it)==value ) break;

	if(it!=g_command_vector.end()) {
		//g_commands.erase(g_commands.begin());
		//std::cout << "exec command!";
		(*(*it)).execute(g_commands);
		//std::cout<<"debugg executed the command"<<std::endl;

		//std::cout << "finished exec command!";
		//(this->*it->second)(g_commands);
	} else {
		print_input_error_msg();
	}
}
void Zuul::print_end_msg(void) const {
	std::cout << "Thank you for playing World of Zuul!" << std::endl << std::endl;	
}

std::vector<std::string> Zuul::split(const std::string& strValue, char separator) {
	std::vector<std::string> vecstrResult;

	if(strValue.size()<1){
		return vecstrResult;
	}
	int startpos=0;
	int endpos=0;
	bool looking_for_text = true;
	auto it = strValue.begin();
	while(it != strValue.end()) {	
		if((*it) == separator){
			if (looking_for_text) {
				vecstrResult.push_back(strValue.substr(startpos, (endpos-startpos)));
				startpos = endpos;
				looking_for_text = false;
			}
			else {
				startpos++;
			}
		} else {
			if(!looking_for_text) {
				startpos = endpos;
			}
			looking_for_text = true;

		}
		++it;
		++endpos;
	}
	it = strValue.begin();	
	it += startpos;
	if((*it) != separator)
		vecstrResult.push_back(strValue.substr(startpos, endpos-startpos));
	return vecstrResult;
}

void Zuul::print_input_error_msg(void) const {
	std::cout <<'"'<< g_input <<'"' << ", was not a valid input!"<<std::endl;
}
void Zuul::npc_action(void) {
	auto it = g_npc_vector.begin();

	//std::cout<<"debugg looping over npc"<<std::endl;
	while(it != g_npc_vector.end()) {
		//debugg
		//std::cout<<"debugg "<<(*it)->get_name()<<std::endl;
		(*it)->action(*g_player);
		it++;
	}
}
bool Zuul::is_end_of_game(void) {
	if(!g_player->is_alive()){
		g_quit = true;
		std::cout<<"You have died! And lost the game!"<<std::endl;
		std::cout<<"Better luck next time."<<std::endl;
		return true;
	}
	//todo win scenario

	return false;
}
void Zuul::init_npc(void) {
	//paladin
	g_npc_vector.push_back(new Paladin("Paladin Dicander", 2900, map->get_cathedral()));
	//monsters
	//trolls
	g_npc_vector.push_back(new Troll("Troll Bert", 200, map->get_field()));
	g_npc_vector.push_back(new Troll("Troll Bill", 200, map->get_field()));
	g_npc_vector.push_back(new Troll("Troll Tom", 200, map->get_field()));
	g_npc_vector.push_back(new SwampTroll("Swamp Troll Torog", 800, map->get_swamp_troll_start()));

	g_npc_vector.push_back(new SkeletonKing("Skeleton King Baltatzis", 6000, map->get_skeleton_king_start()));
}