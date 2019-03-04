#include "Regex.h"
#include <iostream>
#include <string>


int main(char **argc, int argv)
{
    Regex regex("([bcd](a)*|b)(ab|b)");
    std::string output;
    regex.print(output);
    std::cout << output;
    auto match = regex.match("caaab");
    return 0;
}