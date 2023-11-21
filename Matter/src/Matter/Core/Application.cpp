#include "Application.h"

#include "Matter/Events/ApplicationEvent.h"
#include "Matter/Core/Logger.h"

namespace Matter {

	Application::Application() {



	}

	Application::~Application() {



	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
			MATTER_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
			MATTER_INFO(e);

		while (true);

	}

}