#include "JacobVM.h"
#include "testProgram.cpp"
#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
#include <cstdint>

extern std::array<uint16_t, 8> program;


int main() {
    JacobVM VM; 
    
    bool running = true;
    VM.flag = 0;
    VM.pc = 0x300;


    //for any ROM i have i will load up here 
    for (int i=0; i < program.size(); i++)
    {
        VM.memory[VM.pc + i] = program[i];
    }


    
    
    //while (running) {
    

    //grab the opcode 
    uint16_t opcode = VM.memory[VM.pc];   
    VM.pc++;
    std::cout << "opcode: " << opcode << std::endl;

    uint8_t op = (opcode >> 12) & 0x0F; 
    uint8_t X = (opcode >> 8) & 0x0F; //the first register 
    uint8_t Y = (opcode >> 4) & 0x0F; //the second register 
    uint8_t num = opcode & 0x0F; //the last generated number we get
    //need the first number to determine type of instruction

    switch (op) 
    {
        case 0: //ADD
        VM.reg[X] = VM.reg[X] + VM.reg[Y];
        if (VM.reg[X] < 255) { VM.flag = 1; } else { VM.flag = 0;}
        std::cout << "Equals: " << VM.reg[X] << std::endl;
        break;

        case 1: //SUB
        VM.reg[X] = VM.reg[X] - VM.reg[Y];
        break;

        case 2: //AND
        VM.reg[X] = VM.reg[Y] & num;
        break;

        case 3: //OR
        VM.reg[X] = VM.reg[Y] | num;
        break;  

        case 4: //XOR
        VM.reg[X] = VM.reg[Y] ^ num;
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
        
        case 10: //LDI immediate the 8 bits are the number we need to load
        {
            uint8_t number = opcode & 0xFF;
            VM.reg[X] = number;
            break;
        }

        case 11: //LDR 
        VM.reg[X] = VM.reg[Y];
        break;

        case 12: //STR
        VM.memory[VM.reg[Y]] = VM.reg[X];
        break;

        case 13: //INC
        VM.reg[X]++;
        break;

        case 14: //DEC
        VM.reg[X]--;
        break;

        case 15: //BEQ
        {
            uint8_t number = opcode & 0xFF;
            if (VM.flag == 0) {
                VM.pc = number;
            }
            break;
        }
        
    }

    //}
    

    return 0;
}


