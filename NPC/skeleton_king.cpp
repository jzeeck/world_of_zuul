#include "skeleton_king.h"

SkeletonKing::SkeletonKing(std::string p_name, int p_hp, Tile* tile) : Skeleton(p_name, p_hp, tile) {
	hp = p_hp;
	faction = UNDEAD_FACTION;
}

void SkeletonKing::walk(Player& player) {
	//If the king cant come to the player, the player has to come to the king!
}

void SkeletonKing::action(Player& player) {
	//debugg
	//std::cout << "went into skeleton king action"<< std::endl;
	if(!(player.get_current_tile()==(*current_tile))) {
		walk(player);
	} else {
		player.get_damage(do_attack());
		std::cout <<get_name()<<" hit you! You lost " <<do_attack()<<" life."<< std::endl;
	}
}
void SkeletonKing::talk(Player& player) {
	std::cout << "You tried talked to " <<get_name()<<"."<< std::endl;
	std::cout << "The Skeleton King makes a crackling laugh!"<< std::endl;
}

unsigned int SkeletonKing::do_attack(void) const {
	return 700;
}