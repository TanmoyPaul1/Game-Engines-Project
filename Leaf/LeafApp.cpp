#include "pch.h"

#include "LeafApp.h"
#include "LeafUtil.h"
#include "LeafWindow.h"
#include "glad/glad.h"

namespace Leaf
{
	void LeafApp::OnUpdate()
	{

	}
	
	void LeafApp::Run()
	{
		LEAF_LOG("Leaf Running... ");

		LeafWindow::Init();
		LeafWindow::GetWindow()->Create(600, 400, "TestWindow");

		/*
		// set up vertex data (and buffer(s)) and configure vertex attributes
		float vertices[] = {
			-0.5f, -0.5f, // left  
			 0.5f, -0.5f, // right 
			 0.0f,  0.5f  // top   
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);

		*/

		while (true)
		{
			LeafWindow::GetWindow()->SwapBuffers(); 

			OnUpdate();
		}
	}
}