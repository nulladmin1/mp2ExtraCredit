cmake_minimum_required(VERSION 3.20)

project(mp2ec)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)

install(TARGETS mp2ec DESTINATION bin)
