#pragma once

#include "LeafUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h"

namespace Leaf
{
	class LEAF_API Renderer
	{
	public:
		static void Init();
		static Renderer* GetRenderer();

		static void Draw(Picture& picture, int x, int y, int z);
		static void Draw(Picture& picture, int x, int y, int z, Shader& shader);

		static void Clear();

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation; 

		Renderer(); 

		Shader mDefaultShader{ "Assets/Shaders/defaultLeafVertex.glsl", "Assets/Shaders/defaultLeafFragment.glsl" };
	};
}