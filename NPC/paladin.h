#ifndef PALADIN_H_
#define PALADIN_H_

#include "npc.h"
class Paladin  : public NPC {
private:

public:
	Paladin(std::string p_name, int p_hp, Tile* tile);
	~Paladin();
	virtual void walk(void);
	virtual unsigned int do_attack(void);
	virtual void get_damage(int);
};


};
#endif /* PALADIN_H_ */