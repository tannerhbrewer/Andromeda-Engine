#include "mtpch.h"

#include "Renderer.h"

#include "Matter/Renderer/Renderer2D.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Matter {

	Scope<Renderer::SceneData> Renderer::s_SceneData = CreateScope<Renderer::SceneData>();

	void Renderer::Initialize() {

		RenderCommand::Initialize();
		Renderer2D::Initialize();

	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height) {

		RenderCommand::SetViewport(0, 0, width, height);

	}

	void Renderer::BeginScene(OrthographicCamera& camera) {

		s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();

	}

	void Renderer::EndScene() {



	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform) {

		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);

		vertexArray->Bind(); 
		RenderCommand::DrawIndexed(vertexArray);

	}

}