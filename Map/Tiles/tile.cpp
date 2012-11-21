#include "tile.h"

Tile::Tile() {
	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;

	l_isExplored = false;
}
Tile::Tile(int index) {
	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;

	l_isExplored = false;

	number = index;
}
//setters
void Tile::set_north(Tile& t) {
	north = &t;
}

void Tile::set_south(Tile& t) {
	south = &t;
}

void Tile::set_west(Tile& t) {
	west = &t;
}

void Tile::set_east(Tile& t) {
	east = &t;
}
//getters
Tile* Tile::get_north(void) const{
	return north;
}

Tile* Tile::get_south(void) const{
	return south;
}

Tile* Tile::get_west(void) const{
	return west;
}

Tile* Tile::get_east(void) const{
	return east;
}
bool Tile::isExplored(void) const{
	return l_isExplored;
}
std::ostream& operator<<(std::ostream& stream, const Tile& tile) {

	if(!tile.isExplored()) {
		stream<<'X';
	}
	else {
		stream<<' ';
	}

	return stream;
}