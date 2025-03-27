cmake_minimum_required(VERSION 3.18)

project(Serie11 LANGUAGES C)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed. Please make a build directory and run CMake from there.")
endif()

add_subdirectory(Exercice_cours_Queue)
add_subdirectory(Exercice_cours_Stack)

add_subdirectory(Exercice01)
add_subdirectory(Exercice02)
add_subdirectory(Exercice03)
add_subdirectory(Exercice04)

