#include <catch2/catch_test_macros.hpp>
#include "disasm.h"

TEST_CASE( "Simple disassembly test", "[disassembly]" ) {
    auto disassembler = disassembler_t(32);

    const uint32_t instructionBits = 0xee828293;
    insn_t instruction(instructionBits);
    auto disassembly = disassembler.disassemble(instruction);
    REQUIRE(disassembly == "addi    t0, t0, -280");
}
