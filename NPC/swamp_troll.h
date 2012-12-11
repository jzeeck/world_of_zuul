#ifndef SWAMPTROLL_H_
#define SWAMPTROLL_H_

#include "troll.h"
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

class SwampTroll  : public Troll {
private:

public:
	SwampTroll(std::string p_name, int p_hp, Tile* tile);
	~SwampTroll();
	virtual void walk(Player& player);
	virtual void talk(Player& player);
	virtual unsigned int do_attack(void) const;
	virtual void action(Player& player);
};

#endif /* SWAMPTROLL_H_ */