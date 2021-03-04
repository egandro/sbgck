
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

project( displayimage )
cmake_minimum_required(VERSION 2.8)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( displayimage displayimage.cpp version.cpp main.cpp )
target_link_libraries( displayimage ${OpenCV_LIBS} )
