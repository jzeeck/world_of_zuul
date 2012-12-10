#include "paladin.h"


Paladin::Paladin(std::string p_name, int p_hp, Tile* tile) : NPC(p_name, p_hp, tile) {
	hp = p_hp;
	faction = PALADIN_FACTION;
	//TODO equip paladin with gear that he drops
}

void Paladin::walk(void) {
	std::string directions = current_tile->get_valid_directions();
	std::istringstream iss(directions);

	std::vector<std::string> dir_vector;

	std::string direction;

	while(iss >> direction)	{
		dir_vector.push_back(direction);
	}
	auto it = dir_vector.begin();

	while(it != dir_vector.end()) {
		Tile * neighbour_tile = current_tile->get_direction(*it);
		if(!neighbour_tile->is_cathedral()){
			dir_vector.erase(it);
		}
		++it;
	}

	int index = rand() % dir_vector.size();
	direction = dir_vector[index];
	Tile * next_tile  = current_tile->get_direction(direction);
	#ifdef DEBUGG
		std::cout << "New paladin tile index was " <<next_tile->get_number()<< std::endl;	
	#endif
	current_tile = next_tile;
}

void Paladin::action(const Player& player) {
	if(!(player.get_current_tile()==(*current_tile))) {
		walk();
	}
}

unsigned int Paladin::do_attack(void) const{
	return 10000000;
}

void Paladin::get_damage(int dmg) {
	hp -= dmg;
} 