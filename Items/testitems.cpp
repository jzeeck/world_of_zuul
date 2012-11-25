#include "testitems.h"
using namespace std;
int main(int argc, char** argv) {

	Player fool;
	// Player * player_pointer = player;

	cout << fool.get_hp() << endl;
	cout << fool.get_exp() << endl;
	fool.level_up();
	cout << fool.get_hp() << endl;
	cout << fool.get_exp() << endl;
	fool.delete_inventory_at(0);
	// Weapon * sword = new Weapon("Sword",100,false);
	// Weapon * pointer;
	// *pointer = sword;
	
	// sword.get_damage();
	// cout <<"strenght: " << fool.get_strength() << endl;
	
	// fool.equip_weapon(sword);
	// cout <<"strenght + 100: " << fool.get_strength() << endl;
	// fool.unequip_item("WEAPON");
	// cout <<"strenght - 100: " << fool.get_strength() << endl;

	//fool.unequip_item("WEAPON");
	// delete sword;
	std::cout << "testitems finished" << std::endl;
	// return 1;
}