#include "map.h"

#define MAP_DIMENSION 6
#define CATHEDRAL_SQUARES 4
#define DUNGEON_SQUARES 7

Map::Map() {
	Tile* tile_ptr =  new Tile[MAP_DIMENSION*MAP_DIMENSION];
	Cathedral* c_tile_ptr =  new Cathedral[CATHEDRAL_SQUARES];
	Dungeon* d_tile_ptr =  new Dungeon[DUNGEON_SQUARES];

	dungeon = d_tile_ptr;
	cathedral = c_tile_ptr;
	field = tile_ptr;	
	init_field();	
	init_dungeon();
	init_cathedral();
}
Map::~Map() {
	delete[] dungeon;
	delete[] cathedral;
	delete[] field;
}

void Map::init_field(void) {

}
void Map::init_dungeon(void) {

}
void Map::init_cathedral(void) {

}