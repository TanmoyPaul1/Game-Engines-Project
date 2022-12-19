#pragma once

#include "LeafUtil.h"
#include "ShaderImplementation.h"
#include "pch.h"

namespace Leaf
{
	class LEAF_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Activate();

		void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideFloatValues(std::string&& valueName, std::vector<float>&& vals);


	private:
		ShaderImplementation* mImplementation{ nullptr };
	};
}