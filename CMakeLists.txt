cmake_minimum_required(VERSION 3.30)

project(cppmaker)

find_package(Boost COMPONENTS program_options)

add_executable(${PROJECT_NAME} src/main.cpp src/project.hpp src/project.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options)
