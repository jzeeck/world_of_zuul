#ifndef ARMOR_H_
#define ARMOR_H_

#include "item.h"
#include <string>

class Armor : public Item {
private:
	int armor_protection;
	std::string armor_type;
public:
	// Constructors
	Armor(const std::string name);
	Armor(const std::string name, const int weight, const int protection, const std::string type);

	// functions
	int get_protection(void) const;
	void set_protection(int);
	std::string get_type(void) const;
	void set_type(const std::string);


};

#endif /* ARMOR_H_ */