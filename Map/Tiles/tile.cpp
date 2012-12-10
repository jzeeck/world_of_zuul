#include "tile.h"

std::map<std::string, Tile* (Tile::*)() const> Tile::directions;

static const std::vector<std::string> string_direction = {"west","east","south","north"};
const std::vector<std::string> Tile::string_type = {"field", "swamp", "graveyard", "cathedral", "dungeon"};

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

void Tile::get_valid_directions(std::string& ans) const{
	//std::cout<<"Tile index: "<<number<<std::endl;
	ans = "";
	auto it = string_direction.begin();
	while(it != string_direction.end()) {
		//std::cout<<"dir: "<<*it<<std::endl;
		auto it2 = directions.find(*it);
		if(it2 != directions.end()) {
			Tile * tile_ptr = (this->*((*it2).second))();
			if(NULL != tile_ptr){
				//std::cout<<"valid dir: "<<*it<<std::endl;
				ans.append(*it).append(" ");
			}
		}
		++it;
	}
	//std::cout<<"returning string: "<<ans<<std::endl;
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
bool Tile::is_field(void) const {
	if (tile_type <= GRAVEYARD)
		return true;
	return false;
}

bool Tile::is_swamp(void) const {
	if (tile_type == SWAMP)
		return true;
	return false;
}

bool Tile::is_graveyard(void) const {
	if (tile_type == GRAVEYARD)
		return true;
	return false;
}

bool Tile::is_cathedral(void) const {
	if (tile_type == CATHEDRAL)
		return true;
	return false;
}

bool Tile::is_dungeon(void) const {
	if (tile_type == DUNGEON)
		return true;
	return false;
}
int Tile::get_number(void) const {
	return number;
}
bool Tile::operator==(const Tile& tile) const {
	if(number == tile.number && tile_type == tile.tile_type) {
		return true;
	}
	return false;
}
