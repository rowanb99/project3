cmake_minimum_required(VERSION 3.23)
project(project3)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        *.h
        *.cpp
        )

add_executable(project3 ${SOURCES})
