
cmake_minimum_required(VERSION 2.8)

project( opencvtest )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
## set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
## set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} "../opencv/" )
file(GLOB SOURCE_FILES "../opencv/*.cpp" "../opencv/*.hpp")

# add_executable( main_json ${SOURCE_FILES} main_json.cpp )
# target_link_libraries( main_json ${OpenCV_LIBS} )

# add_executable( main_camera ${SOURCE_FILES} main_camera.cpp )
# target_link_libraries( main_camera ${OpenCV_LIBS} )

add_executable( main_assetmanager ${SOURCE_FILES} main_assetmanager.cpp )
target_link_libraries( main_assetmanager ${OpenCV_LIBS} )
