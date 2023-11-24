#include "mtpch.h"

#include "Matter/Core/Application.h"

#include "Matter/Core/Input.h"

#include "Matter/Renderer/Renderer.h"

#include <glfw/glfw3.h>

namespace Matter {

	Application* Application::s_Instance = nullptr;

	Application::Application() {

		MATTER_ASSERT(!s_Instance, "Application already exists.");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(MATTER_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Initialize();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	}

	Application::~Application() {

		Renderer::Shutdown();

	}

	void Application::PushLayer(Layer* layer) {

		m_LayerStack.PushLayer(layer);

	}

	void Application::PushOverlay(Layer* overlay) {

		m_LayerStack.PushOverlay(overlay);

	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(MATTER_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(MATTER_BIND_EVENT_FN(Application::OnWindowResize));

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

			if (!m_Minimized) {

				for (Layer* layer : m_LayerStack)
					layer->Update(timestep);

			}

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

	bool Application::OnWindowResize(WindowResizeEvent& e) {

		if (e.GetWidth() == 0 || e.GetHeight() == 0) {

			m_Minimized = true;
			return false;

		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;

	}

}