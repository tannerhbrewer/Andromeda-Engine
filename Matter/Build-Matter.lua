
project "Matter"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mtpch.h"
	pchsource "src/mtpch.cpp"

	files {

		"src/**.h",
		"src/**.cpp",
		"Dependencies/stb_image/**.h",
		"Dependencies/stb_image/**.cpp",
		"Dependencies/glm/glm/**.hpp",
		"Dependencies/glm/glm/**.inl",

	}

	includedirs {

		"src",
		"Dependencies/spdlog/include",
		"Dependencies/GLFW/include",
		"Dependencies/Glad/include",
		"Dependencies/imgui",
		"Dependencies/glm",
		"Dependencies/stb_image",

	}

	links {

		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",

	}

	defines {

		"GLFW_INCLUDE_NONE",
		"_CRT_SECURE_NO_WARNINGS",

	}

	filter "system:windows"
       systemversion "latest"
       defines { "MATTER_PLATFORM_WINDOWS", }

   filter "configurations:Debug"
       defines { "MATTER_DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "MATTER_RELEASE" }
       runtime "Release"
       optimize "On"

   filter "configurations:Dist"
       defines { "MATTER_DIST" }
       runtime "Release"
       optimize "On"