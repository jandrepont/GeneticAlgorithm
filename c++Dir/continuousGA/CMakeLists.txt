cmake_minimum_required(VERSION 3.5)
project(continuousGA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -lcurl")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -lcurl")

set(SOURCE_FILES
        Chromosome.cpp
        Chromosome.h
        function.cpp
        function.h
        GenAlg.cpp
        GenAlg.h
        main.cpp
        #Poptest.cpp
        Population.cpp
        Population.h)

add_executable(continuousGA ${SOURCE_FILES})