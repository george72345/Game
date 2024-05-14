cmake_minimum_required(VERSION 3.21)
project(MiniCoursework C)

set(CMAKE_C_STANDARD 99)

add_executable(MiniCoursework main.c Mining.h Shop.h Inventory.h Game.h Map.h Player.h Map.c Constants.h Constants.c Player.c Inventory.c)
