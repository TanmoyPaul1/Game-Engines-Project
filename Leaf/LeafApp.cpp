#include "pch.h"

#include "Leaf.h"

namespace Leaf
{
	LeafApp::LeafApp()
	{
		LeafWindow::Init();
		LeafWindow::GetWindow()->Create(1350, 800, "TestWindow");

		Renderer::Init();
	}

	void LeafApp::OnUpdate() {}  // override in Fall22.cpp
	
	void LeafApp::Run()
	{
		LEAF_LOG("Leaf Running... ");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			Renderer::Clear();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			LeafWindow::GetWindow()->SwapBuffers(); 

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}