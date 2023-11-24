#pragma once

#include <Matter/Matter.h>

class Sandbox2D : public Matter::Layer {

public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void Attach() override;
	virtual void Detach() override;

	void Update(Matter::Timestep ts) override;
	virtual void ImGuiRender() override;
	void OnEvent(Matter::Event& e) override;

private:
	Matter::OrthographicCameraController m_CameraController;

	// Temp
	Matter::Ref<Matter::VertexArray> m_SquareVA;
	Matter::Ref<Matter::Shader> m_FlatColorShader;
	Matter::Ref<Matter::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	glm::vec2 m_SquarePosition = { 0.0f, 0.0f };

};