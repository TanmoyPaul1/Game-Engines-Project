#pragma once

#include "LeafUtil.h"
#include "Picture.h"
#include "Renderer.h"

namespace Leaf
{
	class LEAF_API Unit
	{
	public:
		Unit(const std::string& picFile, const std::string& color);
		Unit(std::string&& picFile, std::string&& color);

		void SetCoord(int x, int y, int z);
		int ChangeX( int xDiff );
		int ChangeY( int yDiff );
		int ChangeZ( int zDiff );

		int GetX() const;
		int GetY() const;
		int GetZ() const;

		std::string GetColor() const;

		bool OverlapsWith( const Unit& other ) const;
		void DrawPicture( int x, int y, int z );

		bool operator==(const Unit& other);

	private:
		Picture mPicture;
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };

		std::string mColor;

		friend class Renderer;
	};
}