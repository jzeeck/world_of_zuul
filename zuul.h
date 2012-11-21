#ifndef ZUUL_H_
#define ZUUL_H_

#include <vector>
#include <string>
#include <map>
#include <utility>
#include "Commands/command.h"
#include "player.h"
#include <stdio.h>
#include <string.h>

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
	void print_valid_commands(void) const;
	void exec_command(void);
	void init_map(void);
	void print_end_msg(void) const;
	void get_adventurer_name(void);
	std::vector<std::string> split(const std::string& strValue, char separator);
	static bool g_quit;
	static std::vector<std::string> g_commands;
	static std::vector<Command*> g_command_vector;
	//static std::multimap<std::string, void (Zuul::*)(std::vector<std::string>)> g_commad_map;
	static Player* g_player;
public:
	int run(int argc, char** argv);
	Zuul();
	~Zuul();

};

#endif /* ZUUL_H_ */