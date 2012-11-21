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
	Consumable(std::string name);
	Consumable(std::string name, int weight, std::string consumable_effect, int grade);

	// functions
	std::string get_consumable_effect(void);
	void set_consumable_effect(std::string);
	int get_consumable_grade(void);
	void set_consumable_grade(int);

};

#endif /* CONSUMABLE_H_ */