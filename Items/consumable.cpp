#include "weapon.h"

// Constructors
Consumable::Consumable(std::string name){
	set_name(name);
}
Consumable::Consumable(std::string name, int weight, std::string consumable_effect, int grade){
	set_name(name);
	set_weight(weight);
	set_consumable_effect(consumable_effect);
	set_consumable_grade(grade);
}

// functions
std::string Consumable::get_consumable_effect(void){
	return consumable_effect;
}
void Consumable::set_consumable_effect(std::string effect){
	consumable_effect = effect;
}
int Consumable::get_consumable_grade(void){
	return consumable_grade;
}
void Consumable::set_consumable_grade(int grade){
	consumable_grade = grade;
}