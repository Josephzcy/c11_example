cmake_minimum_required(VERSION 3.5)
project(os_study)

# add_compile_definitions(-std=c++11)
SET(WORESPACE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
MESSAGE(STATUS "WORESPACE_DIR:${WORESPACE_DIR}")

SET(INCLUDE_DIR ${WORESPACE_DIR}/include)
SET(SRC_SUFFIX .hpp)

file(GLOB_RECURSE MODULE_SRC_LIST ${WORESPACE_DIR}/src/*${SRC_SUFFIX})

include_directories(${INCLUDE_DIR})
include_directories(${WORESPACE_DIR}/src)

SET(GLOBAL_LINK_LIBS
  pthread
)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${WORESPACE_DIR}/build/archive)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${WORESPACE_DIR}/build/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${WORESPACE_DIR}/build/runtime)


foreach(src ${MODULE_SRC_LIST})
  string(REGEX MATCH "src.*" relative_path ${src})  
  string(REGEX REPLACE "src/" "" target_name ${relative_path})
  string(REGEX REPLACE ${SRC_SUFFIX} "" target_name ${target_name})
  MESSAGE(STATUS "target_name: ${target_name}")

  add_executable(${target_name}_node ${src} ${WORESPACE_DIR}/code_test/${target_name}_test.cpp)

  target_link_libraries(${target_name}_node
    ${GLOBAL_LINK_LIBS}
  )
endforeach()
  











