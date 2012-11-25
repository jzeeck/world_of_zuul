#ifndef WEAPON_H_
#define WEAPON_H_

#include "item.h"
#include <string>

class Weapon : public Item {
private:
	int weapon_damage;
	bool two_handed_weapon;
	
public:
	// Constructors
	// Weapon(const std::string name);
	Weapon(const std::string name, const int damage, const bool two_handed);

	// functions
	int get_damage(void) const;
	void set_damage(const int);
	int get_two_handed(void) const;
	void set_two_handed(const bool);
};

#endif /* WEAPON_H_ */