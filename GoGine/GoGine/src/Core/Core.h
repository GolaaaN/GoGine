#pragma once

#ifdef GOG_PLATFORM_WINDOWS
	#ifdef GOG_BUILD_DLL
		#define GOG_API __declspec(dllexport)
	#else
		#define GOG_API __declspec(dllimport)
	#endif
#else
	#error GOG only support Windows!
#endif