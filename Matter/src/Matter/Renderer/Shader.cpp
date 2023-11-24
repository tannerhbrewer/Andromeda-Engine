#include "mtpch.h"

#include "Shader.h"

#include "Matter/Core/Base.h"

#include "Matter/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Matter {

	Matter::Ref<Shader> Shader::Create(const std::string& filepath) {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None: MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(filepath);

		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

	Matter::Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource) {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None: MATTER_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(name, vertexSource, fragmentSource);

		}

		MATTER_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;

	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader) {

		MATTER_ASSERT(!Exists(name), "Shader already exists!");
		m_Shaders[name] = shader;

	}

	void ShaderLibrary::Add(const Ref<Shader>& shader) {

		auto& name = shader->GetName();
		Add(name, shader);

	}

	Ref<Shader> ShaderLibrary::Load(const std::string& filepath) {

		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;

	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath) {

		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;

	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name) {

		MATTER_ASSERT(Exists(name), "Shader not found!");
		return m_Shaders[name];

	}

	bool ShaderLibrary::Exists(const std::string& name) const {

		return m_Shaders.find(name) != m_Shaders.end();

	}

}