#pragma once

#include "Matter/Core/LayerStack.h"
#include "Matter/Events/Event.h"
#include "Matter/Events/ApplicationEvent.h"

#include "Matter/Core/Window.h"

namespace Matter {

	class Application {

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;

		bool m_Running = true;

	};

	Application* CreateApplication();

}