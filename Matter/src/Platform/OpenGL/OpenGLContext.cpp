#include "mtpch.h"

#include "OpenGLContext.h"

#include "Matter/Core/Base.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Matter {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) {

		MATTER_ASSERT(windowHandle, "Window handle is null.");

	}

	void OpenGLContext::Initialize() {

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MATTER_ASSERT(status, "Failed to initialize Glad.");

	}

	void OpenGLContext::SwapBuffers() {

		glfwSwapBuffers(m_WindowHandle);

	}

}