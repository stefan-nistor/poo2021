cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 main.cpp
        lab2/NumberList.cpp lab2/NumberList.h
        lab2/Student.cpp lab2/Student.h
        lab3/Canvas.cpp lab3/Canvas.h lab3/Math.cpp lab3/Math.h
        lab4/Sort.cpp lab4/Sort.h
        lab5/Number.cpp lab5/Number.h
        side/List.cpp side/List.h
        )
