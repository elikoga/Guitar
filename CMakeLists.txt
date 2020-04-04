cmake_minimum_required(VERSION 3.0.0)
project(KarplusStrong VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include(CTest)
enable_testing()

add_library(RingBuffer RingBuffer.cxx)
add_library(GuitarString GuitarString.cxx)
add_library(Helpers Helpers.cxx)

add_executable(KarplusStrong main.cpp)

target_link_libraries(KarplusStrong PUBLIC Helpers)
target_link_libraries(KarplusStrong PUBLIC RingBuffer)
target_link_libraries(KarplusStrong PUBLIC GuitarString)
target_link_libraries(KarplusStrong PUBLIC ${CURSES_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
