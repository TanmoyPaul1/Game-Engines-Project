#pragma once

#include "LeafUtil.h"
#include "Picture.h"

namespace Leaf
{
	class LEAF_API Unit
	{
	public:
		Unit(const std::string& picFile, int hp);
		Unit(std::string&& picFile, int hp);

		void SetCoord(int x, int y, int z);
		int ChangeX( int xDiff );
		int ChangeY( int yDiff );
		int ChangeZ( int zDiff );

		int GetX() const;
		int GetY() const;
		int GetZ() const;

		int ChangeHP( int hpDiff );
		int GetHP() const;

		bool OverlapsWith( const Unit& other ) const;

	private:
		Picture mPicture;
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };
		int mHP{ 0 };

		friend class Renderer;

	};
}