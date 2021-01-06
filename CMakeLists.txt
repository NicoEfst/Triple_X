cmake_minimum_required(VERSION 3.0.0)
project(Triple_X VERSION 1.0.0)

# Build debug executable
ADD_CUSTOM_TARGET(debug
COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
COMMENT "Creating the executable in the debug mode.")

# Put debug executable in Debug/ folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)

# Build release executable
ADD_CUSTOM_TARGET(release
COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
COMMENT "Creating the executable in the release mode.")

# Put release executable in Release folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
#set(CMAKE_BUILD_TYPE Debug)

include_directories(
source/
)

set(SOURCES
source/main.cpp
source/Level.cpp)

set(HEADERS
source/Level.h)

add_executable(Triple_X ${SOURCES} ${HEADERS})