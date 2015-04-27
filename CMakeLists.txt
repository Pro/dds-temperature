cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake)
project (dds_tests)

include (osmacros)

add_subdirectory(connext)
add_subdirectory(opensplice)
