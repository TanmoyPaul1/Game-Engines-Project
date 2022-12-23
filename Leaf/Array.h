#pragma once

#include "pch.h"
#include "LeafUtil.h"
#include "Unit.h"

namespace Leaf
{
	class LEAF_API Array
	{
	public:
		Array(const std::vector<Unit>& v);
		Array(std::vector<Unit>&& v);

		void DrawArrayRight(int x, int y, int z);
		void DrawArrayLeft(int x, int y, int z);
		void DrawArrayTop(int x, int y, int z);
		void DrawArrayBottom(int x, int y, int z);

		void Insert(Unit newUnit, int pos, int& score);
		int Size();

	private:
		std::vector<Unit> mUnitArray;
	};
}