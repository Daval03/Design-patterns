cmake_minimum_required(VERSION 3.15)
project(Datos_2___2_0)

set(CMAKE_CXX_STANDARD 14)

#add_executable( Datos_2___2_0 mainAdapter.cpp
#        "patron de diseño observer/Subject"
#        "patron de diseño observer/Observer"
#        "patron de diseño observer/producto"
#        "patron de diseño observer/libreria"
#        "Adapter Pattern/EuropeanSocketInterface"
#        "Adapter Pattern/CRSocketInterface"
#        "Adapter Pattern/Socket"
#        "Adapter Pattern/Adapter"
#        "Adapter Pattern/Blender"
#        )

add_executable( Datos_2___2_0
#        "P1/LinkedList.h++"
        "P1/Set.h++"
        "P1/VSPointer.h++"
        "P1/GBCollector.h++"
        "P1/HashTable.h++"
        mainVSPtr.cpp
        )





