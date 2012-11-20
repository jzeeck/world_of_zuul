#ifndef MAP_H_
#define MAP_H_

#include "Tiles/tile.h"
#include "Tiles/cathedral.h"
#include "Tiles/graveyard.h"
#include "Tiles/dungeon.h"
#include "Tiles/swamp.h"

class Map {
private:
	Dungeon* dungeon;
	Cathedral* cathedral;
	Tile* field;
	void init_field(void);
	void init_dungeon(void);
	void init_cathedral(void);
public:
	Map();
	~Map();
};


#endif /* MAP_H_ */