#include "mtpch.h"

#include "Platform/Windows/WindowsWindow.h"

#include "Matter/Events/ApplicationEvent.h"
#include "Matter/Events/KeyEvent.h"
#include "Matter/Events/MouseEvent.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace Matter {

	static bool s_GLFWInitialized = false;

	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description) {

		MATTER_ERROR("GLFW Error ({0}): {1}", error, description);

	}

	Scope<Window> Window::Create(const WindowProperties& properties) {

		return CreateScope<WindowsWindow>(properties);

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

		#ifdef MATTER_DEBUG
		MATTER_INFO("Creating window {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);
		#endif

		if (!s_GLFWInitialized) {

			int success = glfwInit();
			MATTER_ASSERT(success, "Failed to initialize GLFW.");

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;

		}

		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, m_Data.Title.c_str(), nullptr, nullptr);
		
		m_Context = GraphicsContext::Create(m_Window);
		m_Context->Initialize();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);

		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);

		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {

				case GLFW_PRESS: {

					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;

				}

				case GLFW_RELEASE: {

					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;

				}

				case GLFW_REPEAT: {

					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;

				}

			}

		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallback(event);

		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {

				case GLFW_PRESS: {

					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;

				}

				case GLFW_RELEASE: {

					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;

				}

			}

		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);

		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);

		});

	}

	void WindowsWindow::Shutdown() {

		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
		{
			MATTER_INFO("Terminating GLFW");
			glfwTerminate();
		}

	}
	
	void WindowsWindow::Update() {

		glfwPollEvents();
		m_Context->SwapBuffers();

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