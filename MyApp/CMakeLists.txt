cmake_minimum_required(VERSION 3.1)

# set the project name
project(MyApp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# add executable
file(GLOB SOURCES "*.cpp")
add_executable(MyApp ${SOURCES})

# specify required libraries
target_link_libraries(MyApp astu)