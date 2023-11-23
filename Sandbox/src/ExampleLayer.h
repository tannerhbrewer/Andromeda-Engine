#pragma once

#include <Matter/Matter.h>

#include "imgui/imgui.h"

class ExampleLayer : public Matter::Layer {

public:
	ExampleLayer() : Layer("Example") {}

	void Update() override {

		

	}

	virtual void ImGuiRender() override {

		ImGui::Begin("Test");
		ImGui::Text("Welcome to Sandbox!");
		ImGui::End();

	}

	void OnEvent(Matter::Event& event) override {

		

	}

};