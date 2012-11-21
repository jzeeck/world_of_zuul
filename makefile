CC = g++
CFLAGS = -std=c++0x -Wall -DDEBUGG


all: compile


compile: commands player map
	$(CC) $(CFLAGS) map.o  npc.o commands.o graveyard.o dungeon.o swamp.o cathedral.o Commands/game_command.h item.o player.o tiles.o zuul.cpp main.cpp -o zuul

run:
	./zuul

commands:
	$(CC) $(CFLAGS) -c Commands/command.cpp -o commands.o




player: item
	$(CC) $(CFLAGS) -c player.cpp -o player.o

item: Items/item.cpp Items/item.h
	$(CC) $(CFLAGS) -c Items/item.cpp -o item.o





map: tiles
	$(CC) $(CFLAGS) -Wall -c Map/map.cpp -o map.o

tiles: cathedral graveyard dungeon swamp npc
	$(CC) Map/Tiles/tile.cpp $(CFLAGS) -o tiles.o -c

cathedral: cathedral
	$(CC) Map/Tiles/cathedral.cpp $(CFLAGS) -o cathedral.o -c

graveyard: graveyard
	$(CC) -Wall Map/Tiles/graveyard.cpp $(CFLAGS) -o graveyard.o -c

dungeon: dungeon
	$(CC) -Wall Map/Tiles/dungeon.cpp $(CFLAGS) -o dungeon.o -c

swamp: swamp
	$(CC) Map/Tiles/swamp.cpp $(CFLAGS) -o swamp.o -c



npc:
	$(CC) NPC/npc.cpp $(CFLAGS) -o npc.o -c
