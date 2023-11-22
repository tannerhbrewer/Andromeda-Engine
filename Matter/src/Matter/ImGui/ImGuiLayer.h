#pragma once

#include "Matter/Core/Layer.h"

#include "Matter/Events/ApplicationEvent.h"
#include "Matter/Events/KeyEvent.h"
#include "Matter/Events/MouseEvent.h"

namespace Matter {

	class ImGuiLayer : public Layer {

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void Attach();
		void Detach();
		void Update();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;

	};

}