workspace "Aaliyah"
	architecture "x86"
	startproject "Aaliyah"

	configurations
	{
		"Debug",
		"Release"
	}

	flags "MultiProcessorCompile"

project "Aaliyah"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/build/%{cfg.buildcfg}")
	objdir ("%{wks.location}/.build/%{cfg.buildcfg}")

	pchheader "pch.h"
	pchsource "src/pch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs "src"