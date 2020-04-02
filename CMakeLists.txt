cmake_minimum_required(VERSION 3.15)
project(Datos_2___2_0)

set(CMAKE_CXX_STANDARD 14)

add_executable( Datos_2___2_0 mainAdapter.cpp "patron de diseño observer/Subject.h++" "patron de diseño observer/Observer.h++" "patron de diseño observer/producto"
        "patron de diseño observer/libreria" "Adapter Pattern/EuropeanSocketInterface.h" "Adapter Pattern/Socket.cpp"
        "Adapter Pattern/Socket.h" "Adapter Pattern/CRSocketInterface.h" "Adapter Pattern/Adapter.cpp" "Adapter Pattern/Adapter.h" "Adapter Pattern/Blender.cpp" "Adapter Pattern/Blender.h")