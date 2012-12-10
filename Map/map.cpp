#include "map.h"

#define MAP_DIMENSION 6
#define CATHEDRAL_SQUARES 4
#define DUNGEON_SQUARES 7

Map::Map() : dungeon(new Dungeon[DUNGEON_SQUARES]), cathedral(new Cathedral[CATHEDRAL_SQUARES]), field(new Tile[MAP_DIMENSION*MAP_DIMENSION]){
	dungeon_is_unlocked = false;
	init_field();	
	link_field();
	init_dungeon();
	link_dungeon();
	init_cathedral();
	link_cathedral();
	link_map_together();
}
Map::~Map() {
	delete[] dungeon;
	delete[] cathedral;
	delete[] field;
}
Tile* Map::get_starting_position(void) const {
	return field+(MAP_DIMENSION*MAP_DIMENSION)-1;
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

			*(field_ptr+index) = Tile(index);
		}
	}

	for(int i = 0;i<MAP_DIMENSION/2;++i) {
		for(int j = 0;j<MAP_DIMENSION/2;++j){
			int index = ((i*6)+j+21);
			#ifdef DEBUGG
				inited_squares[index] = true;
				std::cout<<"Init a Tile at index "<<index<<std::endl;
			#endif

			*(field_ptr + index) = Tile(index);
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

			*(field_ptr+index) = Swamp(index);
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

			*(field_ptr+index) = Graveyard(index);
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

void Map::link_field(void) {
	Tile* tile_ptr = field;

	//link the middle field!
	for (int i = 0; i < MAP_DIMENSION-2; ++i)
	{
		for (int j = 0; j < MAP_DIMENSION-2; ++j)
		{
			(*(tile_ptr+j+7+(i*MAP_DIMENSION))).set_east((*(tile_ptr+j+8+(i*MAP_DIMENSION))));
			(*(tile_ptr+j+7+(i*MAP_DIMENSION))).set_west((*(tile_ptr+j+6+(i*MAP_DIMENSION))));
			(*(tile_ptr+j+7+(i*MAP_DIMENSION))).set_south((*(tile_ptr+j+7+(i*MAP_DIMENSION)+MAP_DIMENSION)));
			(*(tile_ptr+j+7+(i*MAP_DIMENSION))).set_north((*(tile_ptr+j+7+(i*MAP_DIMENSION)-MAP_DIMENSION)));
		}
	}
	for (int i = 1; i < MAP_DIMENSION-1; ++i)
	{
		//top
		(tile_ptr+i)->set_west(*(tile_ptr+i-1));
		(tile_ptr+i)->set_east(*(tile_ptr+i+1));
		(tile_ptr+i)->set_south(*(tile_ptr+i+MAP_DIMENSION));
		//bottom
		(tile_ptr+30+i)->set_west(*(tile_ptr+i+30-1));
		(tile_ptr+30+i)->set_east(*(tile_ptr+i+30+1));
		(tile_ptr+30+i)->set_north(*(tile_ptr+i-MAP_DIMENSION+30));
	}
	for (int i = 1; i < MAP_DIMENSION-1; ++i)
	{
		//left side
		(tile_ptr+(i*MAP_DIMENSION))->set_east(*(tile_ptr+(i*MAP_DIMENSION)+1));
		(tile_ptr+(i*MAP_DIMENSION))->set_north(*(tile_ptr+(i*MAP_DIMENSION)-MAP_DIMENSION));
		(tile_ptr+(i*MAP_DIMENSION))->set_south(*(tile_ptr+(i*MAP_DIMENSION)+MAP_DIMENSION));
		//right side

		(tile_ptr+5+(i*MAP_DIMENSION))->set_west(*(tile_ptr+5+(i*MAP_DIMENSION)-1));
		(tile_ptr+5+(i*MAP_DIMENSION))->set_north(*(tile_ptr+5+(i*MAP_DIMENSION)-MAP_DIMENSION));
		(tile_ptr+5+(i*MAP_DIMENSION))->set_south(*(tile_ptr+5+(i*MAP_DIMENSION)+MAP_DIMENSION));
	}
	//fix corners
	//top left
	tile_ptr->set_east(*(tile_ptr+1));
	tile_ptr->set_south(*(tile_ptr+MAP_DIMENSION));

	//top rigth
	tile_ptr = tile_ptr+MAP_DIMENSION-1;
	(tile_ptr)->set_west(*(tile_ptr-1));
	(tile_ptr)->set_south(*(tile_ptr+(MAP_DIMENSION)));

	//bottom right
	tile_ptr = field;
	tile_ptr = tile_ptr+(MAP_DIMENSION*MAP_DIMENSION)-1;
	(tile_ptr)->set_west(*(tile_ptr-1));
	(tile_ptr)->set_north(*(tile_ptr-(MAP_DIMENSION)));

	//bottom left
	tile_ptr = tile_ptr-MAP_DIMENSION+1;	
	tile_ptr->set_east(*(tile_ptr+1));
	(tile_ptr)->set_north(*(tile_ptr-(MAP_DIMENSION)));


}

void Map::init_dungeon(void) {
	Tile* ptr = dungeon;
	for(int i = 0;i<DUNGEON_SQUARES;++i){
		(*(ptr+i)) = Dungeon(i);
	}

}

void Map::link_dungeon(void) {
	Tile* ptr = dungeon;
	ptr->set_east(*(ptr+1));
	(ptr+1)->set_east(*(ptr+2));
	(ptr+2)->set_east(*(ptr+4));
	(ptr+4)->set_east(*(ptr+6));


	(ptr+2)->set_north(*(ptr+3));
	(ptr+5)->set_north(*(ptr+4));

	(ptr+3)->set_south(*(ptr+2));
	(ptr+4)->set_south(*(ptr+5));

	(ptr+5)->set_west(*(ptr+4));
	(ptr+4)->set_west(*(ptr+2));
	(ptr+2)->set_west(*(ptr+1));
	(ptr+1)->set_west(*(ptr+0));
}

void Map::init_cathedral(void) {
	Tile* ptr = cathedral;
	for(int i = 0;i<CATHEDRAL_SQUARES;++i){
		(*(ptr+i)) = Cathedral(i);
	}
}

void Map::link_cathedral(void) {
	Tile* ptr = cathedral;

	ptr->set_east(*(ptr+2));
	(ptr+2)->set_west(*(ptr));

	(ptr+1)->set_south(*(ptr+2));
	(ptr+2)->set_south(*(ptr+3));

	(ptr+3)->set_north(*(ptr+2));
	(ptr+2)->set_north(*(ptr+1));
}


void Map::link_map_together() {
	dungeon->set_south(*field);
	field->set_north(*dungeon);


	cathedral->set_west(*(field+17));
	(field+17)->set_east(*cathedral);
}

Tile* Map::get_dungeon() const{
	return dungeon;
}

Tile* Map::get_cathedral() const{
	return cathedral;
}

Tile* Map::get_field() const {
	return field;
}
Tile* Map::get_swamp_troll_start(void) const {
	return (field+4);
}
Tile* Map::get_skeleton_king_start(void) const {
	return (field+DUNGEON_SQUARES);
}

bool Map::is_dungeon_unlocked(void) {
	return dungeon_is_unlocked;
}

void Map::unlock_dungeon(void) {
	dungeon_is_unlocked = true;
}


std::ostream& operator<<(std::ostream& stream, const Map& map) {

	Tile* tile_ptr = map.get_field();

	std::cout<<"Field:"<<std::endl;
	for(int i = 0;i<MAP_DIMENSION;++i){
		for(int j = 0;j<MAP_DIMENSION;++j){
			std::cout<<'|'<<*(tile_ptr+(i*6)+j)<<'|';
		}
		std::cout<<std::endl;
	}
	
	Tile* cathedral_ptr = map.get_cathedral();

	std::cout<<"Cathedral:"<<std::endl;
	std::cout<<"   "<<'|'<<*(cathedral_ptr+1)<<'|'<<std::endl;
	std::cout<<'|'<<*(cathedral_ptr)<<'|'<<'|'<<*(cathedral_ptr+2)<<'|'<<std::endl;
	std::cout<<"   "<<'|'<<*(cathedral_ptr+3)<<'|'<<std::endl;

	Tile* dungeon_ptr = map.get_dungeon();

	std::cout<<"Dungeon:"<<std::endl;
	std::cout<<"   "<<"   "<<'|'<<*(dungeon_ptr+3)<<'|'<<std::endl;
	std::cout<<'|'<<*(dungeon_ptr)<<'|'<<'|'<<*(dungeon_ptr+1)<<'|'<<'|'<<*(dungeon_ptr+2)<<'|';
	std::cout<<'|'<<*(dungeon_ptr+4)<<'|'<<'|'<<*(dungeon_ptr+6)<<'|'<<std::endl;
	std::cout<<"   "<<"   "<<"   "<<'|'<<*(dungeon_ptr+5)<<'|'<<std::endl;

	return stream;

}

Tile* Map::find_tile(const Tile& tile) const {
	for(int i = 0;i<MAP_DIMENSION*MAP_DIMENSION;++i) {
			if((*(field + i))== tile);
				return field + i;
	}
	for(int i = 0;i<DUNGEON_SQUARES;++i) {
		if((*(dungeon + i)) == tile);
			return dungeon + i;
	}
	for(int i = 0;i<CATHEDRAL_SQUARES;++i) {
		if((*(cathedral + i)) == tile);
			return cathedral + i;
	}

	return NULL;
}