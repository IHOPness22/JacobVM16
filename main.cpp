#include "JacobVM.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
#include <cstdint>

int main() {
    JacobVM VM; 
    
    bool running = true;
    VM.flag = 0;
    VM.pc = 0x300;

    
    
    //while (running) {
    

    //grab the opcode 
    uint16_t opcode = VM.memory[VM.pc];   
    VM.pc++;
    std::cout << "opcode: " << opcode << std::endl;

    uint8_t op = (opcode >> 12) & 0x0F; 
    uint8_t X = (opcode >> 8) & 0x0F; //the first register 
    uint8_t Y = (opcode >> 4) & 0x0F; //the second register 
    //need the first number to determine type of instruction

    switch (op) 
    {
        case 0: //ADD
        VM.reg[X] = VM.reg[X] + VM.reg[Y];
        if (VM.reg[X] < 255) { VM.flag = 1; } else { VM.flag = 0;}
        break;

        case 1: //SUB
        VM.reg[X] = VM.reg[X] - VM.reg[Y];
        break;

        case 2: //AND
        break;
    }

    //}
    

    return 0;
}


