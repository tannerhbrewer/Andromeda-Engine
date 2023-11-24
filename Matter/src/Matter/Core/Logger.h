#pragma once

#include "Matter/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Matter {

	class Logger {

	public:
		static void Initialize();

		inline static Ref<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_EngineLogger;
		static Ref<spdlog::logger> s_ClientLogger;

	};

}

// ENGINE LOGGER MACROS
#define MATTER_TRACE(...)		::Matter::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define MATTER_INFO(...)		::Matter::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define MATTER_WARN(...)		::Matter::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define MATTER_ERROR(...)		::Matter::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define MATTER_CRITICAL(...)    ::Matter::Logger::GetEngineLogger()->critical(__VA_ARGS__)

// CLIENT LOGGER MACROS
#define APPLICATION_TRACE(...)	::Matter::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define APPLICATION_INFO(...)	::Matter::Logger::GetClientLogger()->info(__VA_ARGS__)
#define APPLICATION_WARN(...)	::Matter::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define APPLICATION_ERROR(...)	::Matter::Logger::GetClientLogger()->error(__VA_ARGS__)
#define APPLICATION_FATAL(...)	::Matter::Logger::GetClientLogger()->critical(__VA_ARGS__)