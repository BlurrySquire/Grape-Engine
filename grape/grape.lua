project "GRAPE"
    kind		"StaticLib"
    language	"C++"
    cppdialect	"c++20"
    warnings	"Extra"

    files
    {
        "**.hpp",
        "**.cpp"
    }

    includedirs
    {
        "%{prj.location}",
        IncludeDirectories
    }

    links
    {
        "glfw",
        "spdlog"
    }