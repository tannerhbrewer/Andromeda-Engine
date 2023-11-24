#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {}

void Sandbox2D::Attach() {

	m_SquareVA = Matter::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	Matter::Ref<Matter::VertexBuffer> squareVB;
	squareVB.reset(Matter::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ Matter::ShaderDataType::Float3, "a_Position" }
	});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Matter::Ref<Matter::IndexBuffer> squareIB;
	squareIB.reset(Matter::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Matter::Shader::Create("Assets/Shaders/FlatColor.glsl");
}

void Sandbox2D::Detach() {}

void Sandbox2D::Update(Matter::Timestep ts)
{
	// Update
	m_CameraController.Update(ts);

	// Render
	Matter::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Matter::RenderCommand::Clear();

	Matter::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Matter::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Matter::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Matter::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Matter::Renderer::EndScene();
}

void Sandbox2D::ImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Matter::Event& e)
{
	m_CameraController.OnEvent(e);
}