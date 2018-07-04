cmake_minimum_required(VERSION 3.11)
project (dvs_core VERSION 0.0.1)

set(CORE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(CORE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include PARENT_SCOPE)
include_directories(${CORE_INCLUDE_DIRS})

file(GLOB CORE_SRC_FILES *.cc)
add_library(dvs_core ${CORE_SRC_FILES})

set_property(TARGET dvs_core PROPERTY CXX_STANDARD 17)
