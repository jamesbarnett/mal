#include "linenoise.hpp"

/* https://github.com/yhirose/cpp-linenoise */

int main(int arc, char** argv) {
    // Load history
    auto path = ".history.cpp.2";

    linenoise::SetHistoryMaxLen(500);
    linenoise::LoadHistory(path);

    while (true) {
        // Read line
        std::string line;
        auto quit = linenoise::Readline("user> ", line);

        if (quit) {
            break;
        }

        // Add text to history
        linenoise::AddHistory(line.c_str());
    }

    // Save history
    linenoise::SaveHistory(path);

    return 0;
}
