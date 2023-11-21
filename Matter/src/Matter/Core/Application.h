#pragma once

#include "Matter/Events/Event.h"

#include "Matter/Core/Window.h"

namespace Matter {

	class Application {

	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	Application* CreateApplication();

}