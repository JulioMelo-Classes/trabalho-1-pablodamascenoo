cmake_minimum_required(VERSION 3.5)
project(kenobet VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 14)
#--------------------------------

### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include )


# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp
add_executable( kenobet
                src/file.cpp
                src/main.cpp )

# The end
