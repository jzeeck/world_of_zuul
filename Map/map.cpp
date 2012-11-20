#include "map.h"

#define MAP_DIMENSION 6
#define CATHEDRAL_SQUARES 4
#define DUNGEON_SQUARES 7

Map::Map() {
	dungeon = new Dungeon[DUNGEON_SQUARES];
	cathedral = new Cathedral[CATHEDRAL_SQUARES];
	field = new Tile[MAP_DIMENSION*MAP_DIMENSION];

	init_field();	
	init_dungeon();
	init_cathedral();
	link_map_together();
}
Map::~Map() {
	delete[] dungeon;
	delete[] cathedral;
	delete[] field;
}

void Map::init_field(void) {
	#ifdef DEBUGG
		std::cout<<"Init Field... "<<std::endl;
		bool inited_squares[MAP_DIMENSION*MAP_DIMENSION];
		for(int i = 0;i<MAP_DIMENSION*MAP_DIMENSION;++i) {
			inited_squares[i] = false;
		}
	#endif

	Tile* field_ptr = field;
	for(int i = 0;i<MAP_DIMENSION/2;++i) {
		for(int j = 0;j<MAP_DIMENSION/2;++j){
			int index = ((i*6)+j);
			#ifdef DEBUGG
				inited_squares[index] = true;
				std::cout<<"Init a Tile at index "<<index<<std::endl;
			#endif

			*(field_ptr+index) = Tile();
		}
	}

	for(int i = 0;i<MAP_DIMENSION/2;++i) {
		for(int j = 0;j<MAP_DIMENSION/2;++j){
			int index = ((i*6)+j+21);
			#ifdef DEBUGG
				inited_squares[index] = true;
				std::cout<<"Init a Tile at index "<<index<<std::endl;
			#endif

			*(field_ptr + index) = Tile();
		}
	}

	#ifdef DEBUGG
		std::cout<<"Init Swamp... "<<std::endl;
	#endif

	for(int i = 0;i<MAP_DIMENSION/2;++i) {
		for(int j = 0;j<MAP_DIMENSION/2;++j){
			int index = ((i*6)+j)+3;
			#ifdef DEBUGG
				inited_squares[index] = true;
				std::cout<<"Init a Tile at index "<<index<<std::endl;
			#endif

			*(field_ptr+index) = Swamp();
		}
	}
	#ifdef DEBUGG
		std::cout<<"Init Graveyard... "<<std::endl;
	#endif

	for(int i = 0;i<MAP_DIMENSION/2;++i) {
		for(int j = 0;j<MAP_DIMENSION/2;++j){
			int index = ((i*6)+j)+18;
			#ifdef DEBUGG
				inited_squares[index] = true;
				std::cout<<"Init a Tile at index "<<index<<std::endl;
			#endif

			*(field_ptr+index) = Graveyard();
		}
	}
	#ifdef DEBUGG
	bool all_done = true;
	for(int i = 0;i< MAP_DIMENSION*MAP_DIMENSION;++i) {
		if(!inited_squares[i]) {
			std::cout<<"Tile with index "<<i<< " was not initialized"<<std::endl;
			all_done = false;
		}
	}
	if(all_done)
		std::cout<<"Entire field inited!"<<std::endl;
	#endif
}
void Map::init_dungeon(void) {
	Dungeon* ptr = dungeon;
	for(int i = 0;i<DUNGEON_SQUARES;++i){
		(*(ptr+i)) = Dungeon();
	}

}
void Map::init_cathedral(void) {
	Cathedral* ptr = cathedral;
	for(int i = 0;i<CATHEDRAL_SQUARES;++i){
		(*(ptr+i)) = Cathedral();
	}
}
void Map::link_map_together() {

}
void Map::print(void) {

	Tile* tile_ptr = field;

	std::cout<<"Field:"<<std::endl;
	for(int i = 0;i<MAP_DIMENSION;++i){
		for(int j = 0;j<MAP_DIMENSION;++j){
			std::cout<<'|'<<*(tile_ptr+ (i*6)+j)<<'|';
		}
		std::cout<<std::endl;
	}
	
	Cathedral* cathedral_ptr = cathedral;

	std::cout<<"Cathedral:"<<std::endl;
	std::cout<<"   "<<'|'<<*(cathedral_ptr+1)<<'|'<<std::endl;
	std::cout<<'|'<<*(cathedral_ptr)<<'|'<<'|'<<*(cathedral_ptr+2)<<'|'<<std::endl;
	std::cout<<"   "<<'|'<<*(cathedral_ptr+3)<<'|'<<std::endl;

	Dungeon* dungeon_ptr = dungeon;

	std::cout<<"Dungeon:"<<std::endl;
	std::cout<<"   "<<"   "<<'|'<<*(dungeon_ptr+3)<<'|'<<std::endl;
	std::cout<<'|'<<*(dungeon_ptr)<<'|'<<'|'<<*(dungeon_ptr+1)<<'|'<<'|'<<*(dungeon_ptr+2)<<'|';
	std::cout<<'|'<<*(dungeon_ptr+4)<<'|'<<'|'<<*(dungeon_ptr+6)<<'|'<<std::endl;
	std::cout<<"   "<<"   "<<"   "<<'|'<<*(dungeon_ptr+5)<<'|'<<std::endl;

}