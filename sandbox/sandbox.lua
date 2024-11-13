project "Sandbox"
    kind    "WindowedApp"
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
        "%{wks.location}",
        IncludeDirectories
    }

    links
    {
        "Grape"
    }