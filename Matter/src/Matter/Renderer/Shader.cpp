#include "mtpch.h"

#include "Shader.h"

#include "Matter/Core/Base.h"

#include "Matter/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Matter {

	Shader* Shader::Create(const std::string& filepath) {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None: MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(filepath);

		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

	Shader* Shader::Create(const std::string& vertexSource, const std::string& fragmentSource) {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None: MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSource, fragmentSource);

		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

}