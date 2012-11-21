#include <iostream>
#include "zuul.h"
#include "Map/map.h"
#include "Commands/command.h"
#include "Commands/game_command.h"

//define used variables
#define MAX_BYTES 101


char g_input[MAX_BYTES];

bool Zuul::g_quit = false;
std::vector<std::string> Zuul::g_commands;
std::vector<Command*> Zuul::g_command_vector;
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

	map->print();

	while(!g_quit) {

		read_command();
		exec_command();
	}
	print_end_msg();
	return 1;
}
void Zuul::print_welcome_msg(void) const{
	std::cout << "Welcome to the World of Zuul!" << std::endl << std::endl;

}
void Zuul::get_adventurer_name(void) {
	std::cout << "Please enter the name of your adventurer!" << std::endl;
	std::cin.getline (g_input, MAX_BYTES);
	g_player = new Player();
	g_player->set_name(g_input);

}

void Zuul::print_help_msg(std::vector<std::string> commands){
	print_valid_commands();
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
	init_map();
	init_program_commands();
}
void Zuul::init_map(void) {
	map = new Map();
}
void Zuul::init_program_commands(void) {
	std::string s = "quit";
	//new GameCommand<void (Zuul::*)(std::vector<std::string> commands), Zuul*> command(s, &Zuul::quit, this);
	//g_command_vector.push_back(new (Zuul::*)(std::vector<std::string> commands), Zuul*> (s, &Zuul::quit, this));
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string> commands), Zuul*>(s, &Zuul::quit, this));
	s = "help";
	//g_command_vector.push_back(GameCommand<void (Zuul::*)(std::vector<std::string> commands)>(s, &Zuul::print_help_msg));
	g_command_vector.push_back(new GameCommand<void (Zuul::*)(std::vector<std::string> commands), Zuul*>(s, &Zuul::print_help_msg, this));
	
	/*g_commad_map.insert(std::pair<std::string, void (Zuul::*)(std::vector<std::string> commands)>("quit", &Zuul::quit));
	g_commad_map.insert(std::pair<std::string, 
		void (Zuul::*)(std::vector<std::string> commands)>("help", &Zuul::print_help_msg));*/
	
}
void Zuul::quit(std::vector<std::string> commands) {
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