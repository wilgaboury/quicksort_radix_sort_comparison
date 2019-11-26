cmake_minimum_required(VERSION 3.15)
project(Quicksort_Radix_Sort_Comparison C)

set(CMAKE_C_STANDARD 99)

#add_executable(Quicksort_Radix_Sort_Comparison src/main.c include/api.h src/api.c)

#this is for creating a shared library and installing it on computer
#I think it only works on linux
add_library(quickradix SHARED src/quickradix_api.c src/quicksorts.h src/utils.h src/utils.c src/tester.h src/types.h src/radixsorts.h)
set_target_properties(quickradix PROPERTIES
        PUBLIC_HEADER include/quickradix_api.h)
install(TARGETS quickradix
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})