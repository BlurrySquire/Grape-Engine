#include <grape/core/core.hpp>

#include <iostream>

GameConfig game_config = {
	.title = "Grape-Engine Sandbox",
	.width = 800,
	.height = 600
};

int game_entry([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	std::cout << "Hello, World!" << std::endl;

	return 0;
}