#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
class Command {
private:
	std::string name;
public:
	//constructors
	Command();
	Command(std::string & n);
	//destructor
	virtual ~Command();
	//operators
	bool operator==(const Command & c) const;
	bool operator!=(const Command & c) const;
	bool operator<(const Command & c) const;
	bool operator<=(const Command & c) const;
	bool operator>(const Command & c) const;
	bool operator>=(const Command & c) const;
	//functions
	std::string get_name() const;
	//virtual functions
	virtual bool execute(std::vector<std::string> v);
};


#endif /* COMMAND_H_ */