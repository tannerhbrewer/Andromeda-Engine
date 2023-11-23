#include "mtpch.h"

#include "Shader.h"

#include "Matter/Core/Base.h"

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace Matter {

	Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource) {

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* source = vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(vertexShader);

			MATTER_ERROR("{0}", infoLog.data());
			MATTER_ASSERT(false, "Vertex shader compilation failure.");
			return;

		}

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		source = fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);

			MATTER_ERROR("{0}", infoLog.data());
			MATTER_ASSERT(false, "Fragment shader compilation failure.");
			return;

		}

		m_RendererID = glCreateProgram();
		GLuint program = m_RendererID;

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);

		if (isLinked == GL_FALSE) {

			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(program);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(program);
			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);

			MATTER_ERROR("{0}", infoLog.data());
			MATTER_ASSERT(false, "Shader link failure.");
			return;

		}

		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);

	}

	Shader::~Shader() {

		glDeleteProgram(m_RendererID);

	}

	void Shader::Bind() const {

		glUseProgram(m_RendererID);

	}

	void Shader::Unbind() const {

		glUseProgram(0);

	}

	void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix) {

		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));

	}

}