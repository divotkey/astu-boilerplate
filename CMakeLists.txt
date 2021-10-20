cmake_minimum_required(VERSION 3.0)

# set project name
project(ASTUApps)

# add required libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/astu astu)

# add sub-projects
add_subdirectory(${PROJECT_SOURCE_DIR}/MyApp myapp)