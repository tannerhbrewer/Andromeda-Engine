#pragma once

#include "Matter/Core/LayerStack.h"
#include "Matter/Events/Event.h"
#include "Matter/Events/ApplicationEvent.h"

#include "Matter/ImGui/ImGuiLayer.h"

#include "Matter/Renderer/Shader.h"
#include "Matter/Renderer/Buffer.h"
#include "Matter/Renderer/VertexArray.h"

#include "Matter/Renderer/OrthographicCamera.h"

#include "Matter/Core/Window.h"

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

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;

		bool m_Running = true;

	private:
		static Application* s_Instance;

	};

	Application* CreateApplication();

}