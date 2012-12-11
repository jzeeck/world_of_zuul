CC = g++
CFLAGS = -std=c++0x -Wall 



all: compile


compile: commands player map npc
	$(CC) $(CFLAGS) *.o  Commands/game_command.h zuul.cpp main.cpp -o zuul

run: compile
	./zuul

commands:
	$(CC) $(CFLAGS) -c Commands/command.cpp -o commands.o

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

tiles: cathedral graveyard dungeon swamp Map/Tiles/tile.cpp Map/Tiles/tile.h
	$(CC) Map/Tiles/tile.cpp $(CFLAGS) -o tiles.o -c

cathedral: cathedral Map/Tiles/cathedral.cpp Map/Tiles/cathedral.h
	$(CC) Map/Tiles/cathedral.cpp $(CFLAGS) -o cathedral.o -c

graveyard: graveyard Map/Tiles/graveyard.cpp Map/Tiles/graveyard.h
	$(CC) Map/Tiles/graveyard.cpp $(CFLAGS) -o graveyard.o -c

dungeon: dungeon Map/Tiles/dungeon.cpp Map/Tiles/dungeon.h
	$(CC) Map/Tiles/dungeon.cpp $(CFLAGS) -o dungeon.o -c

swamp: swamp
	$(CC) Map/Tiles/swamp.cpp $(CFLAGS) -o swamp.o -c



npc: NPC/npc.cpp NPC/npc.h paladin troll swamptroll skeleton skeletonking
	$(CC) NPC/npc.cpp $(CFLAGS) -o npc.o -c

paladin: NPC/paladin.cpp NPC/paladin.h
	$(CC) NPC/paladin.cpp $(CFLAGS) -o paladin.o -c

troll: NPC/troll.cpp NPC/troll.h
	$(CC) NPC/troll.cpp $(CFLAGS) -o troll.o -c

swamptroll: NPC/swamp_troll.cpp NPC/swamp_troll.h
	$(CC) NPC/swamp_troll.cpp $(CFLAGS) -o swamp_troll.o -c

skeleton: NPC/skeleton.cpp NPC/skeleton.h
	$(CC) NPC/skeleton.cpp $(CFLAGS) -o skeleton.o -c

skeletonking: NPC/skeleton_king.cpp NPC/skeleton_king.h
	$(CC) NPC/skeleton_king.cpp $(CFLAGS) -o skeleton_king.o -c

