cmake_minimum_required(VERSION 3.20)

project(skyrim_armor_system_simulated C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Armor src/main.c)


target_include_directories(Armor PRIVATE include)

target_compile_options(Armor PRIVATE -Wall -Wextra -Wpendantic)

