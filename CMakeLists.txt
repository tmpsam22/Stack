cmake_minimum_required(VERSION 3.20)

project(custom_stack)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/${CMAKE_PROJECT_NAME}/main.cpp)

include_directories(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})


