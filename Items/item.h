#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item {
private:
	std::string item_name;
	std::string item_description;
	int item_weight;
public:
	std::string get_name() const;
	std::string get_description() const;	
	int get_weight() const;

	// operators
	bool operator==(const Item other_item) const;
protected:
	void set_name(const std::string name);
	void set_weight(const int weight);
	void set_description(const std::string description);
};

#endif /* ITEM_H_ */