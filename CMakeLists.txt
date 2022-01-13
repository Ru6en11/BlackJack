cmake_minimum_required(VERSION 3.20)
project(BlackJack2_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlackJack2_0 main.cpp stack.h deck.h shoe.h player.h diler.h logics.h interface.h)
