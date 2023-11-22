#include "mtpch.h"

#include "Application.h"

#include <GLFW/glfw3.h>

namespace Matter {

	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}

	Application::~Application() {



	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		//MATTER_TRACE("{0}", e);

	}

	void Application::Run() {

		while (m_Running) {

			glClearColor(0.3f, 0.3f, 0.3f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->Update();

		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {

		m_Running = false;
		return true;

	}

}