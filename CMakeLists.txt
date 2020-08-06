cmake_minimum_required( VERSION 3.2 )

message( STATUS "learning algorithms" )

if(WIN32)
    option(gtest_force_shared_crt "" TRUE)
endif(WIN32)

include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Configure.cmake" )

############################### GTest ###############################
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/gtest/googletest/include")

############################## Modules ##############################
include_directories(3rdparty/unapproved)
add_subdirectory(modules)