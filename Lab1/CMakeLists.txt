cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

project(untitled)
add_executable(thor thor.cpp)
add_executable(model model.cpp)

# gmsh укажем явно (потому что он был просто распакован руками)
add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
        IMPORTED_LOCATION "/home/vladislav/gmsh-4.7.1-Linux64-sdk/lib/libgmsh.so"
        INTERFACE_INCLUDE_DIRECTORIES "/home/vladislav/gmsh-4.7.1-Linux64-sdk/include"
        )
set(GMSH_LIBRARY gmsh)

# Укажем библиотеки для линковки
target_link_libraries(thor ${GMSH_LIBRARY})
target_link_libraries(model ${GMSH_LIBRARY})
