cmake_minimum_required(VERSION 4.0)
project(ControleDeVoo C)

set(CMAKE_C_STANDARD 11)

include_directories(ControleDeVoo)

add_executable(ControleDeVoo
        ControleDeVoo/ArvoreBinaria.c
        ControleDeVoo/ArvoreBinaria.h
        ControleDeVoo/ControleDeVoo.c
        ControleDeVoo/ControleDeVoo.h
        ControleDeVoo/Main.c)
