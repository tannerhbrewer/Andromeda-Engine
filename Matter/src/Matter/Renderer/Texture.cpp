#include "mtpch.h"

#include "Texture.h"

#include "Matter/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Matter {

	Ref<Texture2D> Texture2D::Create(const std::string& path) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
			case RendererAPI::API::OpenGL:	return std::make_shared<OpenGLTexture2D>(path);

		}

		MATTER_ASSERT(false, "Unknown renderer API.");
		return nullptr;

	}

}