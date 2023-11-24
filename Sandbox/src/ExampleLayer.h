#pragma once

#include <Matter/Matter.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Matter::Layer {

public:
	ExampleLayer() : Layer("Example"), m_CameraController(1280.0f / 720.0f) {
	
		m_VertexArray.reset(Matter::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Matter::Ref<Matter::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Matter::VertexBuffer::Create(vertices, sizeof(vertices)));
		Matter::BufferLayout layout = {
			{ Matter::ShaderDataType::Float3, "a_Position" },
			{ Matter::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Matter::Ref<Matter::IndexBuffer> indexBuffer;
		indexBuffer.reset(Matter::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Matter::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Matter::Ref<Matter::VertexBuffer> squareVB;
		squareVB.reset(Matter::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Matter::ShaderDataType::Float3, "a_Position" },
			{ Matter::ShaderDataType::Float2, "a_TexCoord"},
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Matter::Ref<Matter::IndexBuffer> squareIB;
		squareIB.reset(Matter::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		m_Shader = Matter::Shader::Create("Assets/Shaders/Triangle.glsl");
		m_FlatColorShader = Matter::Shader::Create("Assets/Shaders/FlatColor.glsl");
		auto textureShader = m_ShaderLibrary.Load("Assets/Shaders/Texture.glsl");

		m_Texture = Matter::Texture2D::Create("Assets/Textures/Checkerboard.png");
		m_ChernoLogoTexture = Matter::Texture2D::Create("Assets/Textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Matter::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Matter::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	
	}

	void Update(Matter::Timestep ts) override {

		m_CameraController.Update(ts);

		Matter::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Matter::RenderCommand::Clear();

		Matter::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Matter::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Matter::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++) {

			for (int x = 0; x < 20; x++) {

				glm::vec3 position(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * scale;
				Matter::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);

			}

		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Matter::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_ChernoLogoTexture->Bind();
		Matter::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		Matter::Renderer::Submit(m_Shader, m_VertexArray, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		Matter::Renderer::EndScene();

	}

	virtual void ImGuiRender() override {

		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();

	}

	void OnEvent(Matter::Event& e) override {

		m_CameraController.OnEvent(e);

	}

private:
	Matter::ShaderLibrary m_ShaderLibrary;
	Matter::Ref<Matter::Shader> m_Shader;
	Matter::Ref<Matter::VertexArray> m_VertexArray;

	Matter::Ref<Matter::Shader> m_FlatColorShader;
	Matter::Ref<Matter::VertexArray> m_SquareVA;

	Matter::Ref<Matter::Texture2D> m_Texture, m_ChernoLogoTexture;

	Matter::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

};