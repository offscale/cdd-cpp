cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)
project(cdd_cpp VERSION 0.0.0 LANGUAGES CXX)

set(HOMEPAGE_URL "https://github.com/offscale/cdd-cpp")
set(DESCRIPTION "Compiler driven development implementation for C++")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED)

# Add path to LLVM modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LLVM_CMAKE_DIR}")

# import LLVM CMake functions
include(AddLLVM)

include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS} ${CLANG_DEFINITIONS})

add_llvm_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE clangTooling)
