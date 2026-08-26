#include "JacobVM.h"
#include "assembler.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <string>
#include <cstdint>

extern std::array<uint16_t, 8> program;


int main() {
    JacobVM VM; 
    
    //reset every variable that needs to be resetted
    bool running = true;
    VM.flag = 0;
    VM.pc = 0x300;


    //first im gonna need to recieve input of my assmebly line
    std::array<std::string, 16> lines;
    std::vector<uint16_t> codes;  
    int currentLine = 0;
    int counter = 0;
    bool done = false;
    std::string mash = "";
    while (!done)
    {
        recieveInput(lines, currentLine);
        convertInstruction(lines, codes, mash, done);
        int hexResult = stringToHex(mash);
        codes.push_back(hexResult);
    }


    //for any ROM i have i will load up here 
    for (int i=0; i<codes.size(); i++)
    {
        std::cout << codes[i] << "\n";
        VM.memory[VM.pc+i] = codes[i];
    }


    
    
    while (running) {
    
        counter++;

    //grab the opcode 
    uint16_t opcode = VM.memory[VM.pc];   
    VM.pc++;

    uint8_t op = (opcode >> 12) & 0x0F; 
    uint8_t X = (opcode >> 8) & 0x0F; //the first register 
    uint8_t Y = (opcode >> 4) & 0x0F; //the second register 
    uint8_t num = opcode & 0x0F; //the last generated number we get
    //need the first number to determine type of instruction


    std::cout << "op: " << +op << "\n";
    std::cout << "X: " << +X << "\n";
    std::cout << "Y: " << +Y << "\n";
    std::cout << "num: " << +num << "\n";
  

    switch (op) 
    {
        case 0: //ADD
        VM.reg[X] = VM.reg[X] + VM.reg[Y];
        std::cout << "reg X: " << VM.reg[X] << "\n";
        std::cout << "reg Y: " << VM.reg[Y] << "\n";
        if (VM.reg[X] < 255) { VM.flag = 1; } else { VM.flag = 0;}
        break;

        case 1: //SUB
        VM.reg[X] = VM.reg[X] - VM.reg[Y];
        break;

        case 2: //AND
        {
            VM.reg[X] = VM.reg[X] & VM.reg[Y];
            break;
        }

        case 3: //OR
        {
            VM.reg[X] = VM.reg[X] | VM.reg[Y];
            break;
        }  

        case 4: //XOR
        VM.reg[X] = VM.reg[X] ^ VM.reg[Y];
        break;

        case 5: //JMP
        VM.pc = VM.stack.top();
        break;

        case 6: //CALL 
        VM.stack.push(VM.reg[X]);
        VM.pc = VM.reg[X];
        break;

        case 7: //RET
        VM.pc = VM.stack.top();
        VM.stack.pop();
        break;

        case 8: //JSR
        VM.stack.push(VM.pc + 1);
        VM.pc = 0x100;
        break;

        case 9: //LD
        {
            uint8_t address = opcode & 0xFF;
            VM.reg[X] = VM.memory[address];
            break;
        }
        // 0xA
        case 0xA: //LDI immediate the 8 bits are the number we need to load
        {
            uint8_t number = opcode & 0xFF;
            VM.reg[X] = number;
            std::cout << "reg X: " << VM.reg[X] << "\n";
            break;
        }
        // 0xB
        case 0xB: //LDR 
        VM.reg[X] = VM.reg[Y];
        break;
        //OxC
        case 0xC: //STR
        {
        uint8_t number = opcode & 0xFF;
        VM.memory[number] = VM.reg[X];
        break;
        }
        //0xD
        case 0xD: //INC
        VM.reg[X]++;
        break;
        //0xE
        case 0xE: //DEC
        VM.reg[X]--;
        break;
        //0xF
        case 0xF: //BEQ
        { 
            uint8_t number = opcode & 0xFF;
            if (VM.flag == 0) {
                VM.pc = number;
            }
            break;
        }
        
    }

        //this is to make sure if were done executing all opcodes
    if (counter >= codes.size() - 1) {
            running = false;
        }
        std::cout << "R1: " << VM.reg[1] << std::endl;
        std::cout << "R2: " << VM.reg[2] << std::endl;    
        
    }


    return 0;
}


