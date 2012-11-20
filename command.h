#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
template <class T>
class Command {
private:
	std::string name;
public:
	Command(){name = "";};
	Command(std::string n, T p){name = n;};
};


#endif /* COMMAND_H_ */