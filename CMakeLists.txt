cmake_minimum_required(VERSION 3.22)
project(BasketBall_League_Sim)

set(CMAKE_CXX_STANDARD 14)

add_executable(BasketBall_League_Sim sources/Game.cpp sources/Game.hpp sources/League.cpp sources/League.hpp sources/Schedule.cpp sources/Schedule.hpp sources/Team.cpp sources/Team.hpp sources/Round.hpp sources/Test.cpp)
