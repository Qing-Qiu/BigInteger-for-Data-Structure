cmake_minimum_required(VERSION 3.23)
project(BigInteger_for_Data_Structure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigInteger_for_Data_Structure
        List.h BigInteger.h List.cpp BigInteger.cpp main.cpp)
