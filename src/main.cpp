#include <iostream>
#include <boost/program_options.hpp>
#include "project.hpp"

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    po::options_description desc("allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("cmake", po::value<std::string>(), "create a project with cmake structure")
        ("makefile", po::value<std::string>(), "create a project with make structure")
        ("qmake", po::value<std::string>(), "create a project with qmake structure")
        ("bazel", po::value<std::string>(), "create a project with bazel structure")
        ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("cmake")) {
        project::create_cmake_project(vm["cmake"].as<std::string>());
    } else if (vm.count("makefile")) {
        project::create_makefile_project(vm["makefile"].as<std::string>()); 
    } else if (vm.count("qmake")) {
        project::create_qmake_project(vm["qmake"].as<std::string>());
    } else if (vm.count("bazel")) {
        project::create_bazel_project(vm["bazel"].as<std::string>());
    } else if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    } else {
        std::cout << desc << "\n";
        return 1;
    }

    return 0;
}

