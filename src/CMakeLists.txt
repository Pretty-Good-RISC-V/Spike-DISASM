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

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview4
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)

add_executable(disasm_tests disasm_tests.cc)
target_link_libraries(disasm_tests PRIVATE spike_disasm Catch2::Catch2WithMain)

catch_discover_tests(disasm_tests)
