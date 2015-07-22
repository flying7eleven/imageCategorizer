cmake_minimum_required( VERSION 3.2.3 )
project( "Image Categorizer" )

# setup the path where CMake should search for Find*.cmake scripts
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake" )

# be sure that C++11 is always enabled
add_definitions( "-std=c++11" )

# set some compiler options based on the used compiler
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_definitions( "-Weverything -Wno-reserved-id-macro -Wno-c++98-compat -Wno-c++98-compat-pedantic" )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	add_definitions( "-Wno-unknown-pragmas" )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
	add_definitions( "-Wno-unknown-pragmas" )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
endif()

# be sure that the source directory and the build directory are added to the include list
include_directories( AFTER ${CMAKE_CURRENT_BINARY_DIR} )
include_directories( AFTER ${CMAKE_CURRENT_SOURCE_DIR}/source )

# search for the boost packages we need here
find_package( Boost COMPONENTS system program_options filesystem regex REQUIRED )
include_directories( AFTER ${Boost_INCLUDE_DIR} )

# make a version file containing the current version from git.
include( GetGitRevisionDescription )
git_describe( VERSION "--tags" )

# parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1 "${VERSION}")
set( VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}" )

#
set( version_file "${CMAKE_CURRENT_BINARY_DIR}/VersionInformation.cxx" )
configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/source/VersionInformation.cxx.in ${version_file} )

#
add_executable( ic source/main.cxx ${version_file} )
target_link_libraries( ic ${Boost_LIBRARIES} )
