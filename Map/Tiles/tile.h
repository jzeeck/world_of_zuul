#ifndef TILE_H_
#define TILE_H_
#include <cstddef>
#include <vector>
#include "../../NPC/npc.h"
#include <iostream>

class Tile {
private:
	Tile* north;
	Tile* south;
	Tile* west;
	Tile* east;

	bool l_isExplored;

	std::vector<NPC> v;
public:
	Tile();
	//setters
	void set_north(Tile& t);
	void set_south(Tile& t);
	void set_west(Tile& t);
	void set_east(Tile& t);
	//getters
	Tile* get_north(void) const;
	Tile* get_south(void) const;
	Tile* get_west(void) const;
	Tile* get_east(void) const;
	bool isExplored(void) const;
	//print
	friend std::ostream& operator<<(std::ostream& stream, const Tile& tile);
};

#endif /* TILE_H_ */