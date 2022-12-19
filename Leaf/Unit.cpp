#include "pch.h"
#include "Unit.h"

namespace Leaf
{
	Unit::Unit(const std::string& picFile, int hp) : mPicture(picFile), mHP(hp) {}

	Unit::Unit(std::string&& picFile, int hp) : mPicture(picFile), mHP(hp) {}

	void Unit::SetCoord(int x, int y, int z)
	{
		mXcoord = x;
		mYcoord = y;
		mZcoord = z;
	}

	int Unit::ChangeX(int xDiff)
	{
		mXcoord += xDiff; 
		return mXcoord; 
	}

	int Unit::ChangeY(int yDiff)
	{
		mYcoord += yDiff;
		return mYcoord;
	}

	int Unit::ChangeZ(int zDiff)
	{
		mZcoord += zDiff;
		return mZcoord;
	}

	int Unit::GetX() const
	{
		return mXcoord;
	}

	int Unit::GetY() const
	{
		return mYcoord;
	}

	int Unit::GetZ() const
	{
		return mZcoord;
	}

	int Unit::ChangeHP(int hpDiff)
	{
		mHP += hpDiff;
		return mHP;
	}

	int Unit::GetHP() const
	{
		return mHP;
	}

	bool Unit::OverlapsWith(const Unit& other) const
	{
		int oneLeft{ GetX() };
		int oneRight{ GetX() + mPicture.GetWidth() };
		int anotherLeft{ other.GetX() };
		int anotherRight{ other.GetX() + other.mPicture.GetWidth() };

		int oneBottom{ GetY() };
		int oneTop{ GetY() + mPicture.GetHeight() };
		int anotherBottom{ other.GetY() };
		int anotherTop{ other.GetY() + other.mPicture.GetHeight() };

		bool collideX{ false };
		if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
			(anotherLeft <= oneLeft && oneLeft <= anotherRight))
			collideX = true;

		bool collideY{ false };
		if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
			(anotherBottom <= oneBottom && oneBottom <= anotherTop))
			collideY = true;

		return collideX && collideY;
	}

}