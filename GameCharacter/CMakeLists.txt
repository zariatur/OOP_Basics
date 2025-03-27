cmake_minimum_required(VERSION 3.10)

project(GameCharacter)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameCharacter main.cpp character.cpp game.cpp)
