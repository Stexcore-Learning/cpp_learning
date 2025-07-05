cmake_minimum_required(VERSION 3.16)
project(Examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ruta a los archivos de examples
file(GLOB SAMPLE_SOURCES CONFIGURE_DEPENDS "examples/*.cpp")

foreach(source_file ${SAMPLE_SOURCES})
    # Extraer el nombre del ejecutable a partir del nombre del archivo
    get_filename_component(sample_name ${source_file} NAME_WE)
    add_executable(${sample_name} ${source_file})
endforeach()