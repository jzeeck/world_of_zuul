#include "troll.h"


Troll::Troll(std::string p_name, int p_hp, Tile* tile) : NPC(p_name, p_hp, tile) {
	hp = p_hp;
	faction = SWAMP_FACTION;
	//TODO equip troll with gear that he drops
}

void Troll::walk(Player& player) {
	std::string directions;
	current_tile->get_valid_directions(directions);
	//std::cout << "got direction"<< std::endl;
	std::istringstream iss(directions);
	//std::cout << "starting split"<< std::endl;

	std::vector<std::string> dir_vector;

	std::string direction;

	while(iss >> direction)	{
		dir_vector.push_back(direction);
	}
	//std::cout << "done split"<< std::endl;
	auto it = dir_vector.begin();

	while(it != dir_vector.end()) {
		//std::cout << "next tile "<<*it<< std::endl;
		Tile * neighbour_tile = current_tile->get_direction(*it);
		//std::cout << "verifying tile in direction "<<*it<< std::endl;
		if(!neighbour_tile->is_field()){
			//std::cout << "erasing tile in direction "<<*it<< std::endl;
			dir_vector.erase(it);
			--it;
			//std::cout << "done"<< std::endl;
		}
		++it;
		//std::cout << "++it"<< std::endl;
	}
	//std::cout << "pick next direction"<< std::endl;
	if(direction.size()==0)
		return;

	int index = rand() % dir_vector.size();
	direction = dir_vector[index];
	Tile * next_tile  = current_tile->get_direction(direction);
	#ifdef DEBUGG
		std::cout << "New troll tile, index was " <<next_tile->get_number()<< std::endl;
	#endif
	current_tile = next_tile;
}

void Troll::action(Player& player) {
	//debugg
	//std::cout << "went into troll action"<< std::endl;
	if(!(player.get_current_tile()==(*current_tile))) {
		walk(player);
	} else {
		player.get_damage(do_attack());
		std::cout <<get_name()<<" hit you! You lost " <<do_attack()<<" life."<< std::endl;
	}
}
void Troll::talk(Player& player) {
	std::cout << "You tried talked to " <<get_name()<<"."<< std::endl;
	std::cout << "Yarl me SMASH!"<< std::endl;
}

unsigned int Troll::do_attack(void) const {
	return 20;
}