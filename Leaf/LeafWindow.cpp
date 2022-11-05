#include "pch.h"
#include "LeafWindow.h"
#include "GLFWcode/GLFWimplementation.h"

namespace Leaf 
{
	void LeafWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new LeafWindow;

#ifdef LEAF_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
#elif defined LEAF_MAC
			mInstance->mImplementation = new GLFWimplementation;
#else
			mInstance->mImplementation = new GLFWimplementation;
#endif
		}
	}

	LeafWindow* LeafWindow::GetWindow()
	{
		return mInstance;
	}

	void LeafWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);
	}

	void LeafWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	LeafWindow::LeafWindow()
	{
	}

}