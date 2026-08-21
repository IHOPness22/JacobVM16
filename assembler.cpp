#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "assembler.h"


void recieveInput(std::array<std::string, 16>& lines, int cl)
{
    std::cout << "Enter your line of assembly (put end to finish):  ";
    std::getline(std::cin, lines[cl]);
    cl++;
}

void convertInstruction(std::array<std::string, 16>& lines, int cl)
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
            } 
            else { word += c;}
        }

        if (!word.empty()) {
            words.push_back(word);
            std::cout << word << std::endl;
            word = "";
        }
        //after collecting all the words from the sentence
        //
 
    }
}