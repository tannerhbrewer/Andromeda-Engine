#pragma once

#include <Matter/Matter.h>

class ExampleLayer : public Matter::Layer {

public:
	ExampleLayer() : Layer("Example") {}

	void Update() override {

		if (Matter::Input::IsKeyPressed(KEY_TAB))
			APPLICATION_TRACE("Tab key is pressed (poll).");

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