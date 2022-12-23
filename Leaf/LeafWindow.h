#pragma once

#include "pch.h"
#include "LeafUtil.h"
#include "WindowImplementation.h"
#include "Event.h"

namespace Leaf
{
	class LEAF_API LeafWindow
	{
	public:
		static void Init();
		static LeafWindow* GetWindow();

		virtual  void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);
	private:
		inline static LeafWindow* mInstance{ nullptr };
		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}