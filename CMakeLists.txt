project(cpp11_tutorial CXX C)
cmake_minimum_required(VERSION 2.8)

##-----------------------------------------------------------------------------
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wl,-O3,--sort-common,--no-as-needed -pthread")

# ## Compiler Flags
# if(UNIX)
#   #SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x") # come on guys... update your system ;)
#   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
   add_definitions(-Wall)
#   add_definitions(-Werror)
  add_definitions(-g)
#   add_definitions(-fPIC)
# endif()

# if(APPLE)
#   add_definitions(-Wno-missing-braces)
#   set(CUDA_HOST_COMPILER "/usr/local/bin/g++-4.9")
# endif(APPLE)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
##-----------------------------------------------------------------------------
## includes
add_subdirectory(src)
