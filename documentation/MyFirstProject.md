# Grape-Engine Documentation
## My First Project
- Clone the repo. ``git clone https://github.com/BlurrySquire/Grape-Engine.git --recursive --branch=main``.

- Delete the sandbox folder (project) and create a new folder (project) under the title of your project. Inside that folder create a ``.lua`` file (usually called the project name) with the following contents:
```lua
project "PROJECT_NAME"
    kind    	"WindowedApp"
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
```

- Use [premake5](https://premake.github.io/) to create the project files for your selected build system (e.g. ``premake5 vs2022`` for Visual Studio Community 2022).

- In the project you created, make a ``main.cpp`` file with the following contents:
```c++
#include <grape/core/core.hpp>
#include <grape/core/logger.hpp>

#include <iostream>

GameConfig game_config = {
	.title = "PROJECT_TITLE",
	.width = PROJECT_DISPLAY_WIDTH,
	.height = PROJECT_DISPLAY_HEIGHT
};

int game_entry([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	GRAPE_LOG_INFO("Hello, World!");

	return 0;
}
```