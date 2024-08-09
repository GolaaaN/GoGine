#include "Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace GOG {

	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init()
	{

		spdlog::set_pattern("(%D - %T)@%n: %v");

		s_CoreLogger = spdlog::stdout_color_mt("GOG");
		s_CoreLogger->set_level(spdlog::level::trace);

		GOG_INFO_LOG("info blah bkah");
		

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}

}



