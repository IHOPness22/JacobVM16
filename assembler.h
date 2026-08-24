#pragma once 
#include "assembler.cpp"

void recieveInput(std::array<std::string, 16>& lines, int cl);
void convertInstruction(std::array<std::string, 16>& lines, std::array<uint16_t, 16>& codes, std::string& mash);
void stringToHex(std::string& mash);