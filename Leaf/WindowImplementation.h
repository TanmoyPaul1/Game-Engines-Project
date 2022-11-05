#pragma once

#include "pch.h"

namespace Leaf
{
	class WindowImplementation
	{
	public:
		virtual void Create(int width, int height, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;

	};
}