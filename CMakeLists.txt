cmake_minimum_required (VERSION 3.6)

project (TYRANNO)
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 1)


set_property (GLOBAL PROPERTY GLOBAL_CPP_VERSION 14)

add_subdirectory(src)
add_subdirectory(test)

