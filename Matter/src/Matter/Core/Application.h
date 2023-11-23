#pragma once

#include "Matter/Core/LayerStack.h"
#include "Matter/Events/Event.h"
#include "Matter/Events/ApplicationEvent.h"

#include "Matter/ImGui/ImGuiLayer.h"

#include "Matter/Renderer/Shader.h"
#include "Matter/Renderer/Buffer.h"

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

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		bool m_Running = true;

	private:
		static Application* s_Instance;

	};

	Application* CreateApplication();

}