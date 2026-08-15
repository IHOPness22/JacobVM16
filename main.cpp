#include "JacobVM.h"
#include <iostream>
#include <algorithm>
#include <cstdint>

int main() {
    JacobVM VM;
    
    
    //first reset everything to 0 before cycle begins
    std::fill(std::begin(VM.memory), std::end(VM.memory), 0);
    std::fill(std::begin(VM.reg), std::end(VM.reg), 0);
    std::fill(std::begin(VM.stack), std::end(VM.stack), 0);
    VM.sp = 0;
    VM.flag = 0;
    VM.pc = 0x300;

    
    return 0;
}


