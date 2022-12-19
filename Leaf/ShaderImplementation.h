#pragma once

namespace Leaf
{
	class ShaderImplementation
	{
	public:
		virtual void Activate() = 0;

		virtual void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals) = 0;
		virtual void ProvideFloatValues(std::string&& valueName, const std::vector<float>& vals) = 0;

		virtual ~ShaderImplementation() {};
	};
}