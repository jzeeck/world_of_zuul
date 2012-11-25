#include "graveyard.h"

Graveyard::Graveyard() :Tile() {
	tile_type = GRAVEYARD;
}

Graveyard::Graveyard(int index) :Tile(index) {
	tile_type = GRAVEYARD;
}

Graveyard::~Graveyard() {}