#include "swamp.h"

Swamp::Swamp() : Tile(){
	tile_type = SWAMP;
}
Swamp::Swamp(int index) : Tile(index){
	tile_type = SWAMP;
}
Swamp::~Swamp() {}