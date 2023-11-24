#include "mtpch.h"

#include "VertexArray.h"

#include "Matter/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Matter {

	Ref<VertexArray> VertexArray::Create() {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:		MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
			case RendererAPI::API::OpenGL:		return std::make_shared<OpenGLVertexArray>();
	
		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

}