#include "weapon.h"


// Weapon::Weapon(const std::string name){
// 	set_name(name);
// 	set_type("WEAPON");
// }

Weapon::Weapon(const std::string name, const int damage){
	set_name(name);
	set_damage(damage);
	set_type("WEAPON");
}


// functions
int Weapon::get_damage(void) const{
	return weapon_damage;
}
void Weapon::set_damage(const int damage){
	weapon_damage = damage;
}