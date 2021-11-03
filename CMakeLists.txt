cmake_minimum_required(VERSION 3.0.0)
project(Compression VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} //..)

add_executable(Compression main.cpp FileReader.cpp FileWriter.cpp LCG.cpp Test.cpp BigNumber.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
