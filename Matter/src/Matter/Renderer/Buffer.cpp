#include "mtpch.h"

#include "Buffer.h"

#include "Matter/Core/Base.h"

#include "Matter/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Matter {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None: MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);

		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None: MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);

		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

}