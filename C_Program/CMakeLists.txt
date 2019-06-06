cmake_minimum_required(VERSION 3.9)
project(C_Program)

set(CMAKE_CXX_STANDARD 11)

add_executable(C_Program
        calculate_positions.c
        functions.h
        insert_observers.c
        insert_sightings.c
        main.c
        print_observers.c
        print_sightings.c
        shared.h)

target_link_libraries(C_Program m)