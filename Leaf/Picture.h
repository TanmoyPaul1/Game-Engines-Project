#pragma once

#include "pch.h"
#include "LeafUtil.h"
#include "PictureImplementation.h"

namespace Leaf
{
	class LEAF_API Picture
	{
	public:
		Picture(const std::string& sourceFile);
		Picture(std::string&& sourceFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };


	};
}