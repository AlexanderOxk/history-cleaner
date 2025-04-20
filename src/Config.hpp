#pragma once

#include <string>

class Config {
public:
    Config() = delete;
    Config(int argc, char** argv);

    bool ParseOk() const;
    bool PrintHelp() const;

    const std::string& GetHistoryFilePath() const;

private:
    bool found_history_path = false;
    bool found_unknown_args = false;

    bool print_help = false;
    std::string history_file_path;
};
