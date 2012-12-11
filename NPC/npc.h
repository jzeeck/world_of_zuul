#ifndef NPC_H_
#define NPC_H_

#include "../Items/item.h"
#include "../player.h"
#include "../Map/Tiles/tile.h"
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

#define PALADIN_FACTION 0
#define SWAMP_FACTION 1
#define UNDEAD_FACTION 2

class NPC {
protected:
	int faction;
	int hp;
	std::string name;
	std::vector<Item*> items;
	Tile* current_tile;

public:
	NPC(std::string p_name, int p_hp, Tile* tile);
	~NPC();
	bool is_dead(void);
	virtual void walk(Player& player);
	virtual void talk(Player& player);
	virtual void action(Player& player);
	virtual unsigned int do_attack(void) const;
	virtual bool get_damage(int);
	virtual bool get_attacked(Player& player);
	virtual bool is_skeleton_king() const;
	Tile& get_current_tile(void) const;
	std::string get_name(void) const;
};

#endif /* NPC_H_ */