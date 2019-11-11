cmake_minimum_required(VERSION 3.15)
project(alternative_vote_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(alternative_vote_system src/main.cpp src/votes/Vote.h src/votes/Vote.cpp)