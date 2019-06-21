cmake_minimum_required(VERSION 3.13)
project(Sokoban)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sokoban console/main.cpp console/ConsoleBoardUtil.cpp console/ConsoleBoardUtil.h Session.cpp Session.h Game.cpp Game.h Icon.h Operation.h Position.cpp Position.h Map.cpp Map.h Player.cpp Player.h console/autoTest.cpp)