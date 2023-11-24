#include "mtpch.h"

#include "Matter/Renderer/GraphicsContext.h"

#include "Matter/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Matter {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    MATTER_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		MATTER_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}