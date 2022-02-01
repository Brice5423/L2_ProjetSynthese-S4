cmake_minimum_required(VERSION 3.21)
project(Projet_ProjetSynthese_S4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_ProjetSynthese_S4
        src/main.c src/algo.c include/algo.h src/geometry.c include/geometry.h src/heap.c include/heap.h
        src/list.c include/list.h src/sort.c include/sort.h src/tree.c include/tree.h src/util.c include/util.h)
