#include "paladin.h"



Paladin::Paladin(std::string p_name, int p_hp, Tile* tile) {
	hp = p_hp;
	

}

void Paladin::walk(void) {
	
}

unsigned int Paladin::do_attack(void) {
	return 10000000;
}

void Paladin::get_damage(int dmg) {
	hp -= dmg;
} 