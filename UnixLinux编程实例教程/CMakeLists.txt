cmake_minimum_required(VERSION 3.17)
project(unix_linux C)

set(CMAKE_C_STANDARD 11)
aux_source_directory(. DIR_SRCS)
add_executable(unix_linux ${DIR_SRCS} more02.h more02.c)