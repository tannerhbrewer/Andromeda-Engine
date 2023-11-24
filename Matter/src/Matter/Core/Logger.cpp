#include "mtpch.h"

#include "Matter/Core/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Matter {

	Ref<spdlog::logger> Logger::s_EngineLogger;
	Ref<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Initialize() {

		spdlog::set_pattern("%^%T [%n] %v%$");

		s_EngineLogger = spdlog::stdout_color_mt("ENGINE");
		s_EngineLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ClientLogger->set_level(spdlog::level::trace);

	}

}