#include "mtpch.h"

#include "LayerStack.h"

namespace Matter {

	LayerStack::LayerStack() {

		

	}

	LayerStack::~LayerStack() {

		for (Layer* layer : m_Layers) {

			layer->Detach();
			delete layer;

		}

	}

	void LayerStack::PushLayer(Layer* layer) {

		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
		layer->Attach();

	}

	void LayerStack::PushOverlay(Layer* overlay) {

		m_Layers.emplace_back(overlay);
		overlay->Attach();

	}

	void LayerStack::PopLayer(Layer* layer) {

		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);

		if (it != m_Layers.begin() + m_LayerInsertIndex) {

			m_Layers.erase(it);
			m_LayerInsertIndex--;
			layer->Detach();

		}

	}

	void LayerStack::PopOverlay(Layer* overlay) {

		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);

		if (it != m_Layers.end()) {

			m_Layers.erase(it);
			overlay->Detach();

		}

	}

}