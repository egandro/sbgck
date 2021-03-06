
## https://www.npmjs.com/package/cmake-js
# https://github.com/cmake-js/cmake-js/wiki/TUTORIAL-01-Creating-a-native-module-by-using-CMake.js-and-NAN
# https://stackoverflow.com/questions/38006584/how-to-clone-and-integrate-external-from-git-cmake-project-into-local-one
cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

# Name of the project (will be the name of the plugin)
project(glue)

include(FindGit)
find_package(Git)

if (NOT Git_FOUND)
	message(FATAL_ERROR "Git not found!")
endif ()

include(ExternalProject)

# opencv
find_package(OpenCV REQUIRED)

if(UNIX AND NOT APPLE)
    # on Linux
    set(SYSTEM_LIBRARIES stdc++fs asound) # required for filesystem streams on g++
endif()

IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # idea from here - https://stackoverflow.com/questions/15100351/changing-cmake-cxx-flags-in-project
    SET ( CMAKE_CXX_FLAGS "-Wno-psabi" )
ENDIF()

if(DEFINED EXTERNAL_INSTALL_LOCATION)
    set(EXTERNAL_INSTALL_LOCATION ${EXTERNAL_INSTALL_LOCATION})
else()
    set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
endif()
#message("using EXTERNAL_INSTALL_LOCATION: ${EXTERNAL_INSTALL_LOCATION}")

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

#ExternalProject_Add(sbgck_core_lib
#    GIT_REPOSITORY https://github.com/egandro/sbgck-core
#    CMAKE_ARGS -DEXTERNAL_INSTALL_LOCATION=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
#)

ExternalProject_Add(sbgck_core_lib
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/sbgck-core
    CMAKE_ARGS -DEXTERNAL_INSTALL_LOCATION=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

# Build a shared library named after the project from the files in `cpp/`
file(GLOB SOURCE_FILES "cpp/*.cpp" "cpp/*.hpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

# needed for the logger
add_definitions(-DNODE_MODULE_NAME="${CMAKE_PROJECT_NAME}")

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Essential include files to build a node addon,
# You should add this line in every CMake.js based project
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC} ${OpenCV_INCLUDE_DIRS} "cpp/")

# Essential library files to link to a node addon
# You should add this line in every CMake.js based project
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} ${OpenCV_LIBS} sbgck_core sbgck_opencv soloud ${SYSTEM_LIBRARIES})

add_dependencies(${PROJECT_NAME} sbgck_core_lib)
