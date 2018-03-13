cmake_minimum_required(VERSION 3.7)
project(cookbooking)

include_directories(src/)

set(CMAKE_CXX_FLAGS "-std=c++1z -Wall -Werror -Wextra -fsanitize=address")

file(GLOB SRC src/*.cpp)
set(SOURCE_FILES main.cpp ${SRC})
add_executable(cbing ${SOURCE_FILES})