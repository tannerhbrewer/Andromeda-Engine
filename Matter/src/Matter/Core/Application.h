#pragma once

#include "Matter/Core/LayerStack.h"
#include "Matter/Core/Window.h"
#include "Matter/Core/Timestep.h"

#include "Matter/Events/Event.h"
#include "Matter/Events/ApplicationEvent.h"

#include "Matter/ImGui/ImGuiLayer.h"


namespace Matter {

	class Application {

	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;

		bool m_Running = true;
		bool m_Minimized = false;

	private:
		static Application* s_Instance;

	};

	Application* CreateApplication();

}