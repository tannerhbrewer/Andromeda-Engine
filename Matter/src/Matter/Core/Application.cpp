#include "mtpch.h"

#include "Application.h"

#include "Matter/Core/Input.h"

#include "Matter/Renderer/Renderer.h"

#include <glfw/glfw3.h>

namespace Matter {

	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() {

		MATTER_ASSERT(!s_Instance, "Application already exists.");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		Renderer::Initialize();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	}

	void Application::PushLayer(Layer* layer) {

		m_LayerStack.PushLayer(layer);

	}

	void Application::PushOverlay(Layer* overlay) {

		m_LayerStack.PushOverlay(overlay);

	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {

			(*--it)->OnEvent(e);
			if (e.Handled)
				break;

		}

	}

	void Application::Run() {

		while (m_Running) {

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			for (Layer* layer : m_LayerStack)
				layer->Update(timestep);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->ImGuiRender();
			m_ImGuiLayer->End();

			m_Window->Update();

		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {

		m_Running = false;
		return true;

	}

}