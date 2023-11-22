#pragma once

#include "Matter/Events/Event.h"

namespace Matter {

	class Layer {

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void Attach() {}
		virtual void Detach() {}
		virtual void Update() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};

}