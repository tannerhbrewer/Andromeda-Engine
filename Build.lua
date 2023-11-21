
workspace "Blank Project"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "Application"

	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
	include "Core/Build-Core.lua"
group ""

include "Application/Build-Application.lua"
