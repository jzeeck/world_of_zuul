#ifndef NPC_H_
#define NPC_H_

#include <vector>
#include <string>
#include "../Items/item.h"
#include "../Map/Tiles/tile.h"

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
	virtual unsigned int do_attack(void);
	virtual void get_damage(int);
};

#endif /* NPC_H_ */