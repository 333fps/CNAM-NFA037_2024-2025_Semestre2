cmake_minimum_required(VERSION 3.18)

project(Serie01 LANGUAGES C)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed. Please make a build directory and run CMake from there.")
endif()

add_subdirectory(Exercice01)
add_subdirectory(Exercice02)
