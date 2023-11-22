#pragma once

#include <Matter/Matter.h>

#include "imgui/imgui.h"

class ExampleLayer : public Matter::Layer {

public:
	ExampleLayer() : Layer("Example") {}

	void Update() override {

		if (Matter::Input::IsKeyPressed(KEY_TAB))
			APPLICATION_TRACE("Tab key is pressed (poll).");

	}

	virtual void ImGuiRender() override {

		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();

	}

	void OnEvent(Matter::Event& event) override {

		if (event.GetEventType() == Matter::EventType::KeyPressed) {

			Matter::KeyPressedEvent& e = (Matter::KeyPressedEvent&)event;
			if (e.GetKeyCode() == KEY_TAB)
				APPLICATION_TRACE("Tab key is pressed (event).");
			APPLICATION_TRACE("{0}", (char)e.GetKeyCode());

		}

	}

};