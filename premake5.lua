IncludeDirectories = {}

IncludeDirectories["engine"] = "%{wks.location}/engine"
IncludeDirectories["glad"] = "%{wks.location}/submodules/glad/include"
IncludeDirectories["glfw"] = "%{wks.location}/glad/glfw/include"

workspace "Game-Engine"
    architecture    "x86_64"
    startproject    "Sandbox"

    targetdir       "build/bin/%{cfg.system}/%{cfg.buildcfg}/%{prj.name}"
    objdir          "build/obj/%{cfg.system}/%{cfg.buildcfg}/%{prj.name}"

    flags
    {
        "MultiProcessorCompile",
        "FatalWarnings"
    }

    configurations
    {
        "Debug",
        "Release"
    }

    filter "configurations:Debug"
        defines		"GRAPE_DEBUG"
        optimize	"Off"
        runtime		"Debug"
        symbols		"Full"

    filter "configurations:Release"
        defines		"GRAPE_RELEASE"
        optimize	"Full"
        runtime		"Release"
        symbols		"Off"

    filter "system:windows"
        systemversion	"latest"
        staticruntime	"On"
        
        defines
        {
            "PLATFORM_WINDOWS",
            "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
        }

include "engine/engine.lua"
include "sandbox/sandbox.lua"

include "submodules/glfw_premake5.lua"
include "submodules/glad_premake5.lua"