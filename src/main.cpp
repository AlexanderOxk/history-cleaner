#include "Config.hpp"
#include "InputHandler.hpp"
#include <iostream>

constexpr char help_message[] = "Usage: history-cleaner [-h|--help] <history-file-path>\n"
                                "\t-h|--help\n"
                                "\t\tPrint this help message.\n"
                                "\t<history-file-path>\n"
                                "\t\tPath to the history file that should be cleaned.";

int main(int argc, char** argv) {
    Config config(argc, argv);
    int exit_code = 0;

    if (!config.ParseOk()) {
        std::cerr << "Failed to parse commandline args." << std::endl;
        exit_code = 1;
    }

    if (config.PrintHelp() || exit_code) {
        std::cout << help_message << std::endl;
        return exit_code;
    }

    InputHandler input_handler(config.GetHistoryFilePath());

    return exit_code;
}
