#ifndef PALADIN_H_
#define PALADIN_H_

#include "npc.h"
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

class Paladin  : public NPC {
private:

public:
	Paladin(std::string p_name, int p_hp, Tile* tile);
	~Paladin();
	virtual void walk(void);
	virtual unsigned int do_attack(void) const;
	virtual void action(const Player& player);
	virtual void get_damage(int);
};

#endif /* PALADIN_H_ */