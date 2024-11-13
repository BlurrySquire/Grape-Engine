IncludeDirectories = {}

IncludeDirectories["spdlog"] = "%{wks.location}/submodules/spdlog/include"
IncludeDirectories["glfw"] = "%{wks.location}/submodules/glfw/include"

workspace "Grape-Engine"
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
        "Release",
        "RelWithDebug"
    }

    -- Different release configurations
    filter "configurations:Debug"
        defines		"GRAPE_BUILD_DEBUG"
        optimize	"Off"
        runtime		"Debug"
        symbols		"Full"

    filter "configurations:Release"
        defines		"GRAPE_BUILD_RELEASE"
        optimize	"Full"
        runtime		"Release"
        symbols		"Off"

    filter "configurations:RelWithDebug"
        defines		"GRAPE_BUILD_RELWITHDEBUG"
        optimize	"Full"
        runtime		"Release"
        symbols		"Full"

    -- Platform specific configurations
    filter "system:windows"
        systemversion	"latest"
        staticruntime	"On"
        
        defines
        {
            "GRAPE_PLATFORM_WINDOWS"
        }
    
    filter "system:linux"
        defines
        {
            "GRAPE_PLATFORM_LINUX"
        }


include "grape/grape.lua"
include "sandbox/sandbox.lua"

include "submodules/glfw_premake5.lua"