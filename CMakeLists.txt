cmake_minimum_required(VERSION 3.21)
project(coursera)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp
                OrderBookEntry.cpp
        MerkelMain.h
        test.cpp
        CSVReader.cpp
        CSVReader.h
)
