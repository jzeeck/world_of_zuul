#include "item.h"


Item::Item(){
	item_name = "UNINITIALIZED ITEM";
}
std::string Item::get_name() const{
	return item_name;
}

void Item::set_name(const std::string name){
	item_name = name;
}

std::string Item::get_type() const{
	return item_type;
}
void Item::set_type(const std::string type){
	item_type = type;
}

std::string Item::get_description() const{
	return item_name;
}

void Item::set_description(const std::string description){
	item_description = description;
}

bool Item::operator==(const Item other_item) const{
	return (item_name.compare(other_item.get_name()) == 0);
}