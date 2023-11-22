#pragma once

#include "Matter/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Matter {

	class OpenGLContext : public GraphicsContext {

	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Initialize() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;

	};

}