#include "player.h"
Player::Player(){
	
}
Player::Player(Tile* tile) {
	current_tile = tile;
	l_hp = 4000;
	has_talked_to_paladin = false;
	#ifdef DEBUGG
		std::cout<<"Created Player with a starting tile!"<<std::endl;
	#endif
	tile->explore();
}

Player::~Player(){
	/*delete l_head_gear;
	delete l_wepond;
	delete l_shield;
	delete l_chest;
	delete l_gloves;
	delete l_boots;*/
}

void Player::set_name(std::string var) {
	l_name = var;
}
/*int Player::get_max_number_of_items(){
	return Player::max_number_of_items;
}*/
bool Player::move(std::string dir) {
	Tile * next_tile = current_tile->get_direction(dir);
	if(NULL == next_tile)
		return false;
	current_tile = next_tile;
	current_tile->explore();
	return true;
}

Tile& Player::get_current_tile(void) const{
	return *current_tile;
}
bool Player::is_alive(void) const {
	if(l_hp<=0) {
		return false;
	}
	return true;
}

bool Player::get_damage(unsigned int dmg) {
	l_hp -=dmg;
	return is_alive();
}

unsigned int Player::do_damage(void) {
	if (!has_talked_to_paladin)
		return 300;
	else {
		return 5000;
	}
}

void Player::talked_to_paladin(void) {
	has_talked_to_paladin = true;
}

int Player::get_hp(void) {
	return l_hp;
}