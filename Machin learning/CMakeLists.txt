cmake_minimum_required(VERSION 3.30.0)
project(logistic_regression VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#add_executable(logistic_regression logistic_regression_main.cpp)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(logistic_regression ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
