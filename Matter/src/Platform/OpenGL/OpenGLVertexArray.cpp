#include "mtpch.h"

#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Matter {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {

		switch (type) {

		case Matter::ShaderDataType::Float:    return GL_FLOAT;
		case Matter::ShaderDataType::Float2:   return GL_FLOAT;
		case Matter::ShaderDataType::Float3:   return GL_FLOAT;
		case Matter::ShaderDataType::Float4:   return GL_FLOAT;
		case Matter::ShaderDataType::Mat3:     return GL_FLOAT;
		case Matter::ShaderDataType::Mat4:     return GL_FLOAT;
		case Matter::ShaderDataType::Int:      return GL_INT;
		case Matter::ShaderDataType::Int2:     return GL_INT;
		case Matter::ShaderDataType::Int3:     return GL_INT;
		case Matter::ShaderDataType::Int4:     return GL_INT;
		case Matter::ShaderDataType::Bool:     return GL_BOOL;

		}

		MATTER_ASSERT(false, "Unknown shader type.");
		return 0;

	}

	OpenGLVertexArray::OpenGLVertexArray() {

		glCreateVertexArrays(1, &m_RendererID);

	}

	OpenGLVertexArray::~OpenGLVertexArray() {

		glDeleteVertexArrays(1, &m_RendererID);

	}

	void OpenGLVertexArray::Bind() const {

		glBindVertexArray(m_RendererID);

	}

	void OpenGLVertexArray::Unbind() const {

		glBindVertexArray(0);

	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {

		MATTER_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout.");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();

		for (const auto& element : layout) {

			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			m_VertexBufferIndex++;

		}

		m_VertexBuffers.push_back(vertexBuffer);

	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {

		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;

	}

}