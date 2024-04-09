project(ddsflow)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
INCLUDE(${BUILD_SCRIPT_ROOT}/cmake/common.cmake)
add_compile_options(-std=c++11)

add_subdirectory(proto)
include_directories(proto)

add_executable(dds_pub dds_pub/dds_pub.cpp)
target_link_libraries(dds_pub 
   dds
   dds_api
   dds_proto
   nanomsg
   pthread
   protobuf
)


add_executable(ddsflow dds2libflow/ddsflow.cpp dds2libflow/cJSON.c)
target_link_libraries(ddsflow 
   dds
   dds_api
   nanomsg
   flow
   pthread
)


add_executable(libflow_sub libflow_sub/libflow_sub.cpp)
target_link_libraries(libflow_sub 
   dds
   dds_api
   dds_proto
   nanomsg
   flow
   pthread
   glog
   protobuf
)