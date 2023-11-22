#include <Matter/Matter.h>

#include "ExampleLayer.h"

class SandboxApplication : public Matter::Application {

public:
	SandboxApplication() {

		PushLayer(new ExampleLayer());
		PushOverlay(new Matter::ImGuiLayer());

	}

	~SandboxApplication() {



	}

};

Matter::Application* Matter::CreateApplication() {

	return new SandboxApplication();

}