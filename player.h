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
	Tile* current_tile;

	int l_hp;
	bool has_talked_to_paladin;

	Armor* l_head_gear;
	Weapon* l_weapon;
	Armor* l_shield;
	Armor* l_chest;
	Armor* l_gloves;
	Armor* l_boots;

	std::vector <Consumable *> l_consumables;
	void init_start_items(void);

public:
	void set_name(std::string var);
	Player();
	Player(Tile*);
	~Player();
	bool move(std::string);
	Tile& get_current_tile(void) const;
	bool is_alive(void) const;
	bool get_damage(unsigned int dmg);
	int get_hp(void);
	unsigned int do_damage(void);
	void talked_to_paladin(void);

	// functions for items
	void equip_weapon(Weapon * weapon);
	void equip_armor(Armor * armor);
	void use_consumable(unsigned int);

	void pickup_consumable(Consumable * consumable);
	void print_consumables();
	void print_equipped();

	int get_protection();

};

#endif /* PLAYER_H_ */