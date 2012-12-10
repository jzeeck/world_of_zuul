#include "npc.h"

NPC::NPC(std::string p_name, int p_hp, Tile* tile) {
	name = p_name;
	hp = p_hp;
	current_tile = tile;
}
NPC::~NPC() {

}
bool NPC::is_dead(void) {
	if(hp<=0){
		return true;
	}
	return false;
}

void NPC::walk(void) {

}
void NPC::action(const Player& player) {
	
}

unsigned int NPC::do_attack(void) const{
	return 1;
}

void NPC::get_damage(int dmg) {
	hp -= dmg;
}
Tile& NPC::get_current_tile(void) const {
	return *current_tile;
}
std::string NPC::get_name(void) const {
	return name;
}