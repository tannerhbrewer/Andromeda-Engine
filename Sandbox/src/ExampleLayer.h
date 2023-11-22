#pragma once

#include <Matter/Matter.h>

class ExampleLayer : public Matter::Layer {

public:
	ExampleLayer() : Layer("Example") {}

	void Update() override {

		//APPLICATION_INFO("ExampleLayer::Update");

	}

	void OnEvent(Matter::Event& event) override {

		//APPLICATION_TRACE("{0}", event);

	}

};