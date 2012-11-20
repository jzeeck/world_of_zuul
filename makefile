all: compile


compile: commands player map
	g++ -std=c++0x -Wall commands.o Commands/game_command.h player.o map.o zuul.cpp main.cpp -o zuul

run:
	./zuul

commands:
	g++ -std=c++0x -Wall -c Commands/command.cpp -o commands.o




player: item
	g++ -std=c++0x -Wall -c item.o player.cpp -o player.o

item: Items/item.cpp Items/item.h
	g++ -std=c++0x -Wall -c Items/item.cpp -o item.o





map: tiles
	g++ -std=c++0x -Wall -c tiles.o Map/map.cpp -o map.o

tiles: cathedral graveyard dungeon swamp
	g++ cathedral.o graveyard.o dungeon.o swamp.o Map/Tiles/tile.cpp -std=c++0x -Wall -o tiles.o -c

cathedral: cathedral
	g++ Map/Tiles/cathedral.cpp -std=c++0x -Wall -o cathedral.o -c

graveyard: graveyard
	g++ -Wall Map/Tiles/graveyard.cpp -std=c++0x -Wall -o graveyard.o -c

dungeon: dungeon
	g++ -Wall Map/Tiles/dungeon.cpp -std=c++0x -Wall -o dungeon.o -c

swamp: swamp
	g++ Map/Tiles/swamp.cpp -std=c++0x -Wall -o swamp.o -c 
