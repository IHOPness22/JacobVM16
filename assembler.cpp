#include <iostream>
#include <string>
#include "assembler.h"


void recieveInput(std::array<std::string, 16>& lines, int cl)
{
    std::cout << "Enter your line of assembly:  ";
    std::getline(std::cin, lines[cl]);
    std::cout << lines[cl] << std::endl;
    cl++;
}