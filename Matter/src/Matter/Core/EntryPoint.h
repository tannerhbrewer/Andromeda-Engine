#pragma once

#ifdef MATTER_PLATFORM_WINDOWS
 

extern Matter::Application* Matter::CreateApplication();

int main(int argc, char** argv) {

	auto app = Matter::CreateApplication();
	app->Run();
	delete app;

}


#endif