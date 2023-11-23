#include "mtpch.h"

#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Matter {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}