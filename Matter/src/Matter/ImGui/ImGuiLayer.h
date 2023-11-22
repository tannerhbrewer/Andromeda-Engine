#pragma once

#include "Matter/Core/Layer.h"

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
		float m_Time = 0.0f;

	};

}