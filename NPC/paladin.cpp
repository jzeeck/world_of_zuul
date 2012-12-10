#include "paladin.h"


Paladin::Paladin(std::string p_name, int p_hp, Tile* tile) : NPC(p_name, p_hp, tile) {
	hp = p_hp;
	faction = PALADIN_FACTION;
	has_talked_to_player = false;
	//TODO equip paladin with gear that he drops
}

void Paladin::walk(Player& player) {
	std::string directions;
	current_tile->get_valid_directions(directions);
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
		std::cout << "New paladin tile, index was " <<next_tile->get_number()<< std::endl;
	#endif
	current_tile = next_tile;
}

void Paladin::action(Player& player) {
	if(!(player.get_current_tile()==(*current_tile))) {
		walk(player);
	}
}
void Paladin::talk(Player& player) {
	
	if(!has_talked_to_player) {
		std::cout << "You talked to " <<get_name()<<"."<< std::endl;
		std::cout << "He gave you a sword to defeat the Skeleton King!"<< std::endl;
		player.talked_to_paladin();
		has_talked_to_player = true;
	} else {
		std::cout << get_name()<<" has nothing more to say to you."<< std::endl;
	}
	//TODO
}

unsigned int Paladin::do_attack(void) const{
	if(!has_talked_to_player)
		return 10000000;
	return 300;
}
bool Paladin::get_attacked(Player& player) {
	get_damage(player.do_damage());
	if(is_dead())
		return is_dead();
	player.get_damage(do_attack());
	return false;

}

bool Paladin::get_damage(int dmg) {
	hp -= dmg;
	return is_dead();
	//TODO
} 