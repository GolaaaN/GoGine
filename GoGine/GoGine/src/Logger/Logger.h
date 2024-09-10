#pragma once

#include <memory>
#include "../Core/Core.h"
#include "spdlog/spdlog.h"


namespace GOG {
	
	class GOG_API Logger
	{
	public:
		/*
		* This function initializes the logger
		*/
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Logger macros

#define GOG_TRACE_LOG(...) GOG::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define GOG_INFO_LOG(...) GOG::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define GOG_WARN_LOG(...) GOG::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define GOG_DEBUG_LOG(...) GOG::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define GOG_ERROR_LOG(...) GOG::Logger::GetCoreLogger()->error(__VA_ARGS__)

// Client Logger macros

#define APP_TRACE_LOG(...) GOG::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define APP_INFO_LOG(...) GOG::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define APP_WARN_LOG(...) GOG::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define APP_DEBUG_LOG(...) GOG::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define APP_ERROR_LOG(...) GOG::Logger::GetCoreLogger()->error(__VA_ARGS__)



