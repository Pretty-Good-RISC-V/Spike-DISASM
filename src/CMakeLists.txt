add_library(spike_disasm STATIC
    decode.h
    disasm.cc
    disasm.h
    encoding.h
    regnames.cc
)
add_library(spike_disasm::spike_disasm ALIAS spike_disasm)
target_include_directories(spike_disasm PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(spike_disasm PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(spike_disasm PROPERTIES CXX_STANDARD 17)
