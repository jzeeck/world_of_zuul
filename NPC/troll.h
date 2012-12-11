#ifndef TROLL_H_
#define TROLL_H_

#include "npc.h"

class Troll  : public NPC {
private:

public:
	Troll(std::string p_name, int p_hp, Tile* tile);
	~Troll();
	virtual void walk(Player& player);
	virtual void talk(Player& player);
	virtual unsigned int do_attack(void) const;
	virtual void action(Player& player);
};

#endif /* TROLL_H_ */