#ifndef NPC_H_
#define NPC_H_

#include <vector>
#include <string>
#include "../Items/item.h"
#include "../player.h"
#include "../Map/Tiles/tile.h"

#define PALADIN_FACTION 0

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
	virtual void walk(void);
	virtual void action(const Player& player);
	virtual unsigned int do_attack(void) const;
	virtual void get_damage(int);
	Tile& get_current_tile(void) const;
	std::string get_name(void) const;
};

#endif /* NPC_H_ */