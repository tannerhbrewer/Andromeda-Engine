#include <Matter/Matter.h>

class SandboxApplication : public Matter::Application {

public:
	SandboxApplication() {

		APPLICATION_INFO("Sandbox Application Created.");

	}

	~SandboxApplication() {



	}

};

Matter::Application* Matter::CreateApplication() {

	return new SandboxApplication();

}