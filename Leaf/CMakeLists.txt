set(SOURCE_FILES 
	LeafApp.cpp 
	LeafWindow.cpp
	GLFWcode/GLFWimplementation.cpp
   )

set(HEADER_FILES 
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

include_directories(../glfw/include/)
include_directories(../Leaf) 

target_link_libraries(Leaf glfw)