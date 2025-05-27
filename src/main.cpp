#include <iostream>
#include <filesystem>
#include <fstream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void create_cmake_project(const std::string& project_name)
{
    std::filesystem::create_directory(project_name); 
    std::filesystem::current_path(project_name);

    std::ofstream cmake_file("CMakeLists.txt");
    cmake_file << "cmake_minimum_required(VERSION 3.30)\n";
    cmake_file << "project(" << project_name << ")\n";
    cmake_file << "add_executable(" << project_name << " src/main.cpp)\n";
    cmake_file.close();

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

int main(int argc, char *argv[])
{
    po::options_description desc("allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("cmake", po::value<std::string>(), "create a project with cmake structure")
        ("makefile", "create a project with make structure")
        ("qmake", "create a project with qmake structure")
        ("bezel", "create a project with bezel structure")
        ("sh", "create a project with bash structure")
        ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("cmake")) {
        //std::cout << vm["cmake"].as<std::string>() << std::endl; 
        create_cmake_project(vm["cmake"].as<std::string>());
    } else if (vm.count("makefile")) {
        
    } else if (vm.count("qmake")) {

    } else if (vm.count("bezel")) {

    } else if (vm.count("sh")) {

    } else {
        std::cout << desc << "\n";
        return 1;
    }

    return 0;
}

