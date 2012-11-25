CC = g++
CFLAGS = -std=c++0x -Wall -DDEBUGG


all: compile


compile: commands player map
	$(CC) $(CFLAGS) *.o  Commands/game_command.h zuul.cpp main.cpp -o zuul

run:
	./zuul

commands:
	$(CC) $(CFLAGS) -c Commands/command.cpp -o commands.o



testitems: item Items/testitems.cpp Items/testitems.h
	$(CC) $(CFLAGS) -c Items/testitems.cpp -o testitems


player: item
	$(CC) $(CFLAGS) -c player.cpp -o player.o

item: armor weapon consumable Items/item.cpp Items/item.h
	$(CC) $(CFLAGS) -c Items/item.cpp -o item.o

armor: Items/armor.cpp Items/armor.h
	$(CC) $(CFLAGS) -c Items/armor.cpp -o armor.o

weapon: Items/weapon.cpp Items/weapon.h
	$(CC) $(CFLAGS) -c Items/weapon.cpp -o weapon.o

consumable: Items/consumable.cpp Items/consumable.h
	$(CC) $(CFLAGS) -c Items/consumable.cpp -o consumable.o



map: tiles Map/map.cpp Map/map.h
	$(CC) $(CFLAGS) -c Map/map.cpp -o map.o

tiles: cathedral graveyard dungeon swamp npc Map/Tiles/tile.cpp Map/Tiles/tile.h
	$(CC) Map/Tiles/tile.cpp $(CFLAGS) -o tiles.o -c

cathedral: cathedral Map/Tiles/cathedral.cpp Map/Tiles/cathedral.h
	$(CC) Map/Tiles/cathedral.cpp $(CFLAGS) -o cathedral.o -c

graveyard: graveyard Map/Tiles/graveyard.cpp Map/Tiles/graveyard.h
	$(CC) Map/Tiles/graveyard.cpp $(CFLAGS) -o graveyard.o -c

dungeon: dungeon Map/Tiles/dungeon.cpp Map/Tiles/dungeon.h
	$(CC) Map/Tiles/dungeon.cpp $(CFLAGS) -o dungeon.o -c

swamp: swamp
	$(CC) Map/Tiles/swamp.cpp $(CFLAGS) -o swamp.o -c



npc:
	$(CC) NPC/npc.cpp $(CFLAGS) -o npc.o -c
