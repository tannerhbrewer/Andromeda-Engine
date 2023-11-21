#pragma once

#ifdef MATTER_ENABLE_ASSERTS
	#define APPLICATION_ASSERT(x, ...) { if(!(x)) { CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MATTER_ASSERT(x, ...) { if(!(x)) { MATTER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define APPLICATION_ASSERT(x, ...)
	#define MATTER_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
