project "spdlog"
    location    "%{wks.location}/submodules/spdlog"
    kind        "StaticLib"
    language    "C++"

    files
    {
        "%{prj.location}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.location}/include",
        "%{prj.location}/src"
    }

	defines
	{
		"SPDLOG_COMPILED_LIB"
	}