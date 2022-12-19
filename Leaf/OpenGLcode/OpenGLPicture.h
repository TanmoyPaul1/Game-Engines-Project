#pragma once

#include "pch.h"
#include "../PictureImplementation.h"

namespace Leaf
{
	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& pictureFile);
		OpenGLPicture(std::string&& pictureFile);

		virtual int GetHeight() const override;
		virtual int GetWidth() const override;

		virtual void Activate() override;

		~OpenGLPicture();

	private:
		unsigned int mImage{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}