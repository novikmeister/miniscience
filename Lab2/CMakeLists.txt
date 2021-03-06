cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(cubic2d cubic2d.cpp)
add_executable(tetr3d tetr3d.cpp)
add_executable(cubic3d cubic3d.cpp)
add_executable(model model.cpp)

set(VTK_DIR "/home/vladislav/VTK-7.1.1/build")
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# gmsh укажем явно по кусочкам (потому что он был просто распакован руками)
add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
        IMPORTED_LOCATION "/home/vladislav/gmsh-4.7.1-Linux64-sdk/lib/libgmsh.so"
        INTERFACE_INCLUDE_DIRECTORIES "/home/vladislav/gmsh-4.7.1-Linux64-sdk/include"
        )
set(GMSH_LIBRARY gmsh)

# если бы gmsh был поставлен прилично, то можно было бы примерно вот так
#find_package(gmsh REQUIRED)
#include_directories(${GMSH_INCLUDE_DIR})
#target_link_libraries(tetr3d ${GMSH_LIBRARY})

# Укажем библиотеки для линковки
# ... тут только VTK
target_link_libraries(cubic2d ${VTK_LIBRARIES})
target_link_libraries(cubic3d ${VTK_LIBRARIES})

# ... а тут ещё и gmsh
target_link_libraries(tetr3d ${VTK_LIBRARIES})
target_link_libraries(tetr3d ${GMSH_LIBRARY})
target_link_libraries(model ${VTK_LIBRARIES})
target_link_libraries(model ${GMSH_LIBRARY})
