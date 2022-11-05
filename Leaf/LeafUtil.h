#pragma once

#define START_LEAF_GAME(GameClass) \
	int main() \
	{ \
		GameClass __leaf__game; \
		__leaf__game.Run(); \
		return 0;  \
	}

#ifdef LEAF_WINDOWS
	#ifdef LEAF_LIB
		#define LEAF_API __declspec(dllexport)
	#else
		#define LEAF_API __declspec(dllimport)
	#endif
#else
	#define LEAF_API
#endif

#ifdef LEAF_DEBUG
	#define LEAF_LOG(x) std::cout << x << std::endl;
#else
	#define LEAF_LOG(x) 
#endif