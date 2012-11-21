#include "item.h"

std::string Item::get_name() const{
	return item_name;
}

int Item::get_weight() const{
	return item_weight;
}

void Item::set_name(const std::string name){
	item_name = name;
}

void Item::set_weight(const int weight){
	item_weight = weight;
}

bool Item::operator==(const Item other_item) const{
	return (item_name.compare(other_item.get_name()) == 0);
}