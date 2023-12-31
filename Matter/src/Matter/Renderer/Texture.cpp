#include "mtpch.h"

#include "Matter/Renderer/Texture.h"

#include "Matter/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Matter {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(width, height);

		}

		MATTER_ASSERT(false, "Unknown renderer API.");
		return nullptr;

	}

	Ref<Texture2D> Texture2D::Create(const std::string& path) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(path);

		}

		MATTER_ASSERT(false, "Unknown renderer API.");
		return nullptr;

	}

}