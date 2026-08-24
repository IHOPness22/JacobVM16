#pragma once 
#include "assembler.cpp"

void recieveInput(std::array<std::string, 16>& lines, int cl);
void convertInstruction(std::array<std::string, 16>& lines, std::vector<uint16_t>& codes, std::string& mash, bool& done);
int stringToHex(std::string& mash);