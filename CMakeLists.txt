cmake_minimum_required(VERSION 3.30.0)
project(webcam_image_processing VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(webcam_image_processing webcam.cpp)


find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(webcam_image_processing ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})