#include "mtpch.h"

#include "Application.h"

#include "Matter/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Matter {

	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());

	}

	Application::~Application() {



	}

	void Application::Run() {

		while (m_Running) {

			glClearColor(0.3f, 0.3f, 0.3f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->Update();

		}

	}

}