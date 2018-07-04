cmake_minimum_required(VERSION 3.11)

enable_testing()

set(PROJECT_TEST_NAME dvs_test)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB TEST_SRC_FILES *.cc)

find_package (GTest)

include_directories(${CORE_INCLUDE_DIRS})

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
set_property(TARGET ${PROJECT_TEST_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_BOTH_LIBRARIES}
        dvs_core)

add_test(NAME ${PROJECT_TEST_NAME}
         COMMAND ${PROJECT_TEST_NAME} --gtest_color=yes)
