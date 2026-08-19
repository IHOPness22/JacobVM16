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
    uint8_t num = opcode & 0x0F; //the last generated number we get
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
        VM.reg[X] = VM.reg[Y] & num;
        break;

        case 3: //NOT
        {
            uint16_t result = ~VM.reg[X];
            VM.reg[X] = result;
            break; 
        }    

        case 4: //BRANCH 
        VM.pc = 0x000;
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
    }

    //}
    

    return 0;
}


