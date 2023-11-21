#include <Matter/Matter.h>

class SandboxApplication : public Matter::Application {

public:
	SandboxApplication() {



	}

	~SandboxApplication() {



	}

};

Matter::Application* Matter::CreateApplication() {

	return new SandboxApplication();

}