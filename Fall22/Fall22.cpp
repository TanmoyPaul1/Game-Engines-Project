/*
	Inherit a class from LeafApp. Override method OnUpdate in it.
	Feed the name of your class to START_LEAF_GAME macro.

*/

#include "Leaf.h"

class Fall22Game : public Leaf::LeafApp
{
public:
	void OnUpdate() override
	{

	}
};

START_LEAF_GAME(Fall22Game)
