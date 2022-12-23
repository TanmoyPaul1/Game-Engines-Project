#include "pch.h"
#include "Array.h"

namespace Leaf
{
	Array::Array(const std::vector<Unit>& v)
	{
		mUnitArray = v;
	}

	Array::Array(std::vector<Unit>&& v)
	{
		mUnitArray = v;
	}

	void Array::DrawArrayTop(int x, int y, int z)
	{
		for (int i = 0; i < mUnitArray.size(); i++)
		{
			mUnitArray[i].DrawPicture(x, y, z);
			x += 80;
		}
	}

	void Array::DrawArrayBottom(int x, int y, int z)
	{
		for (int i = 0; i < mUnitArray.size(); i++)
		{
			mUnitArray[i].DrawPicture(x, y, z);
			x -= 80;
		}
	}

	void Array::Insert(Unit newUnit, int pos, int& score)
	{
		mUnitArray.insert(mUnitArray.begin() + pos, newUnit);
		for (int i = 0; i < mUnitArray.size() - 2; ++i)
		{
			if (mUnitArray.size() <= 4)	return;
			if (mUnitArray[i] == mUnitArray[i + 1] && mUnitArray[i + 1] == mUnitArray[i + 2])
			{
				score += 10;
				mUnitArray.erase(mUnitArray.begin() + i, mUnitArray.begin() + i + 3);
				i = 0;
			}
		}
	}

	int Array::Size()
	{
		int size = mUnitArray.size();
		return size;
	}

	void Array::DrawArrayRight(int x, int y, int z)
	{
		for (int i = 0; i < mUnitArray.size(); i++)
		{
			mUnitArray[i].DrawPicture(x, y, z);
			y += 80;
		}
	}

	void Array::DrawArrayLeft(int x, int y, int z)
	{
		for (int i = 0; i < mUnitArray.size(); i++)
		{
			mUnitArray[i].DrawPicture(x, y, z);
			y -= 80;
		}
	}

}