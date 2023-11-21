
workspace "Andromeda-Engine"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "Sandbox"

	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
	include "Matter/Build-Matter.lua"
group ""

include "Sandbox/Build-Sandbox.lua"
