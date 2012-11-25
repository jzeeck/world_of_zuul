#include "player.h"
Player::Player(){
	init_start_items();
	init_start_attributes();
}

Player::Player(Tile* tile) {
	current_tile = tile;
	#ifdef DEBUGG
		std::cout<<"Created Player with a starting tile!"<<std::endl;
	#endif
	tile->explore();
	init_start_items();
	init_start_attributes();
}

Player::~Player(){
	delete l_head_gear;
	delete l_weapon;
	delete l_shield;
	delete l_chest;
	delete l_gloves;
	delete l_boots;
	// TODO inventoryt måste tas bort!
}

void Player::set_name(std::string var) {
	l_name = var;
}

unsigned int Player::get_max_number_of_items(){
	return Player::max_number_of_items;
}

bool Player::move(std::string dir) {
	Tile * next_tile = current_tile->get_direction(dir);
	if(NULL == next_tile)
		return false;
	current_tile = next_tile;
	current_tile->explore();
	return true;
}

Tile * Player::get_current_tile() const{
	return current_tile;
}

Item * Player::get_inventory_at(unsigned int position){
	if(position >= get_max_number_of_items()){
		return NULL;
	}
	return l_inventory[position];
}

void Player::delete_inventory_at(unsigned int position){
	delete l_inventory[position];
}


// TODO Inte helt säker på att den här gör rätt, bör pekarna sättas till NULL eller
// deleteas?
void Player::unequip_item(std::string type){
	int freespot = max_number_of_items;
	for(unsigned int index = 0; index < max_number_of_items; index++){
		if(l_inventory[index] == NULL){
			freespot = index;
			break;
		}
	}
	if (type.compare("ARMOR_CHEST") == 0){
		l_inventory[freespot] = l_chest;
		l_chest = NULL;
	}else if (type.compare("ARMOR_SHIELD") == 0){
		l_inventory[freespot] = l_shield;
		l_shield = NULL;
	}else if (type.compare("ARMOR_BOOTS") == 0){
		l_inventory[freespot] = l_boots;
		l_boots = NULL;
	}else if(type.compare("ARMOR_GLOVES") == 0){
		l_inventory[freespot] = l_gloves;
		l_gloves = NULL;
	}else if(type.compare("ARMOR_HEAD_GEAR") == 0){
		l_inventory[freespot] = l_head_gear;
		l_head_gear = NULL;
	} else if(type.compare("WEAPON") == 0){
		l_inventory[freespot] = l_weapon;
		l_weapon = NULL;
	}
}

int Player::get_damage(){
	return get_strength() + l_weapon->get_damage();
}

int Player::get_defense(){
	int from_armor = l_chest->get_protection();
	from_armor += l_head_gear->get_protection();
	from_armor += l_boots->get_protection();
	from_armor += l_gloves->get_protection();
	from_armor += l_shield->get_protection();
	return get_vitality() + from_armor;
}

void Player::equip_weapon(Weapon * weapon){
	l_weapon = weapon;
}

void Player::equip_armor(Armor * armor){
	std::string type = (*armor).get_type();
	if (type.compare("ARMOR_CHEST") == 0){
		l_chest = armor;
	}else if (type.compare("ARMOR_SHIELD") == 0){
		l_shield = armor;
	}else if (type.compare("ARMOR_BOOTS") == 0){
		l_boots = armor;
	}else if(type.compare("ARMOR_GLOVES") == 0){
		l_gloves = armor;
	}else if(type.compare("ARMOR_HEAD_GEAR") == 0){
		l_head_gear = armor;
	}
}

void Player::use_consumable(Consumable * consumable){
	std::string type = consumable->get_type();
	if(type.compare("CONSUMABLE_HP")){
		l_hp += consumable->get_consumable_grade();
	}else if(type.compare("COMSUMABLE_STRENGTH")){
		l_strength += consumable->get_consumable_grade();
	}else if(type.compare("COMSUMABLE_DEXTERITY")){
		l_dexterity += consumable->get_consumable_grade();
	}else if(type.compare("COMSUMABLE_VITALITY")){
		l_vitality += consumable->get_consumable_grade();
	}
}

void Player::init_start_items(){
	Weapon * weapon = new Weapon("Ugly Sword",10,false);
	Armor * headgear = new Armor("Ugly headgear",3,"ARMOR_HEAD_GEAR");
	Armor * chestplate = new Armor("Ugly chestplate",10,"ARMOR_CHEST");
	Armor * boots = new Armor("Ugly boots",3,"ARMOR_BOOTS");
	Armor * shield = new Armor("Ugly shield",5,"ARMOR_SHIELD");
	Armor * gloves = new Armor("Ugly gloves",3,"ARMOR_GLOVES");
	Consumable * potion = new Consumable("Small health potion","CONSUMABLE_HP",20);

	l_inventory[0] = potion;	
	l_weapon = weapon;
	l_head_gear = headgear;
	l_chest = chestplate;
	l_boots = boots;
	l_shield = shield;
	l_gloves = gloves;
}

// Functions for player attributes
int Player::get_strength(void){
	return l_strength;
}
int Player::get_dexterity(void){
	return l_dexterity;
}
int Player::get_vitality(void){
	return l_vitality;
}
int Player::get_hp(void){
	return l_hp;
}
int Player::get_exp(void){
	return l_experience;
}

void Player::set_strenght(int strenght){
	l_strength = strenght;
}
void Player::set_dexterity(int dexterity){
	l_dexterity = dexterity;
}
void Player::set_vitality(int vitality){
	l_vitality = vitality;
}
void Player::set_hp(int hp){
	l_hp = hp;
}
void Player::set_exp(int exp){
	l_experience = exp;
}


void Player::init_start_attributes(void){
	set_strenght(10);
	set_vitality(10);
	set_dexterity(10);
	set_exp(0);
	set_hp(100);
}

void Player::level_up(void){
	std::cout << "Level up!" << std::endl;
	set_hp(get_hp() + get_vitality());
	// TODO Kanske ska få öka valfri attribute?
}