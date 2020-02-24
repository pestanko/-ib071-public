cmake_minimum_required(VERSION 3.6)

# Project configuration
project(pb071-public)


# Executable
add_executable(${EXECUTABLE} ${SOURCES})

# Configure compiler warnings
if (CMAKE_C_COMPILER_ID MATCHES Clang OR ${CMAKE_C_COMPILER_ID} STREQUAL GNU)
  # using regular Clang, AppleClang or GCC
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -pedantic")
elseif (${CMAKE_C_COMPILER_ID} STREQUAL MSVC)
  # using Visual Studio C++
  target_compile_definitions(${EXECUTABLE} PRIVATE _CRT_SECURE_NO_DEPRECATE)
  set(CMAKE_CXX_FLAGS "/permissive- /W4 /EHsc")
endif()

if(MINGW)
    target_compile_definitions(${EXECUTABLE} PRIVATE __USE_MINGW_ANSI_STDIO=1)
endif()


add_subdirectory (cv02)
# add_subdirectory (cv03)
# add_subdirectory (cv04)
# add_subdirectory (cv05)
# add_subdirectory (cv06)
# add_subdirectory (cv07)
# add_subdirectory (cv08)
# add_subdirectory (cv09)
# add_subdirectory (cv10)

add_subdirectory(examples)
