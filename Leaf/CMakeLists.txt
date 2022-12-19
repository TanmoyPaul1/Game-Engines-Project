set(SOURCE_FILES 
	Event.cpp 
	OpenGLcode/OpenGLPicture.cpp 
	OpenGLcode/OpenGLShader.cpp 
	OpenGLcode/OpenGLRenderer.cpp 
	Picture.cpp 
	Shader.cpp
	Renderer.cpp
	Unit.cpp
	LeafApp.cpp 
	LeafWindow.cpp
	GLFWcode/GLFWimplementation.cpp
   )

set(HEADER_FILES 
	Event.h 
	Keys.h
	OpenGLcode/OpenGLPicture.h 
	OpenGLcode/OpenGLShader.h 
	OpenGLcode/OpenGLRenderer.h 
	Picture.h 
	Shader.h
	Renderer.h
	PictureImplementation.h 
	ShaderImplementation.h
	RendererImplementation.h
	Unit.h
	Leaf.h
	LeafApp.h
	LeafUtil.h
	LeafWindow.h 
	WindowImplementation.h
	GLFWcode/GLFWimplementation.h
   )

add_library(Leaf SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DLEAF_LIB)

target_precompile_headers(Leaf PRIVATE pch.h)

include_directories(../glfw/include)
include_directories(../Leaf) 
include_directories(../glad/include)
include_directories(../stbi)

target_link_libraries(Leaf glfw glad stbi)