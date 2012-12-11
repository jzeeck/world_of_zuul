#include "swamp_troll.h"


SwampTroll::SwampTroll(std::string p_name, int p_hp, Tile* tile) : Troll(p_name, p_hp, tile) {
	hp = p_hp;
	faction = SWAMP_FACTION;
	//TODO equip troll with gear that he drops
}

void SwampTroll::walk(Player& player) {
	//we are at the player!
	if((*current_tile) == player.get_current_tile()) {
		#ifdef DEBUGG
				std::cout << "standing on the same tile as player"<< std::endl;
		#endif
		return;
	}
	std::string directions;
	current_tile->get_valid_directions(directions);
	std::cout << "got direction: "<<directions<< std::endl;
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
		if(!neighbour_tile->is_swamp()){
			//std::cout << "erasing tile in direction "<<*it<< std::endl;
			dir_vector.erase(it);
			//std::cout << "done"<< std::endl;
		} else {
			++it;
		}
		//std::cout << "++it"<< std::endl;
	}
	//std::cout << "pick next direction"<< std::endl;
	if(direction.size()==0)
		return;

	//look for player
	it = dir_vector.begin();
	while(it != dir_vector.end()) {
		Tile * next_tile  = current_tile->get_direction(*it);
		//std::cout << "checking tile for player " <<next_tile->get_number()<<*it<< std::endl;
		if ((*next_tile) == player.get_current_tile()) {
			current_tile = next_tile;
			#ifdef DEBUGG
				std::cout << "picked next tile because player was there"<< std::endl;
			#endif
			return;
		}
		++it;
	}


	int index = rand() % dir_vector.size();
	direction = dir_vector[index];
	Tile * next_tile  = current_tile->get_direction(direction);
	#ifdef DEBUGG
		std::cout << "New swamp troll tile, index was " <<next_tile->get_number()<< std::endl;
	#endif
	current_tile = next_tile;
}

void SwampTroll::action(Player& player) {
	//debugg
	//std::cout << "went into troll action"<< std::endl;
	if(!(player.get_current_tile()==(*current_tile))) {
		walk(player);
	} else {
		player.get_damage(do_attack());
		std::cout <<get_name()<<" hit you! You lost " <<do_attack()<<" life."<< std::endl;
	}
}
void SwampTroll::talk(Player& player) {
	std::cout << "You tried talked to " <<get_name()<<"."<< std::endl;
	std::cout << "Yarl me SMASH you puny human!"<< std::endl;
}

unsigned int SwampTroll::do_attack(void) const {
	return 100;
}