#include "game_command.h"

template<class T>
GameCommand<T>::GameCommand() : Command(){}

template<class T>
GameCommand<T>::GameCommand(std::string & n,T p) : Command(n){
	ptr = p;
}
template<class T>
bool GameCommand<T>::execute(){
	return true;
}
