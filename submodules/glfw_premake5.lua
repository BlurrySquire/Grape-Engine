project "glfw"
    location    "%{wks.location}/submodules/glfw"
    kind        "StaticLib"
    language    "C"

    files
    {
        "%{prj.location}/src/**.c"
    }

    includedirs
    {
        "%{prj.location}/include",
        "%{prj.location}/src"
    }

    filter "system:windows"
        defines
        {
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }
    
    filter "system:linux"
        defines
        {
            "_GLFW_X11",
        }