#include "pch.h"

#include "Leaf.h"
//#include "LeafApp.h"
//#include "LeafUtil.h"
//#include "LeafWindow.h"
//#include "glad/glad.h"
//#include "stb_image.h"
//#include "Picture.h"
//#include "Renderer.h"
//#include "Keys.h"

namespace Leaf
{
	LeafApp::LeafApp()
	{
		LeafWindow::Init();
		LeafWindow::GetWindow()->Create(1000, 800, "TestWindow");

		Renderer::Init();
	}

	void LeafApp::OnUpdate()
	{

	}
	
	void LeafApp::Run()
	{
		LEAF_LOG("Leaf Running... ");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x{ 200 }, y{ 200 };
		LeafWindow::GetWindow()->SetKeyPressedCallback([&](const KeyPressedEvent& event) {
			if (event.GetKeyCode() == LEAF_KEY_LEFT) x -= 10;
			else if (event.GetKeyCode() == LEAF_KEY_RIGHT) x += 10;
			});

		Picture pic{ "Assets/Textures/fish.png" };

		while (true)
		{
			Renderer::Clear();

			OnUpdate();

			Renderer::Draw(pic, x, y, 1);

			std::this_thread::sleep_until(mNextFrameTime);

			LeafWindow::GetWindow()->SwapBuffers(); 

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}