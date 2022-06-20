cmake_minimum_required(VERSION 3.22)
project(Proiectutul)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proiectutul
        ADMIN.txt
        "Clienti ID.txt"
        main.cpp
        obiecte.txt
        PROIECT.cpp
        PROIECT.h)
