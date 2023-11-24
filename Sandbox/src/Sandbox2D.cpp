#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {}

void Sandbox2D::Attach() {

	m_CheckerboardTexture = Matter::Texture2D::Create("Assets/Textures/Checkerboard.png");

}

void Sandbox2D::Detach() {}

void Sandbox2D::Update(Matter::Timestep ts)
{
	// Update
	m_CameraController.Update(ts);

	// Render
	Matter::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Matter::RenderCommand::Clear();

	Matter::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Matter::Renderer2D::DrawQuad(m_SquarePosition, { 1.0f, 1.0f }, m_SquareColor);
	Matter::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Matter::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Matter::Renderer2D::EndScene();

	Matter::Renderer::EndScene();
}

void Sandbox2D::ImGuiRender()
{

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::DragFloat2("Square Position", glm::value_ptr(m_SquarePosition), 0.1f);
	ImGui::End();
}

void Sandbox2D::OnEvent(Matter::Event& e)
{
	m_CameraController.OnEvent(e);
}