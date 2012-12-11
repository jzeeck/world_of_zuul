#ifndef CONSUMABLE_H_
#define CONSUMABLE_H_

#include "item.h"
#include <string>

class Consumable : public Item {
private:
	std::string consumable_effect;
	int consumable_grade;
public:
	// Constructors
	// Consumable(const std::string name);
	Consumable(const std::string name, const std::string consumable_effect, const int grade);
	~Consumable(){};

	// functions
	std::string get_consumable_effect(void) const;
	void set_consumable_effect(const std::string);
	int get_consumable_grade(void) const;
	void set_consumable_grade(const int);

};

#endif /* CONSUMABLE_H_ */