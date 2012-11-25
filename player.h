#ifndef PLAYER_H_
#define PLAYER_H_

#include "Items/item.h"
#include "Items/armor.h"
#include "Items/weapon.h"
#include "Items/consumable.h"

#include "Map/Tiles/tile.h"
#include <string>

class Player {
private:
	std::string l_name;
	const static unsigned int max_number_of_items = 8;

	Tile* current_tile;

	int l_strength;
	int l_dexterity;
	int l_vitality;

	int l_experience;
	int l_hp;

	Armor* l_head_gear;
	Weapon* l_weapon;
	Armor* l_shield;
	Armor* l_chest;
	Armor* l_gloves;
	Armor* l_boots;

	Item* l_inventory[max_number_of_items];
public:
	unsigned int get_max_number_of_items(void);
	void set_name(std::string var);
	Player();
	Player(Tile*);
	~Player();
	bool move(std::string);
	Tile * get_current_tile(void)const;


	//function for player items
	void equip_weapon(Weapon * weapon);
	void equip_armor(Armor * armor);
	void unequip_item(std::string type);
	void use_consumable(Consumable * consumable);
	Item * get_inventory_at(unsigned int);
	void delete_inventory_at(unsigned int);
	void init_start_items(void);
	
	// functions for player attributes
	int get_strength(void);
	int get_dexterity(void);
	int get_vitality(void);
	int get_hp(void);
	int get_exp(void);
	
	void set_strenght(int strength);
	void set_dexterity(int dexterity);
	void set_vitality(int vitality);
	void set_hp(int hp);
	void set_exp(int exp);


	void init_start_attributes(void);

	int get_damage(void);
	int get_defense(void);
	void level_up(void);
};

#endif /* PLAYER_H_ */