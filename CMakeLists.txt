cmake_minimum_required(VERSION 3.15)
project(Quicksort_Radix_Sort_Comparison C)

set(CMAKE_C_STANDARD 99)

#add_executable(Quicksort_Radix_Sort_Comparison src/main.c include/api.h src/api.c)

add_library(quickradix src/api.c)
set_target_properties(quickradix PROPERTIES PUBLIC_HEADER include/api.h)