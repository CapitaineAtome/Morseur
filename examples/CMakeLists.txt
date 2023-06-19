cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Morseur)

project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(../sources)

add_executable(${PROJECT_NAME}
    main.cpp
)
