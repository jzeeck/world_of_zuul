#include "player.h"
Player::Player(){
	
}
Player::Player(Tile* tile) {
	current_tile = tile;
	#ifdef DEBUGG
		std::cout<<"Created Player with a starting tile!"<<std::endl;
	#endif
	tile->explore();
}

Player::~Player(){
	delete l_head_gear;
	delete l_wepond;
	delete l_shield;
	delete l_chest;
	delete l_gloves;
	delete l_boots;
}

void Player::set_name(std::string var) {
	l_name = var;
}
int Player::get_max_number_of_items(){
	return Player::max_number_of_items;
}
bool Player::move(std::string dir) {
	Tile * next_tile = current_tile->get_direction(dir);
	if(NULL == next_tile)
		return false;
	current_tile = next_tile;
	current_tile->explore();
}