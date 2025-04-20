#include "InputHandler.hpp"
#include <array>
#include <iostream>

int main(int argc, const char** argv) {
    const std::array<std::string, 3> expected = {
        "Hello world! Big summer blowout",
        "second",
        "first",
    };

    std::cout << "Running on file: " << argv[1] << std::endl;
    InputHandler input_handler(argv[1]);
    std::string line;
    int errors = 0;

    for (int i = 0; i < expected.size(); i++) {
        if (!input_handler.HasLine()) {
            std::cerr << "Did not receive all expected lines!" << std::endl;
            errors++;
            break;
        }

        line = input_handler.GetLine();
        if (expected[i] != line) {
            std::cerr << "Expected: '" << expected[i] << "', received: '" << line << "'"
                      << std::endl;
            errors++;
        }
    }

    if (input_handler.HasLine()) {
        std::cerr << "There were more lines than expected!" << std::endl;
        errors++;
    }

    return errors;
}