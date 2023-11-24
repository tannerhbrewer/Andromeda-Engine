#pragma once

#include <memory>

#ifdef MATTER_DEBUG
	#define MATTER_ENABLE_ASSERTS
#endif

#ifdef MATTER_ENABLE_ASSERTS
	#define APPLICATION_ASSERT(x, ...) { if(!(x)) { CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MATTER_ASSERT(x, ...) { if(!(x)) { MATTER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define APPLICATION_ASSERT(x, ...)
	#define MATTER_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MATTER_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Matter {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
