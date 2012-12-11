#ifndef WEAPON_H_
#define WEAPON_H_

#include "item.h"
#include <string>

class Weapon : public Item {
private:
	int weapon_damage;
	
public:
	// Constructors
	// Weapon(const std::string name);
	Weapon(const std::string name, const int damage);
	~Weapon(){};

	// functions
	int get_damage(void) const;
	void set_damage(const int);
};

#endif /* WEAPON_H_ */