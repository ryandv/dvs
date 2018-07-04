cmake_minimum_required (VERSION 3.11)
project (dvs VERSION 0.0.1)

enable_testing()

option (BUILD_TEST "Builds the dvs test suite" ON)

add_subdirectory (src)
include_directories(${CORE_INCLUDE_DIRS})

if (BUILD_TEST)
        add_subdirectory (test)
endif ()
