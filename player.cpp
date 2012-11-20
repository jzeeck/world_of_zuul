#include "player.h"
Player::Player(){
	
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