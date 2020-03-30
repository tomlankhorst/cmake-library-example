cmake_minimum_required(VERSION 3.10)

project(cmake-library-example CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

if(${WITH_PREBUILT_FOO})
  message(STATUS "Building with prebuilt `foo` library")
  list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR})
  find_package(foo REQUIRED)
else()
  message(STATUS "Building with `foo` from source")
  add_subdirectory(foo-component)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} foo)
