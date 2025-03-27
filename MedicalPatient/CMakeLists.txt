cmake_minimum_required(VERSION 3.10)

project(MedicalPatient)

set(CMAKE_CXX_STANDARD 11)

add_executable(MedicalPatient main.cpp hospital.cpp patient.cpp)

target_include_directories(MedicalPatient PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
