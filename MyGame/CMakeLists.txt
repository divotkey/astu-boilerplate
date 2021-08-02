cmake_minimum_required(VERSION 3.1)

# set the project name
project(MyGame)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# add executable
file(GLOB SOURCES "*.cpp")
add_executable(MyGame ${SOURCES})

# specify required libraries
target_link_libraries(MyGame astu astu_box2d)
