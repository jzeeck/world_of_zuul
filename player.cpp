#include "player.h"
Player::Player(){
	// init_start_items();
}
Player::Player(Tile* tile) {
	current_tile = tile;
	l_hp = 4000;
	has_talked_to_paladin = false;
	#ifdef DEBUGG
		std::cout<<"Created Player with a starting tile!"<<std::endl;
	#endif
	tile->explore();
	init_start_items();
}

Player::~Player(){
	delete l_head_gear;
	delete l_weapon;
	delete l_shield;
	delete l_chest;
	delete l_gloves;
	delete l_boots;
	// for(unsigned int i = 0; i < l_consumables.size(); i++){
	// 	delete l_consumables[i];
	// }
	auto it = l_consumables.begin();
	while(it != l_consumables.end()){
		delete (*it);
		it++;
	}
	l_consumables.clear();
}



void Player::set_name(std::string var) {
	l_name = var;
}

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
	if(dmg - get_protection() > 0){
		l_hp -=(dmg - get_protection());
	}
	return is_alive();
}

unsigned int Player::do_damage(void) {
	return 300 + l_weapon ->get_damage();
	// if (!has_talked_to_paladin)
	// 	return 300;
	// else {
	// 	return 5000;
	// }
}

void Player::talked_to_paladin(void) {
	has_talked_to_paladin = true;
}

int Player::get_hp(void) {
	return l_hp;
}

int Player::get_protection(){
	int protection = 0;
	protection += l_head_gear->get_protection();
	protection += l_chest->get_protection();
	protection += l_boots->get_protection();
	protection += l_gloves->get_protection();
	protection += l_shield->get_protection();
	return protection;
}

void Player::equip_weapon(Weapon * weapon){
	delete l_weapon;
	l_weapon = weapon;
}

void Player::equip_armor(Armor * armor){
	std::string type = (*armor).get_type();
	if (type.compare("ARMOR_CHEST") == 0){
		delete l_chest;
		l_chest = armor;
	}else if (type.compare("ARMOR_SHIELD") == 0){
		delete l_shield;
		l_shield = armor;
	}else if (type.compare("ARMOR_BOOTS") == 0){
		delete l_boots;
		l_boots = armor;
	}else if(type.compare("ARMOR_GLOVES") == 0){
		delete l_gloves;
		l_gloves = armor;
	}else if(type.compare("ARMOR_HEAD_GEAR") == 0){
		delete l_head_gear;
		l_head_gear = armor;
	}
}

void Player::pickup_consumable(Consumable* consumable){
	l_consumables.push_back(consumable);
}

void Player::use_consumable(unsigned int index){
	if ( index < l_consumables.size()){
		auto it = l_consumables.begin();
		unsigned int iter = 0;
		while(it != l_consumables.end()){
			if(iter < index){
				it++;
				iter++; 
			}else{
				break;
			}
		}
		if(iter == index && it != l_consumables.end()){
			if( (*it)->get_type().compare("CONSUMABLE_HP")){
				std::cout << "You drank a: " << (*it)->get_name() << std::endl;
				l_hp += (*it)->get_consumable_grade();
				delete (*it);
				l_consumables.erase(it);
				return;
			}
		}	
	}
	std::cout << "You don't have a consumable with that number" << std::endl;

}



void Player::init_start_items(){
	Weapon * weapon = new Weapon("Ugly Sword",10);
	Armor * headgear = new Armor("Powerfull headgear of C++",30,"ARMOR_HEAD_GEAR");
	Armor * chestplate = new Armor("Powerfull chestplate of C++",100,"ARMOR_CHEST");
	Armor * boots = new Armor("Powerfull boots of C++",30,"ARMOR_BOOTS");
	Armor * shield = new Armor("Powerfull shield of C++",50,"ARMOR_SHIELD");
	Armor * gloves = new Armor("Powerfull gloves of C++",30,"ARMOR_GLOVES");
	Consumable * potion1 = new Consumable("Small health potion","CONSUMABLE_HP",2000);
	Consumable * potion2 = new Consumable("Small health potion","CONSUMABLE_HP",2000);

	pickup_consumable(potion1);
	pickup_consumable(potion2);

	l_weapon = weapon;
	l_head_gear = headgear;
	l_chest = chestplate;
	l_boots = boots;
	l_shield = shield;
	l_gloves = gloves;
}

void Player::print_consumables(){
	auto it = l_consumables.begin();
	int iter = 0;
	std::cout << "You have these consumables:" << std::endl;
	while(it != l_consumables.end()){
		std::cout << iter << ": " << (*it)->get_name() << std::endl;
		it++;
		iter++; 
	}
}	

void Player::print_equipped(){
	std::cout << "You have these items equipped:" << std::endl;
	std::cout << l_weapon->get_name() << ", damage: " << l_weapon->get_damage() << std::endl;
	std::cout << l_head_gear->get_name() << ", protection: " << l_head_gear->get_protection() << std::endl;
	std::cout << l_chest->get_name() << ", protection: " << l_chest->get_protection() << std::endl;
	std::cout << l_boots->get_name() << ", protection: " << l_boots->get_protection() << std::endl;
	std::cout << l_gloves->get_name() << ", protection: " << l_gloves->get_protection() << std::endl;
	std::cout << l_shield->get_name() << ", protection: " << l_shield->get_protection() << std::endl;
}