#include "Config.hpp"

#include <filesystem>

Config::Config(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);

        if (arg == "--help" || arg == "-h") {
            print_help = true;
        }
        else {
            // Positional arg should be path to history file
            if (std::filesystem::exists(arg) && !found_history_path) {
                history_file_path = arg;
                found_history_path = true;
            }
            else {
                found_unknown_args = false;
            }
        }
    }
}

bool Config::ParseOk() const {
    return (found_history_path && !found_unknown_args) || print_help;
}

bool Config::PrintHelp() const {
    return print_help;
}

const std::string& Config::GetHistoryFilePath() const {
    return history_file_path;
}
