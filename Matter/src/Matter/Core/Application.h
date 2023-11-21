#pragma once

#include "Matter/Events/Event.h"

namespace Matter {

	class Application {

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	Application* CreateApplication();

}