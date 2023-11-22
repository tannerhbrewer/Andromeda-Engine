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

		virtual void Attach() override;
		virtual void Detach() override;
		virtual void ImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;

	};

}