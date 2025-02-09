cmake_minimum_required(VERSION 3.18)

project(CNAM_NFA037 LANGUAGES C CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed. Please make a build directory and run CMake from there.")
endif()

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(ARCHITECTURE "x64")
else()
	set(ARCHITECTURE "x86")
endif()

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
	set(COMPILER_NAME "Clang")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
	set(COMPILER_NAME "GCC")
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
	set(COMPILER_NAME "MSVC")
else()
	set(COMPILER_NAME ${CMAKE_C_COMPILER_ID})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/${COMPILER_NAME}-${ARCHITECTURE}_Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/${COMPILER_NAME}-${ARCHITECTURE}_Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin/${COMPILER_NAME}-${ARCHITECTURE}_RelWithDebInfo")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin/${COMPILER_NAME}-${ARCHITECTURE}_MinSizeRel")

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
	add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
endif()

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
	message(STATUS "Clang")
	set(C_COMPILE_FLAGS
		-Weverything
		-Werror
	)
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
	message(STATUS "GCC/MinGW")
	set(C_COMPILE_FLAGS
		-Wall
		-Wextra
		-Werror
		-pedantic
	)
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
	message(STATUS "MSVC")
	set(C_COMPILE_FLAGS
		/W4				# High warning level
		/WX				# Treat warnings as errors
		/Wall			# Enable all warnings
		/analyze		# Enable code analysis
		/permissive-	# Strict standards conformance
		/we4242			# Conversion - possible loss of data
		/we4244			# Conversion - possible loss of data
		/we4254			# Bit field type conversion
		/we4287			# Unsigned/negative constant mismatch
		/we4296			# Expression is always false/true
		/we4365			# Signed/unsigned mismatch
		/we4388			# Signed/unsigned comparison
		/we4389			# Signed/unsigned mismatch
		/we4706			# Assignment within conditional
		/we4711			# Function selected for automatic inline expansion
		/we4774			# Format string expected
		/we4800			# Force value to bool
		/we4826			# Conversion sign-extended
		/we4928			# Illegal copy-initialization

		/wd4710
		/wd5045
		/wd6054
	)
else()
	message(STATUS "Using default compiler settings for ${CMAKE_C_COMPILER_ID}.")
	set(C_COMPILE_FLAGS ${CMAKE_C_FLAGS})
endif()

add_subdirectory(Seance01)
add_subdirectory(Seance02)
