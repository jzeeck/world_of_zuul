#ifndef GAME_COMMAND_H_
#define GAME_COMMAND_H_

#include <string>
#include <iostream>
#include <vector>
#include "command.h"
template<class T, class S>
class GameCommand : public Command{
private:
	T func_ptr;
	S obj;
public:
	//constructors
	GameCommand();
	GameCommand(std::string & n,T p);
	GameCommand(std::string & n,T p, S c);

	//virtual functions
	virtual bool execute(std::vector<std::string> v);
	//extra functions
	T get_function(){return func_ptr;};
};

template<class T, class S>
GameCommand<T, S>::GameCommand() : Command(){}

template<class T, class S>
GameCommand<T, S>::GameCommand(std::string & n,T p) : Command(n) {
	func_ptr = p;
}

template<class T, class S>
GameCommand<T, S>::GameCommand(std::string & n,T p, S c) : Command(n) {
	func_ptr = p;
	obj = c;
}

template<class T, class S>
bool GameCommand<T, S>::execute(std::vector<std::string> v){
	//ptr(g_commands);
	//ptr(v);
	//std::cout << "ran execute!";
	(obj->*func_ptr)(v);
	return true;
}


#endif /* GAME_COMMAND_H_ */