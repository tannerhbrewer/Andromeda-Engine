#include "mtpch.h"

#include "Matter/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Matter {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create() {

		switch (s_API) {

			case RendererAPI::API::None:    MATTER_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();

		}

		MATTER_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}