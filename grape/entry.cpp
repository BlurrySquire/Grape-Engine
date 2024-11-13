#include <iostream>

extern int game_entry(int argc, char* argv[]);

int engine_entry(int argc, char* argv[]) {
	int exit_code = game_entry(argc, argv);

    #if defined(GRAPE_BUILD_DEBUG)
        #if defined(GRAPE_PLATFORM_WINDOWS)
            system("pause");
        #endif
    #endif

    return exit_code;
}

#if defined(GRAPE_PLATFORM_WINDOWS)

#include <windows.h>

int WINAPI WinMain(_In_ [[maybe_unused]] HINSTANCE hInstance, _In_opt_ [[maybe_unused]] HINSTANCE hPrevInstance,
                    _In_ [[maybe_unused]] LPSTR lpCmdLine, _In_ [[maybe_unused]] int nCmdShow) {
    #if defined(GRAPE_BUILD_DEBUG)
	    AllocConsole();

        FILE* stdin_new = nullptr;
        FILE* stdout_new = nullptr;
        FILE* stderr_new = nullptr;

        freopen_s(&stdin_new, "conin$", "r", stdin);
        freopen_s(&stdout_new, "conout$", "w", stdout);
        freopen_s(&stderr_new, "conout$", "w", stdout);

        std::ios::sync_with_stdio(true);
    #endif

	return engine_entry(__argc, __argv);
}

#elif defined(GRAPE_PLATFORM_LINUX)

int main(int argc, char* argv[]) {
	return engine_entry(argc, argv);
}

#endif