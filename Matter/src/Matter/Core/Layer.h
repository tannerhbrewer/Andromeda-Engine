#pragma once

#include "Matter/Core/Timestep.h"

#include "Matter/Events/Event.h"

namespace Matter {

	class Layer {

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void Attach() {}
		virtual void Detach() {}
		virtual void Update(Timestep ts) {}
		virtual void ImGuiRender() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};

}