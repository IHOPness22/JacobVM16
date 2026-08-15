#include <cstdint>
 
 struct JacobVM {
    uint16_t memory[65536];
    uint16_t reg[8];
    uint16_t pc;
    uint16_t flag; //keeping one flag reg for now
    //dont know yet if i should use 1-3
    uint16_t stack[16];
    uint16_t sp;
};

JacobVM VM = {};