#include "armor.h"

// Constructors
Armor::Armor(const std::string name){
	set_name(name);
	set_protection(0);
	set_weight(0);
}

Armor::Armor(const std::string name, const int weight, const int protection, const std::string type){
	set_name(name);
	set_weight(weight);
	set_protection(protection);
	set_type(type);
}







// functions
void Armor::set_protection(const int protection){
	armor_protection = protection;
}

int Armor::get_protection() const{
	return armor_protection;
}

void Armor::set_type(const std::string type){
	armor_type = type;
}

std::string Armor::get_type() const{
	return armor_type;
}


