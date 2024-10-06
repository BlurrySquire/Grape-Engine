project "Engine"
	kind		"StaticLib"
	language	"C++"
	cppdialect	"c++20"
	warnings	"Extra"

	files
	{
		"source/**.hpp",
		"source/**.cpp"
	}

    includedirs
	{
		"%{prj.location}/source",
        "%{IncludeDirectories.glad}",
		"%{IncludeDirectories.glfw}"
	}

	libdirs
	{
		"%{wks.location}/build/bin/${cfg.system}/GLFW",
        "%{wks.location}/build/bin/%{cfg.system}/Glad"
	}

    links
	{
		"GLFW",
        "Glad"
	}