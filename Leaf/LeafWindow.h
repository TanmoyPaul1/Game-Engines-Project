#pragma once

#include "pch.h"
#include "LeafUtil.h"
#include "WindowImplementation.h"

namespace Leaf
{
	class LEAF_API LeafWindow
	{
	public:
		static void Init();
		static LeafWindow* GetWindow();

		virtual  void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();


	private:
		LeafWindow(); // constructor is private so multiple instances cannot be made

		inline static LeafWindow* mInstance{ nullptr };
		WindowImplementation* mImplementation{ nullptr };

	};
}