project "Sandbox"
	kind		"ConsoleApp"
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
		"%{prj.location}",
		"%{wks.location}/engine/source"
	}

	links {
		"Engine"
	}