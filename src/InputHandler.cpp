#include "InputHandler.hpp"

#include <fstream>
#include <iostream>

InputHandler::InputHandler(std::string file_name) {
    std::ifstream file(file_name);
    std::string line;
    while (std::getline(file, line)) {
        lines.emplace_back(line);
    }
    current_line = lines.size() - 1;
}

const std::string& InputHandler::GetLine() {
    if (!HasLine()) {
        return empty_string;
    }
    size_t index = current_line;
    if (current_line == 0) {
        done = true;
    }
    else {
        current_line--;
    }
    return lines[index];
}

bool InputHandler::HasLine() const {
    return !done;
}
