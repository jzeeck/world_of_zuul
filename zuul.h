#ifndef ZUUL_H_
#define ZUUL_H_

#include <vector>
#include <string>
#include <map>
#include <utility>
#include "Commands/command.h"
#include "NPC/npc.h"
#include "NPC/paladin.h"
#include "NPC/troll.h"
#include "NPC/swamp_troll.h"
#include "NPC/skeleton.h"
#include "NPC/skeleton_king.h"
#include "player.h"
#include <stdio.h>
#include <string.h>
#include "Map/map.h"
#include "Commands/command.h"
#include "Commands/game_command.h"

class Zuul {
private:
	void print_welcome_msg(void) const;
	void print_input_error_msg(void) const;
	void print_help_msg(std::vector<std::string>& commands);
	void read_command(void);
	void init(void);
	void init_program_commands(void);
	void print_map(std::vector<std::string>& commands);
	void quit(std::vector<std::string>& commands);
	void go(std::vector<std::string>& commands);
	void look(std::vector<std::string>& commands);
	void talk(std::vector<std::string>& commands);
	void info(std::vector<std::string>& commands);
	void attack(std::vector<std::string>& commands);

	void pickup(std::vector<std::string>& commands);

	void print_valid_commands(void) const;
	void print_valid_directions(void) const;
	void exec_command(void);
	void init_map(void);
	void print_end_msg(void) const;
	void get_adventurer_name(void);
	void npc_action(void);
	void init_npc(void);
	bool is_end_of_game(void);

	std::vector<std::string> split(const std::string& strValue, char separator);
	static bool g_quit;
	static std::vector<std::string> g_commands;
	static std::vector<Command*> g_command_vector;
	static std::vector<NPC*> g_npc_vector;
	//static std::multimap<std::string, void (Zuul::*)(std::vector<std::string>)> g_commad_map;
	static Player* g_player;
public:
	int run(int argc, char** argv);
	Zuul();
	~Zuul();

};

#endif /* ZUUL_H_ */