#include <cstdint>
#include <stack>
#include <array>
 

class JacobVM {
    public: 
        std::array<uint16_t, 65536> memory{};
        std::array<uint16_t, 8> reg{};
        std::stack<uint16_t> stack;
        uint16_t pc;
        uint16_t flag;

};

