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

void NPC::walk(Player& player) {

}
void NPC::action(Player& player) {

}

void NPC::talk(Player& player) {

}

bool NPC::get_attacked(Player& player) {
	return get_damage(player.do_damage());
}

unsigned int NPC::do_attack(void) const{
	return 1;
}

bool NPC::get_damage(int dmg) {
	hp -= dmg;
	return is_dead();
}
Tile& NPC::get_current_tile(void) const {
	return *current_tile;
}
std::string NPC::get_name(void) const {
	return name;
}