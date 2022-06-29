cmake_minimum_required(VERSION 3.20)

project(only_stack)

set (CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC ${CURRENT_DIR}/src/main.cpp
        ${CURRENT_DIR}/src/person/person_keeper.cpp
        ${CURRENT_DIR}/src/person/person.cpp
)

include_directories(${CMAKE_PROJECT_NAME} ${CURRENT_DIR}/include)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})