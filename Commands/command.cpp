#include "command.h"
#include <iostream>

Command::Command(){
	name = "";
}
Command::Command(std::string & n){
	name = n;
}
Command::~Command(){
}
//operators
bool Command::operator==(const Command & c) const {
	return name.compare(c.get_name()) == 0;
}
bool Command::operator!=(const Command & c) const{
	return name.compare(c.get_name()) != 0;
}
bool Command::operator<(const Command & c) const{
	return  name.compare(c.get_name()) < 0;
}
bool Command::operator<=(const Command & c) const{
	return name.compare(c.get_name()) <= 0;
}
bool Command::operator>(const Command & c) const{
	return name.compare(c.get_name()) > 0;
}
bool Command::operator>=(const Command & c) const{
	return name.compare(c.get_name()) >= 0;
}
//functions
std::string Command::get_name()const {
	return name;
}
bool Command::execute(std::vector<std::string> v){
	std::cout << "ran base class execute";
	return false;
}