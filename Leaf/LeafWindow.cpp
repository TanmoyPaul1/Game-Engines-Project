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

		mWidth = width; 
		mHeight = height;
	}

	void LeafWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	int LeafWindow::GetWidth() const
	{
		return mWidth;
	}

	int LeafWindow::GetHeight() const
	{
		return mHeight;
	}
	void LeafWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		mImplementation->SetKeyPressedCallback(keyPressedCallback);
	}
	void LeafWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		mImplementation->SetKeyReleasedCallback(keyReleasedCallback);
	}
}