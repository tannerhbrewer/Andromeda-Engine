#include "mtpch.h"

#include "WindowsWindow.h"

namespace Matter {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProperties& properties) {

		return new WindowsWindow(properties);

	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties) {

		Initialize(properties);

	}

	WindowsWindow::~WindowsWindow() {

		Shutdown();

	}

	void WindowsWindow::Initialize(const WindowProperties& properties) {

		m_Data.Title = properties.Title;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;

		MATTER_INFO("Creating window {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);

		if (!s_GLFWInitialized) {

			int success = glfwInit();
			MATTER_ASSERT(success, "Could not initialize GLFW.");

			s_GLFWInitialized = true;

		}

		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

	}

	void WindowsWindow::Shutdown() {

		glfwDestroyWindow(m_Window);

	}
	
	void WindowsWindow::Update() {

		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}

	void WindowsWindow::SetVSync(bool enabled) {

		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;

	}

	bool WindowsWindow::IsVSync() const {

		return m_Data.VSync;

	}

}