#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

namespace project 
{
    void create_cmake_project(const std::string& project_name);
    void create_makefile_project(const std::string& project_name);
    void create_bazel_project(const std::string& project_name);
    void create_qmake_project(const std::string& project_name);
}

#endif //PROJECT_HPP
