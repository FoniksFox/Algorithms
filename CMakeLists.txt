cmake_minimum_required(VERSION 3.20)
project(Algorithms VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create interface library for header-only algorithms
add_library(algorithms INTERFACE)
target_include_directories(algorithms INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Enable testing
enable_testing()

# Compiler-specific options
if(MSVC)
    target_compile_options(algorithms INTERFACE /W4)
else()
    target_compile_options(algorithms INTERFACE -Wall -Wextra -pedantic)
endif()

# Doxygen integration
find_package(Doxygen)
if(DOXYGEN_FOUND)
    doxygen_add_docs(docs ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()

# Add test executables only if the test files exist
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/searching/test_linear_search.cpp")
    add_executable(test_linear_search tests/searching/test_linear_search.cpp)
    target_link_libraries(test_linear_search algorithms)
    add_test(NAME LinearSearchTest COMMAND test_linear_search)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/searching/test_binary_search.cpp")
    add_executable(test_binary_search tests/searching/test_binary_search.cpp)
    target_link_libraries(test_binary_search algorithms)
    add_test(NAME BinarySearchTest COMMAND test_binary_search)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/sorting/test_bubble_sort.cpp")
    add_executable(test_bubble_sort tests/sorting/test_bubble_sort.cpp)
    target_link_libraries(test_bubble_sort algorithms)
    add_test(NAME BubbleSortTest COMMAND test_bubble_sort)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/sorting/test_merge_sort.cpp")
    add_executable(test_merge_sort tests/sorting/test_merge_sort.cpp)
    target_link_libraries(test_merge_sort algorithms)
    add_test(NAME MergeSortTest COMMAND test_merge_sort)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/graph/test_depth_first_search.cpp")
    add_executable(test_depth_first_search tests/graph/test_depth_first_search.cpp)
    target_link_libraries(test_depth_first_search algorithms)
    add_test(NAME DepthFirstSearchTest COMMAND test_depth_first_search)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/graph/test_breadth_first_search.cpp")
    add_executable(test_breadth_first_search tests/graph/test_breadth_first_search.cpp)
    target_link_libraries(test_breadth_first_search algorithms)
    add_test(NAME BreadthFirstSearchTest COMMAND test_breadth_first_search)
endif()