#include "testitems.h"
using namespace std;
int main(int argc, char** argv) {

	Player* fool = new Player();

	Weapon * sword = new Weapon("Fools sword",2000);

	fool->equip_weapon(sword);
	fool->print_consumables();
	// fool.use_consumable(0);
	fool->print_consumables();
	fool->print_equipped();
	// delete sword;
	delete fool;
	std::cout << "testitems finished" << std::endl;
	return 1;
}