#include "pch.h"
#include "GLFWimplementation.h"
#include "LeafUtil.h"

namespace Leaf
{
	GLFWimplementation::GLFWimplementation()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void GLFWimplementation::Create(int width, int height, const std::string& windowName)
	{
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			LEAF_LOG("Failed to initialize GLAD");
		}
	}

	void GLFWimplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	GLFWimplementation::~GLFWimplementation()
	{
		glfwTerminate();
	}

}