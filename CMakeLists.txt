cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 lab10/main.cpp
#        lab2/NumberList.cpp lab2/NumberList.h
#        lab2/Student.cpp lab2/Student.h
#        lab3/Canvas.cpp lab3/Canvas.h lab3/Math.cpp lab3/Math.h
#        lab4/Sort.cpp lab4/Sort.h
#        lab5/Number.cpp lab5/Number.h
#        lab8/lab8.cpp lab8/lab8.h lab8/input.txt
        lab10/Array.cpp lab10/Array.h lambda/lambda.cpp)


add_executable(lab9remake
        lab9remake/main.cpp
        lab9remake/Map.h
        )

add_executable(side
        side/main.cpp
        side/List.cpp side/List.h
        )

add_executable(lambda
        lambda/lambda.cpp
        )
add_executable(lab12
        lab12/Contact.h
        lab12/main.cpp lab12/Prieten.cpp lab12/Prieten.h lab12/Cunoscut.cpp lab12/Cunoscut.h lab12/Coleg.cpp lab12/Coleg.h lab12/Agenda.cpp lab12/Agenda.h)

add_executable(lab5
        lab5/Number.cpp
        lab5/Number.h
        lab5/main.cpp)

add_executable(lab6
        lab6/main.cpp
        lab6/Car.h lab6/Weather.h lab6/Dacia.cpp lab6/Dacia.h lab6/Circuit.cpp lab6/Circuit.h lab6/Mazda.cpp lab6/Mazda.h lab6/Toyota.cpp lab6/Toyota.h lab6/Mercedes.cpp lab6/Mercedes.h lab6/Ford.cpp lab6/Ford.h
        lab6/main.cpp)
