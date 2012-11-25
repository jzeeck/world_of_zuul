#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item {
private:
	std::string item_name;
	std::string item_description;
	std::string item_type;
public:
	Item();
	std::string get_name(void) const;
	std::string get_type(void) const;
	std::string get_description(void) const;	

	// operators
	bool operator==(const Item other_item) const;
protected:
	void set_name(const std::string name);
	void set_description(const std::string description);
	void set_type(const std::string type);
};

#endif /* ITEM_H_ */