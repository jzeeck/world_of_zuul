#ifndef MAP_H_
#define MAP_H_

#include "Tiles/tile.h"
#include "Tiles/cathedral.h"
#include "Tiles/graveyard.h"
#include "Tiles/dungeon.h"
#include "Tiles/swamp.h"
#include <iostream>


#define MAP_DIMENSION 6
#define CATHEDRAL_SQUARES 4
#define DUNGEON_SQUARES 7

class Map {
private:
	Dungeon* const dungeon;//;//[DUNGEON_SQUARES];
	Cathedral* const cathedral;//[CATHEDRAL_SQUARES];
	Tile* const field;//[MAP_DIMENSION*MAP_DIMENSION];
	bool dungeon_is_unlocked;

	void init_field(void);
	void link_field(void);
	void init_dungeon(void);
	void link_dungeon(void);
	void init_cathedral(void);
	void link_cathedral(void);
	void link_map_together(void);

public:
	Map();
	~Map();

	//getters
	Dungeon* get_dungeon(void) const;
	Cathedral* get_cathedral(void) const;
	Tile* get_field(void) const;

	Tile* get_starting_position(void) const;

	bool is_dungeon_unlocked(void);
	void unlock_dungeon(void);

	friend std::ostream& operator<<(std::ostream& stream, const Map& map);
};


#endif /* MAP_H_ */