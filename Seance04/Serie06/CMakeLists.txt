cmake_minimum_required(VERSION 3.18)

project(Serie06 LANGUAGES C)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed. Please make a build directory and run CMake from there.")
endif()

add_subdirectory(Exercice01)
add_subdirectory(Exercice02)
add_subdirectory(Exercice03)
add_subdirectory(Exercice03bis)
add_subdirectory(Exercice04)
add_subdirectory(Exercice05)
add_subdirectory(Exercice06)
add_subdirectory(Exercice07)
add_subdirectory(Exercice08)
add_subdirectory(Exercice09)
add_subdirectory(Exercice10)
add_subdirectory(Exercice11)
add_subdirectory(Exercice12)
add_subdirectory(Exercice13)
add_subdirectory(Exercice14)
add_subdirectory(Exercice15)
add_subdirectory(Exercice16)
add_subdirectory(Exercice17)
add_subdirectory(Exercice18)
add_subdirectory(Exercice19)
add_subdirectory(Exercice20)



