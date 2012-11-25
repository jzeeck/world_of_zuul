#ifndef TILE_H_
#define TILE_H_
#include <cstddef>
#include <vector>
#include "../../NPC/npc.h"
#include <iostream>
#include <map>
#include <utility>

#define FIELD 0
#define SWAMP 1
#define GRAVEYARD 2
#define CATHEDRAL 3
#define DUNGEON 4

class Tile {
private:
	Tile* north;
	Tile* south;
	Tile* west;
	Tile* east;

	bool l_isExplored;

	std::vector<NPC> npc;
	static std::map<std::string, Tile* (Tile::*)() const> directions;
	static const std::vector<std::string> string_type;
	void init_directions(void);
protected:
	int tile_type;
	int number;
public:
	Tile();
	Tile(int);
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
	Tile* get_direction(std::string) const;
	std::string get_valid_directions(void) const;
	bool isExplored(void) const;
	void explore(void);
	//print
	friend std::ostream& operator<<(std::ostream& stream, const Tile& tile);
};

#endif /* TILE_H_ */