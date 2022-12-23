#pragma once

#include "pch.h"
#include "LeafUtil.h"

constexpr int FRAMES_PER_SECOND = 20;

namespace Leaf
{

	class LEAF_API LeafApp
	{
	public:
		LeafApp();
		virtual void OnUpdate();
		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000  / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
