cmake_minimum_required(VERSION 3.10)

project(foo-component CXX)

add_library(foo STATIC foo.cpp)

target_compile_features(foo PUBLIC cxx_std_17)

target_include_directories(foo PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS foo
    EXPORT foo-targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(EXPORT foo-targets
    FILE foo-config.cmake
    DESTINATION lib/cmake/foo
)

install(FILES include/foo.hpp DESTINATION include)
