cmake_minimum_required(VERSION 3.16)

project(time_project LANGUAGES CXX C)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")

add_executable(${PROJECT_NAME} time.cpp)

add_subdirectory(lib/sofa/20231011/c)
target_link_libraries(${PROJECT_NAME} PRIVATE sofa)

