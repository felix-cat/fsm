cmake_minimum_required(VERSION 3.0)

## project
SET (this_target FSM_Test)
PROJECT(${this_target})

## compiler settings
if (MSVC)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}   /DDEBUG /D_LIB  /D_CRT_SECURE_NO_WARNINGS")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /DNDEBUG /D_LIB /D_CRT_SECURE_NO_WARNINGS")
	
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif(MSVC)

if(CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_C_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_definitions(-std=gnu++0x)
endif()

# include directories
INCLUDE_DIRECTORIES(
  )

#files
SET(${this_target}_SOURCE_FILES)
SET(${this_target}_HEADER_FILES)

## sources files
LIST (APPEND ${this_target}_SOURCE_FILES
	test.cpp
	NumbersGenerator.cpp
    )

## header files
LIST (APPEND ${this_target}_HEADER_FILES
	fsm.h
	NumbersGenerator.h
    )

## target
add_executable(${this_target} ${${this_target}_SOURCE_FILES} ${${this_target}_HEADER_FILES})
