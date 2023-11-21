#pragma once

namespace Matter {

	class Application {

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	Application* CreateApplication();

}