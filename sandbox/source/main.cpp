#include <grape.hpp>

int main(void) {
    GRAPE::AppInfo app_info = {
        .win_title = "Grape-Engine Sandbox",
        .win_width = 1280,
        .win_height = 720,
        .resizable = false
    };

    GRAPE::Application application(app_info);

    application.Run();

    return EXIT_SUCCESS;
}