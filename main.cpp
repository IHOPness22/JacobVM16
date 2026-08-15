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

    uint8_t op = (opcode >> 12) & 0x0F; 
    //need the first number to determine type of instruction

    switch (op) 
    {
        case 0:
        break;
    }

    //}
    

    return 0;
}


