set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.10)
project(ProcessingCpp)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -g")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov -g")

# find_package(SFML REQUIRED)

add_executable(ProcessingCpp
                src/main.cpp          /
                src/index.cpp
              )

set_target_properties(ProcessingCpp PROPERTIES CMAKE_INCLUDE_CURRENT_DIR TRUE)
target_include_directories(ProcessingCpp PUBLIC include)
add_subdirectory(library)
target_link_libraries(ProcessingCpp ProcessingCppLib)
