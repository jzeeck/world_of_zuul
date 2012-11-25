#include "dungeon.h"

Dungeon::Dungeon():Graveyard(){
	tile_type = DUNGEON;
}
Dungeon::Dungeon(int i):Graveyard(i){
	tile_type = DUNGEON;
}
Dungeon::~Dungeon(){}