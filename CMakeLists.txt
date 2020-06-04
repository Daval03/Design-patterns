cmake_minimum_required(VERSION 3.15)
project(Datos_2___2_0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable( Datos_2___2_0 mainVSPtr.cpp
        P1/GBCollector.h
        P1/GBCollector.cpp
        P1/HashTable.h
        P1/LinkedList.h
        P1/Set.h
        P1/Set.cpp
        P1/VSPointer.h
        )

find_package(Threads REQUIRED)
target_link_libraries( Datos_2___2_0 Threads::Threads)



