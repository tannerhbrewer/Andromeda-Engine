#pragma once

#include "Matter/Core/Base.h"

#ifdef MATTER_PLATFORM_WINDOWS
 

extern Matter::Application* Matter::CreateApplication();

int main(int argc, char** argv) {

	Matter::Logger::Initialize();
	MATTER_TRACE("Welcome to the Matter Base Engine.");

	auto app = Matter::CreateApplication();
	app->Run();
	delete app;

}


#endif