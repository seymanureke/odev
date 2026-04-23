cmake_minimum_required(VERSION 3.20)
project(PriorityScheduler C)

set(CMAKE_C_STANDARD 11)
add_executable(PriorityScheduler
        main.c
        scheduler.c
        priority_queue.c
        rfc_parser.c)

