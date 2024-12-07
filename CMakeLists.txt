cmake_minimum_required(VERSION 3.10)

project(yeastcpp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES 
    "*.cpp"
    "*.c" 
)

file(GLOB_RECURSE HEADERS 
    "*.hpp" 
    "*.h"
)

# Add the library source files
add_library(yeastcpp 
    ${SOURCES}
)

# Specify include directories for the library (if needed)
target_include_directories(yeastcpp PUBLIC
    include
)

# Install the library and header files
install(TARGETS yeastcpp DESTINATION lib)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/" # source directory
        DESTINATION "include" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.hpp" # select header files
)