cmake_minimum_required(VERSION 3.3)
project(Lab03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)
add_executable(Lab03 ${SOURCE_FILES})
find_package(openssl)
include_directories(${OPENSSL_INCLUDE_DIR})
