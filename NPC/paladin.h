#ifndef PALADIN_H_
#define PALADIN_H_

#include "npc.h"
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

class Paladin  : public NPC {
private:
	bool has_talked_to_player;

public:
	Paladin(std::string p_name, int p_hp, Tile* tile);
	~Paladin();
	virtual void walk(Player& player);
	virtual void talk(Player& player);
	virtual unsigned int do_attack(void) const;
	virtual void action(Player& player);
	virtual bool get_damage(int);
	virtual bool get_attacked(Player& player);
};

#endif /* PALADIN_H_ */