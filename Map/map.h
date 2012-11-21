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
	Dungeon* dungeon;//[DUNGEON_SQUARES];
	Cathedral* cathedral;//[CATHEDRAL_SQUARES];
	Tile* field;//[MAP_DIMENSION*MAP_DIMENSION];

	void init_field(void);
	void init_dungeon(void);
	void init_cathedral(void);
	void link_map_together(void);
public:
	Map();
	~Map();

	void print(void);
};


#endif /* MAP_H_ */