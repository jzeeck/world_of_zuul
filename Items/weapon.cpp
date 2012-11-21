#include "weapon.h"


Weapon::Weapon(const std::string name){
	set_name(name);
}
Weapon::Weapon(const std::string name, const int weight, const int damage, const bool two_handed){
	set_name(name);
	set_weight(weight);
	set_damage(damage);
	set_two_handed(two_handed);
}

// functions
int Weapon::get_damage(void) const{
	return weapon_damage;
}
void Weapon::set_damage(const int damage){
	weapon_damage = damage;
}
int Weapon::get_two_handed(void) const{
	return two_handed_weapon;
}
void Weapon::set_two_handed(const bool two_handed){
	two_handed_weapon = two_handed;
}