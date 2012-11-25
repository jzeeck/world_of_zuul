#include "cathedral.h"
Cathedral::Cathedral() :Tile(){
	tile_type = CATHEDRAL;
}
Cathedral::Cathedral(int i) : Tile(i){
	tile_type = CATHEDRAL;
}

Cathedral::~Cathedral() {}