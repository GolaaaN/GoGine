#pragma once
#include "Core.h"

namespace GOG {

	class GOG_API Application
	{
	public:
		Application() = default;
		
		virtual ~Application() = default;

		void run();

	};

	Application* CreateApplication();
}


