#include <vector>
#include <iostream>
#include <optional>

#ifndef OUT_H
#define OUT_H
struct Output
{
    std::optional<std::string> files;
    std::optional<std::string> output_files;
    std::optional<std::string> chr_file;

    bool print_file;
};

#endif
Output parse_cmd(std::vector<std::string> args);