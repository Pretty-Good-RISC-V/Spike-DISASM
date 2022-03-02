#include <catch2/catch_test_macros.hpp>
#include "disasm.h"

TEST_CASE( "Simple disassembly test", "[disassembly]" ) {
    auto disassembler = disassembler_t(32);

    {
        const uint64_t u = 0xee800000;
        const int64_t s = (int32_t)u >> 20;
        REQUIRE(s == -280); 
    }

    {
        const uint32_t instructionBits = 0xee828293;
        insn_t instruction(instructionBits);
        auto disassembly = disassembler.disassemble(instruction);
        REQUIRE(disassembly == "addi    t0, t0, -280");
    }

    {
        const uint32_t instructionBits = 0xfc9296e3;
        insn_t instruction(instructionBits);
        auto disassembly = disassembler.disassemble(instruction);
        REQUIRE(disassembly == "bne     t0, s1, pc - 52");
    }

    {
        const uint32_t instructionBits = 0xed9ff06f;
        insn_t instruction(instructionBits);
        auto disassembly = disassembler.disassemble(instruction);
        REQUIRE(disassembly == "j       pc - 0x128");
    }    
}
