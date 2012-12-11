#ifndef SKELETON_H_
#define SKELETON_H_

#include "npc.h"

class Skeleton : public NPC {
private:

public:
	Skeleton(std::string p_name, int p_hp, Tile* tile);
	~Skeleton();
	virtual void walk(Player& player);
	virtual void talk(Player& player);
	virtual unsigned int do_attack(void) const;
	virtual void action(Player& player);
	virtual bool is_skeleton_king() const;
};

#endif /* SKELETON_H_ */