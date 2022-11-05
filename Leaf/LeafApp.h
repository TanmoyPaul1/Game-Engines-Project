#pragma once

#include "LeafUtil.h"

namespace Leaf
{

	class LEAF_API LeafApp
	{
	public:

		virtual void OnUpdate();
		void Run();
	};

}
