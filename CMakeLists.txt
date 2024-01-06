cmake_minimum_required(VERSION 3.00)
project(HelicopterGaem)
add_executable(app main.cpp source/location.cpp source/user.cpp source/map.cpp source/enemy.cpp)
include_directories(include)