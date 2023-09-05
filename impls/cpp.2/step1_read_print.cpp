#include <readline/readline.h>
#include <readline/history.h>
#include <readline/tilde.h>
#include <iostream>
#include <string>

/* A static variable for holding the line. */
static char *line_read = nullptr;

/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
bool rl_readline(const std::string& prompt, std::string& input)
{
    // If the buffer has already been allocated, return the memory
    // to the free pool.
    if (line_read) {
        free(line_read);
        line_read = nullptr;
    }

    // Get a line from the user.
    line_read = readline(prompt.c_str());

    if (line_read == nullptr) return false;

    input = line_read;

    return true;
}

std::string READ(const std::string& input) {
    return input;
}

std::string PRINT(const std::string& input) {
  return input;
}

std::string EVAL(const std::string& input) {
  return input;
}

std::string rep(const std::string& input) {
    return PRINT(EVAL(READ(input)));
}

int main(int arc, char** argv) {
    // Load history
    /* auto path = ".history.cpp.2"; */
    // TODO: History persistance
    using_history();
    HISTORY_STATE* history_get_history_state();
    std::string prompt("user> ");
    std::string input;

    while (rl_readline(prompt, input)) {
        std::cout << rep(input) << "\n";
        add_history(line_read);
    };

    return 0;
}

