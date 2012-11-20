#ifndef PLAYER_H_
#define PLAYER_H_

#include "Items/item.h"
#include <string>

class Player {
private:
	std::string l_name;
	const static unsigned int max_number_of_items = 8;

	int l_strength;
	int l_dexterity;
	int l_vitality;

	int l_experience;
	int l_hp;

	Item* l_head_gear;
	Item* l_wepond;
	Item* l_shield;
	Item* l_chest;
	Item* l_gloves;
	Item* l_boots;

	Item* l_inventory[8];
public:
	int get_max_number_of_items();
	void set_name(std::string var);
	Player();
	~Player();
};

#endif /* PLAYER_H_ */