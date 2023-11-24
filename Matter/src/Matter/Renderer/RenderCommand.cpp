#include "mtpch.h"

#include "Matter/Renderer/RenderCommand.h"

namespace Matter {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}