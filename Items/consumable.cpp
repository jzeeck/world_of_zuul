#include "consumable.h"

// Constructors
Consumable::Consumable(const std::string name){
	set_name(name);
	set_type("CONSUMABLE");
}

Consumable::Consumable(const std::string name, const std::string consumable_effect, const int grade){
	set_name(name);
	set_consumable_effect(consumable_effect);
	set_consumable_grade(grade);
	set_type("CONSUMABLE");
}

// functions
std::string Consumable::get_consumable_effect(void) const{
	return consumable_effect;
}
void Consumable::set_consumable_effect(const std::string effect){
	consumable_effect = effect;
}
int Consumable::get_consumable_grade(void) const{
	return consumable_grade;
}
void Consumable::set_consumable_grade(const int grade){
	consumable_grade = grade;
}