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

	void LeafApp::Shoot() {}   // override in Fall22.cpp
	
	void LeafApp::Run()
	{
		LEAF_LOG("Leaf Running... ");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		//int x{ 600 }, y{ 350 };		// fish coordinates

		//LeafWindow::GetWindow()->SetKeyPressedCallback([&](const KeyPressedEvent& event) {
		//	if (event.GetKeyCode() == LEAF_KEY_LEFT) x -= 10;
		//	else if (event.GetKeyCode() == LEAF_KEY_RIGHT) x += 10;
		//	else if (event.GetKeyCode() == LEAF_KEY_UP) y += 10;
		//	else if (event.GetKeyCode() == LEAF_KEY_DOWN) y -= 10;
		//	});

		//LeafWindow::GetWindow()->SetKeyReleasedCallback([&](const KeyReleasedEvent& event) {
		//	if (event.GetKeyCode() == LEAF_KEY_LEFT) x -= 10;
		//	else if (event.GetKeyCode() == LEAF_KEY_RIGHT) x += 10;
		//	else if (event.GetKeyCode() == LEAF_KEY_UP) y += 10;
		//	else if (event.GetKeyCode() == LEAF_KEY_DOWN) y -= 10;
		//	});

		//Picture fish{ "Assets/Textures/fish.png" };

		while (true)
		{
			Renderer::Clear();

			OnUpdate();

			//Renderer::Draw(fish, 600, 350, 1);

			//Shoot();
			std::this_thread::sleep_until(mNextFrameTime);


			LeafWindow::GetWindow()->SwapBuffers(); 

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}