project(aws-dummy)

cmake_minimum_required(VERSION 2.6)

set(aws-dummy_MAJOR_VERSION 0)
set(aws-dummy_MINOR_VERSION 1)
set(aws-dummy_PATCH_VERSION 0)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")

include_directories("${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")

find_package(Threads REQUIRED)
find_package(AWSSDK REQUIRED)

set(SERVICE_LIST ec2)
set(SERVICE ec2)

AWSSDK_DETERMINE_LIBS_TO_LINK(SERVICE OUTPUT)

set(LIBS
    ${THREADS_LIBRARY}
	${ZEROMQ_LIBRARY}
)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-Wall -O0")
set(CMAKE_CXX_FLAGS "-Wall -O0 -std=c++11 -pg -ggdb3")

add_subdirectory(src)

