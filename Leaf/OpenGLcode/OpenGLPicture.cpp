#include "pch.h"
#include "OpenGLPicture.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "LeafUtil.h"

namespace Leaf
{
	OpenGLPicture::OpenGLPicture(const std::string& pictureFile)
	{
        glGenTextures(1, &mImage);
        glBindTexture(GL_TEXTURE_2D, mImage); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(pictureFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            LEAF_LOG("Failed to load texture");
        }
        stbi_image_free(data);
	}

    OpenGLPicture::OpenGLPicture(std::string&& pictureFile)
    {
        glGenTextures(1, &mImage);
        glBindTexture(GL_TEXTURE_2D, mImage); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(pictureFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            LEAF_LOG("Failed to load texture");
        }
        stbi_image_free(data);
    }

    int OpenGLPicture::GetHeight() const
    {
        return mHeight;
    }

    int OpenGLPicture::GetWidth() const
    {
        return mWidth;
    }

    void OpenGLPicture::Activate()
    {
        glBindTexture(GL_TEXTURE_2D, mImage);
    }

    OpenGLPicture::~OpenGLPicture()
    {
        glDeleteTextures(1, &mImage);
    }
}
