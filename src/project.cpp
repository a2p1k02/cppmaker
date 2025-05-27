#include "project.hpp"

#include <filesystem>
#include <fstream>

void create_main_cpp()
{
    std::filesystem::create_directory("src");
    std::filesystem::current_path("src");

    std::ofstream cpp_file("main.cpp");
    cpp_file << "#include <iostream>\n\n";
    cpp_file << "int main() \n{\n";
    cpp_file << "    std::cout << \"hello world\\n\";\n";
    cpp_file << "    return 0;\n";
    cpp_file << "}\n";
    cpp_file.close();
}

void project::create_cmake_project(const std::string& project_name)
{
    std::filesystem::create_directory(project_name); 
    std::filesystem::current_path(project_name);

    std::ofstream cmake_file("CMakeLists.txt");
    cmake_file << "cmake_minimum_required(VERSION 3.30)\n";
    cmake_file << "project(" << project_name << ")\n";
    cmake_file << "add_executable(" << project_name << " src/main.cpp)\n";
    cmake_file.close();
    
    create_main_cpp();
}

void project::create_makefile_project(const std::string& project_name)
{
    std::filesystem::create_directory(project_name); 
    std::filesystem::current_path(project_name);

    std::ofstream makefile("Makefile");
    makefile << "all: \n";
    makefile << "\tclang++ src/main.cpp -o " << project_name << "\n";
    makefile << "clean: \n";
    makefile << "\trm " << project_name << "\n";
    makefile.close();

    create_main_cpp();
}

void project::create_bazel_project(const std::string& project_name)
{
    std::filesystem::create_directory(project_name); 
    std::filesystem::current_path(project_name);

    std::ofstream workspace("WORKSPACE");
    workspace.close();

    std::ofstream bazel_file("BUILD");
    bazel_file << "cc_binary(\n";
    bazel_file << "\tname = \"" << project_name << "\",\n";
    bazel_file << "\tsrcs = [\"src/main.cpp\"],\n";
    bazel_file << ")";
    bazel_file.close();
    
    create_main_cpp();
}

void project::create_qmake_project(const std::string &project_name)
{
    std::filesystem::create_directory(project_name); 
    std::filesystem::current_path(project_name);

    std::ofstream qmake_file(project_name + ".pro");
    qmake_file << "CONFIG -= qt\n";
    qmake_file << "CONFIG += c++17\n";
    qmake_file << "SOURCES += src/main.cpp\n";
    qmake_file.close();

    create_main_cpp();
}

