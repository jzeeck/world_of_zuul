#include "tile.h"

std::map<std::string, Tile* (Tile::*)() const> Tile::directions;

static const std::vector<std::string> string_direction = {"west","east","south","north"};
const std::vector<std::string> Tile::string_type = {};

Tile::Tile() {
	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;

	l_isExplored = false;
	tile_type = FIELD;

	init_directions();
}
Tile::Tile(int index) :north(NULL),south(NULL),west(NULL),east(NULL),l_isExplored(false){


	tile_type = FIELD;
	number = index;

	init_directions();
}
void Tile::init_directions() {
	directions.insert(std::pair<std::string, Tile* (Tile::*)() const>("west", &Tile::get_west));
	directions.insert(std::pair<std::string, Tile* (Tile::*)() const>("east", &Tile::get_east));
	directions.insert(std::pair<std::string, Tile* (Tile::*)() const>("south", &Tile::get_south));
	directions.insert(std::pair<std::string, Tile* (Tile::*)() const>("north", &Tile::get_north));
}

std::string Tile::get_valid_directions(void) const{
	std::string return_string = "";
	auto it = string_direction.begin();
	while(it != string_direction.end()) {
		auto it2 = directions.find(*it);
		if(it2 != directions.end()) {
			Tile * tile_ptr = (this->*((*it2).second))();
			if(NULL != tile_ptr){
				return_string.append(*it).append(" ");
			}
		}
		++it;
	}
	return return_string;
}

//setters
void Tile::explore() {
	#ifdef DEBUGG
	if(!l_isExplored)
		std::cout<<"Explored a new tile"<<std::endl;	
	std::cout<<"Tile had index "<<number<<std::endl;
	#endif

	l_isExplored = true;

}

Tile* Tile::get_direction(std::string dir) const {
	auto it = directions.find(dir);
	if(it != directions.end())
		//(obj->*func_ptr)(v);
		return (this->*((*it).second))();
	return NULL;
}

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