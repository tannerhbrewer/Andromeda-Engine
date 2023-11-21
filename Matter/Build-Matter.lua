
project "Matter"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"src/**.h",
		"src/**.cpp",

	}

	includedirs {

		"src",

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