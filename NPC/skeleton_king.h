#ifndef SKELETONKING_H_
#define SKELETONKING_H_

#include "skeleton.h"

class SkeletonKing : public Skeleton {
private:

public:
	SkeletonKing(std::string p_name, int p_hp, Tile* tile);
	~SkeletonKing();
	virtual void walk(Player& player);
	virtual void talk(Player& player);
	virtual unsigned int do_attack(void) const;
	virtual void action(Player& player);
	virtual bool is_skeleton_king() const;
};

#endif /* SKELETONKING_H_ */