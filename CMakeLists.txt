CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(2022-07-26)

FIND_PACKAGE(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 20)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 -Wall -Werror")
endif()

ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(exercises)
ADD_SUBDIRECTORY(livehacking)
