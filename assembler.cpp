#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iomanip>
#include "assembler.h"


void recieveInput(std::array<std::string, 16>& lines, int cl)
{
    std::cout << "Enter your line of assembly (put end to finish):  ";
    std::getline(std::cin, lines[cl]);
    cl++;
}

void convertInstruction(std::array<std::string, 16>& lines, std::vector<uint16_t>& codes, std::string& mash, bool& done)
{
    std::vector<std::string> words;
    //this will help me so i can break every word into letters
    std::string word = "";
    //this is a loop of all my sentences
    for (int i=0; i < lines.size(); i++) {
        //were gonna go through each character 
        for (char c: lines[i]) { 
            if (c == ' ') {
                words.push_back(word); 
                std::cout << word << std::endl;
                word = "";
            } else if (c == ',') { }
            else { word += c;}
        }

        if (!word.empty()) {
            words.push_back(word);
            std::cout << word << std::endl;
            word = "";
        }
    }

    //after collecting all the words from the sentence
    // convert them into opcode before going to next sentence

    for (int i=0; i < words.size(); i++)
    {
        std::cout << words[i] << std::endl;
        if (words[i] == "LDI") { mash += "A"; }
        else if (words[i] == "LDR") { mash += "B"; }
        else if (words[i] == "STR") { mash += "C"; }
        else if (words[i] == "INC") { mash += "D"; }
        else if (words[i] == "DEC") { mash += "E"; }
        else if (words[i] == "BEQ") { mash += "F"; }
        else if (words[i] == "ADD") { mash += "0"; }
        else if (words[i] == "SUB") { mash += "1"; }
        else if (words[i] == "AND") { mash += "2"; }
        else if (words[i] == "OR")  { mash += "3"; }
        else if (words[i] == "XOR") { mash += "4"; }
        else if (words[i] == "JMP") { mash += "5"; }
        else if (words[i] == "CALL") { mash += "6"; }
        else if (words[i] == "RET") { mash += "7"; }
        else if (words[i] == "JSR") { mash += "8"; }
        else if (words[i] == "LD") { mash += "9";}
        else if (words[i] == "R0") { mash += "0"; }
        else if (words[i] == "R1") { mash += "1"; }
        else if (words[i] == "R2") { mash += "2"; }
        else if (words[i] == "R3") { mash += "3"; }
        else if (words[i] == "R4") { mash += "4"; }
        else if (words[i] == "R5") { mash += "5"; }
        else if (words[i] == "R6") { mash += "6"; }
        else if (words[i] == "R7") { mash += "7"; }
        else if (words[i] == "end") 
        { 
            done = true;
            return;
        }
        else {
            std::string str = words[i];
            int num = std::stoi(str);
            std::cout << "number: " << num << std::endl;
            if (num > 15)
            {
                int leftByte = (num >> 4) & 0xF;
                int rightByte = num & 0xF;
                std::cout << "leftByte: " << leftByte << std::endl;
                std::cout << "Rightbyte: " << rightByte << std::endl;

                std::string icons = std::to_string(leftByte);
                std::string icons2 = std::to_string(rightByte);
                mash += (icons + icons2);
            } // EX 49 in hex = 0x31

            
        
            
        }
        
    }
    std::cout << mash << std::endl;

    /*int code = std::stoi(mash, 0, 16);
    std::cout << "Decimal Value: " << code << "\n"; */
    
}


int stringToHex(std::string& mash) {
    std::stringstream str;
    str << mash;
    int value;
    str >> std::hex >> value;
    return value;
}