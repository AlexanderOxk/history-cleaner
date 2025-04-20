#include <string>
#include <vector>

class InputHandler {
public:
    InputHandler() = delete;
    InputHandler(std::string filename);

    const std::string& GetLine();
    bool HasLine() const;

private:
    const std::string empty_string = "";
    std::vector<std::string> lines;
    size_t current_line;
    bool done = false;
};