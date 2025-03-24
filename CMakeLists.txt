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
	if(CMAKE_C_COMPILER_FRONTEND_VARIANT MATCHES "MSVC")
		set(COMPILER_VARIANT "clang-cl")
	else()
		set(COMPILER_VARIANT "clang")
	endif()
	set(COMPILER_FULL_NAME "${COMPILER_VARIANT}-${CMAKE_C_COMPILER_VERSION}")
else()
	set(COMPILER_FULL_NAME "${CMAKE_C_COMPILER_ID}-${CMAKE_C_COMPILER_VERSION}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG			"${CMAKE_BINARY_DIR}/bin/${COMPILER_FULL_NAME}-${ARCHITECTURE}_Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE			"${CMAKE_BINARY_DIR}/bin/${COMPILER_FULL_NAME}-${ARCHITECTURE}_Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO	"${CMAKE_BINARY_DIR}/bin/${COMPILER_FULL_NAME}-${ARCHITECTURE}_RelWithDebInfo")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL		"${CMAKE_BINARY_DIR}/bin/${COMPILER_FULL_NAME}-${ARCHITECTURE}_MinSizeRel")

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
	add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
endif()

# C
set(MSVC_C_COMPILE_FLAGS
	/W4						# High warning level
	/WX						# Treat warnings as errors
	/Wall					# Enable all warnings
	/analyze				# Enable code analysis
	/permissive-			# Strict standards conformance

	/wd4710					# Function not inlined
	/wd4711					# Function not inlined
	/wd4820					# Padding added
	/wd5045					# Spectre mitigation
	/wd6054					# String may not be zero-terminated
)

set(CLANG_C_COMPILE_FLAGS
	-Wall					# Basic warnings
	-Wextra					# Extra warnings
	-Werror					# Treat warnings as errors
	-Weverything			# Enable all warnings
	-Wnull-dereference		# Null pointer dereference

	-Wno-unsafe-buffer-usage
	-Wno-covered-switch-default
	-Wno-disabled-macro-expansion

)

set(GCC_C_COMPILE_FLAGS
	-Wall					# Basic warnings
	-Wextra					# Extra warnings
	-Werror					# Treat warnings as errors
	-pedantic				# Strict ISO C
	-Wnull-dereference		# Null pointer dereference
	-Wformat-security		# Format string security
	-Warray-bounds			# Array bounds checking
	-Wstack-protector		# Stack protection
	-fstack-protector-all	# Enable stack protection (GCC specific)

	-Wno-covered-switch-default
)

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
	if(CMAKE_C_COMPILER_FRONTEND_VARIANT MATCHES "MSVC")
		message(STATUS "C Compiler: Clang ${CMAKE_C_COMPILER_VERSION} with MSVC CLI")
		set(C_COMPILE_FLAGS ${CLANG_C_COMPILE_FLAGS})
	else()
		message(STATUS "C Compiler: Clang ${CMAKE_C_COMPILER_VERSION} with GNU CLI")
		set(C_COMPILE_FLAGS
			${CLANG_C_COMPILE_FLAGS}
			-pedantic	# Strict ISO C
		)
	endif()
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
	message(STATUS "C Compiler: GCC ${CMAKE_C_COMPILER_VERSION}")
	set(C_COMPILE_FLAGS ${GCC_C_COMPILE_FLAGS})
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
	message(STATUS "C Compiler: MSVC ${CMAKE_C_COMPILER_VERSION}")
	set(C_COMPILE_FLAGS ${MSVC_C_COMPILE_FLAGS})
endif()
message(STATUS "C Compiler flags: ${C_COMPILE_FLAGS}")

#C++
set(MSVC_CXX_COMPILE_FLAGS
	${MSVC_C_COMPILE_FLAGS}
	/std:c++20
	/EHsc				# Standard C++ exception handling
	/Zc:__cplusplus		# Enable correct __cplusplus macro
)

set(CLANG_CXX_COMPILE_FLAGS
	${CLANG_C_COMPILE_FLAGS}
	-std=c++20
	-Woverloaded-virtual	# Virtual function issues
	-Wnon-virtual-dtor		# Missing virtual destructor
	-Wold-style-cast		# C-style cast in C++
)

set(GCC_CXX_COMPILE_FLAGS
	${GCC_C_COMPILE_FLAGS}
	-std=c++20
	-Weffc++			# Effective C++ warnings
	-Wold-style-cast	# C-style cast in C++
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT MATCHES "MSVC")
		message(STATUS "C++ Compiler: Clang ${CMAKE_CXX_COMPILER_VERSION} with MSVC CLI")
		set(CXX_COMPILE_FLAGS ${MSVC_CXX_COMPILE_FLAGS})
	else()
		message(STATUS "C++ Compiler: Clang ${CMAKE_CXX_COMPILER_VERSION} with GNU CLI")
		set(CXX_COMPILE_FLAGS ${CLANG_CXX_COMPILE_FLAGS})
	endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	message(STATUS "C++ Compiler: GCC ${CMAKE_CXX_COMPILER_VERSION}")
	set(CXX_COMPILE_FLAGS ${GCC_CXX_COMPILE_FLAGS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	message(STATUS "C++ Compiler: MSVC ${CMAKE_CXX_COMPILER_VERSION}")
	set(CXX_COMPILE_FLAGS ${MSVC_CXX_COMPILE_FLAGS})
endif()
message(STATUS "C++ Compiler flags: ${CXX_COMPILE_FLAGS}")

add_compile_options(
	"$<$<COMPILE_LANGUAGE:C>:${C_COMPILE_FLAGS}>"
	"$<$<COMPILE_LANGUAGE:CXX>:${CXX_COMPILE_FLAGS}>"
)

#add_subdirectory(Seance01)
#add_subdirectory(Seance02)
#add_subdirectory(Seance03)
#add_subdirectory(Seance04)
#add_subdirectory(Seance05)
#add_subdirectory(Seance06)
#add_subdirectory(Seance07)
#add_subdirectory(Seance08)
add_subdirectory(Seance09)