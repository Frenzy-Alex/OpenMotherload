cmake_minimum_required( VERSION 3.7 )

#########################################
#                OML                    #
#########################################

project( OML )

set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/Build/CMake/Modules" )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11 -Ofast" )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN/.'" )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binary/${CMAKE_BUILD_TYPE} )

include_directories( Include )
include_directories( Source )

include( Include/ACE/CMakeLists.txt )
include( Source/OML/CMakeLists.txt )

link_directories( ${PROJECT_SOURCE_DIR}/Library/${CMAKE_BUILD_TYPE} )

add_executable( OML ${ACE_IncludeFiles} ${OML_SourceFiles} )

target_link_libraries( OML ACE )

add_custom_command( TARGET OML POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/Library/${CMAKE_BUILD_TYPE} ${PROJECT_SOURCE_DIR}/Binary/${CMAKE_BUILD_TYPE} )

add_custom_command( TARGET OML POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/Data ${PROJECT_SOURCE_DIR}/Binary/${CMAKE_BUILD_TYPE}/Data )