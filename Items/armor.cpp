#include "armor.h"

// Constructors
// Armor::Armor(const std::string name){
// 	set_name(name);
// 	set_protection(0);
// 	set_type("ARMOR");
// }

Armor::Armor(const std::string name, const int protection, const std::string type_of_armor){
	set_name(name);
	set_protection(protection);
	set_type("ARMOR");
	set_armor_type(type_of_armor);
}


// functions
void Armor::set_protection(const int protection){
	armor_protection = protection;
}

int Armor::get_protection(void) const{
	return armor_protection;
}

void Armor::set_armor_type(const std::string type_of_armor){
	armor_type = type_of_armor;
}

std::string Armor::get_armor_type(void) const{
	return armor_type;
}


