
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

project( opencvtest )
cmake_minimum_required(VERSION 2.8)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} "../opencv/" )
file(GLOB SOURCE_FILES "../opencv/*.cpp" "../opencv/*.hpp")

add_executable( displayimage ${SOURCE_FILES} main.cpp )
target_link_libraries( displayimage ${OpenCV_LIBS} )
