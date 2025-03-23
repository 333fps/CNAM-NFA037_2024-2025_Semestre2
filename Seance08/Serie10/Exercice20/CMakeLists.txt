cmake_minimum_required(VERSION 3.18)

project(CNAM_NFA037_SERIE10_EXERCICE20 LANGUAGES C)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed. Please make a build directory and run CMake from there.")
endif()

add_executable(${PROJECT_NAME} main.c)

if(DEFINED C_COMPILE_FLAGS)
	target_compile_options(${PROJECT_NAME} PRIVATE ${C_COMPILE_FLAGS})
else()
	message(STATUS "No custom flags defined for ${PROJECT_NAME}")
endif()

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${CMAKE_CURRENT_SOURCE_DIR}/Exercice20.txt"
		"$<TARGET_FILE_DIR:${PROJECT_NAME}>/Exercice20.txt"
	COMMENT "Copying Fichier1.txt to executable directory"
)
