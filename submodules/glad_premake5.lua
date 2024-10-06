project "Glad"
    location    "%{wks.location}/submodules/glad"
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
            "_CRT_SECURE_NO_WARNINGS"
        }
