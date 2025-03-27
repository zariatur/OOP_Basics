cmake_minimum_required(VERSION 3.10)
project(CalendarEvent)

set(CMAKE_CXX_STANDARD 17)

add_executable(CalendarEvent main.cpp calendar.cpp event.cpp)
