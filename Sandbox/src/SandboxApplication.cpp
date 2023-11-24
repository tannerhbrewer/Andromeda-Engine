#include <Matter/Matter.h>
#include <Matter/Core/EntryPoint.h>

#include "Sandbox2D.h"

class SandboxApplication : public Matter::Application {

public:
	SandboxApplication() {

		PushLayer(new Sandbox2D());

	}

	~SandboxApplication() {



	}

};

Matter::Application* Matter::CreateApplication() {

	return new SandboxApplication();

}