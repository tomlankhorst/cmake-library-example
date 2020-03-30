cmake_minimum_required(VERSION 3.10)

project(cmake-library-example CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(foo REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} foo)
