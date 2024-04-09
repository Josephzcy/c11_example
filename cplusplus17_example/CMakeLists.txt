CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(c++17_apply)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++17)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Release")

IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG")
ENDIF ()

# 设置C++编译器选项
IF (CMAKE_BUILD_TYPE MATCHES "(Debug|debug|DEBUG)")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=address")
    set(CMAKE_DEBUG_POSTFIX "d")
ENDIF ()

MESSAGE(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")     # mviz2_ros/src
MESSAGE(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}") # mviz2_ros/build/mviz
MESSAGE(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")     # mviz2_ros/build


SET(WORKSPACE_HOME ${CMAKE_SOURCE_DIR}/src)
MESSAGE(STATUS "WORKSPACE_HOME: ${WORKSPACE_HOME}")

SET(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)


SET(USE_FOR_AIPLORER TRUE)
IF (USE_FOR_AIPLORER)
  SET(AIPLORE_ROOT /home/wingboy/mviz_pilot/aiplorer) 
  # FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/aiplorer.deps/linux/deps.cmake DESTINATION ${CMAKE_BINARY_DIR}/)
  MESSAGE(STATUS "AIPLORE_ROOT: ${AIPLORE_ROOT}")
  INCLUDE(${CMAKE_SOURCE_DIR}/aiplorer.deps/linux/deps.cmake)
ENDIF()


SET(Third_Part_DIR ${CMAKE_SOURCE_DIR}/../3rdParty)

# SET(PB_PATH "${AIPLORE_ROOT}/msg/precompiler")
# SET(Mviz_Msg_DIR ${CMAKE_SOURCE_DIR}/../msg/rosmsgcomplier/)
# SET(FFMPEG_LIBS_DIR /usr/local/ffmpeg/lib)
# SET(FFMPEG_INCLUDE_DIRS /usr/local/ffmpeg/include)
# SET(AIPLORE_Pb_Msg_DIR ${AIPLORE_ROOT}/msg/precompiler)

# cmake -DMVIZ_J3=ON ..
# option(MVIZ_J3 "MVIZ_J3 Use Protobuf2" OFF)
# option(MVIZ_TDA4 "MVIZ_TDA4 Use Protobuf3" ON)

# # 如果选择使用protobuf2版本
# IF(MVIZ_J3)
#   add_definitions(-DMVIZ_J3)
#   MESSAGE(STATUS "MVIZ_J3 Using Protobuf2")
#   SET(PROTOBUF_INCLUDE_PATH ${AIPLORE_ROOT}/third_party/linux/protobuf_2.6.1/include)
#   SET(PROTOBUF_LIB_PATH ${AIPLORE_ROOT}/third_party/linux/protobuf_2.6.1/lib)


# # 如果选择使用protobuf3版本
# ELSEIF(MVIZ_TDA4)
#   add_definitions(-DMVIZ_TDA4)
#   message(STATUS "MVIZ_TDA4 Using Protobuf3")
#   SET(PROTOBUF_INCLUDE_PATH ${AIPLORE_ROOT}/third_party/linux/protobuf_3.12.3/include)
#   SET(PROTOBUF_LIB_PATH ${AIPLORE_ROOT}/third_party/linux/protobuf_3.12.3/lib)
# endif()

# todo:Mviz_Msg is *.h,include implement 
# aux_source_directory(${Mviz_Msg_DIR}mviz_apa_show/ Mviz_Msg_SRC)  
# aux_source_directory(${AIPLORE_Pb_Msg_DIR} AIPLORE_PROTO_CPP)
# list(REMOVE_ITEM AIPLORE_PROTO_CPP ${AIPLORE_Pb_Msg_DIR}/gnss.pb.cc)




# find_package(catkin REQUIRED COMPONENTS
#   cv_bridge
#   image_transport
#   roscpp
#   rosmsg
#   rospy
#   sensor_msgs
#   std_msgs
#   tf
# )

# ## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
# find_package(OpenCV REQUIRED)
# find_package(Eigen3 REQUIRED)

# find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
# SET(QT_LIBRARIES Qt5::Widgets)
# add_definitions(-DQT_NO_KEYWORDS)


# catkin_package(
# #  INCLUDE_DIRS include
# #  LIBRARIES mviz
#  CATKIN_DEPENDS cv_bridge image_transport roscpp rosmsg rospy sensor_msgs std_msgs tf #libqt5-dev qt_build
# #  DEPENDS system_lib
# )

# ###########
# ## Build ##
# ###########
# include_directories(
#   ${WORKSPACE_HOME}/include
#   ${WORKSPACE_HOME}/core/
#   ${WORKSPACE_HOME}/utils
#   ${WORKSPACE_HOME}/utils/bev_odom2pix
#   ${WORKSPACE_HOME}/common/platform
#   ${WORKSPACE_HOME}/tools


#   ${catkin_INCLUDE_DIRS}
#   ${OpenCV_INCLUDE_DIRS}
#   ${Boost_INCLUDE_DIRS}
#   ${FFMPEG_INCLUDE_DIRS}
#   ${EIGEN3_INCLUDE_DIRS}
#   ${Third_Part_DIR}/decode_video/include/
#   ${Mviz_Msg_DIR}
#   ${PROTOBUF_INCLUDE_PATH}
#   ${AIPLORE_Pb_Msg_DIR}

# )
# link_directories(
#   ${Third_Part_DIR}/decode_video/lib/
#   ${FFMPEG_LIBS_DIR}
#   ${PROTOBUF_LIB_PATH}
# )


# # unsed
# SET(GLOBAL_LINK_LIBS
#   ${catkin_LIBRARIES}
#   ${OpenCV_LIBRARIES}
#   pthread
#   flow
#   glog
#   ${Boost_LIBRARIES}
#   protobuf
#   decode_video
#   yaml-cpp
#   avcodec avformat avutil swresample swscale swscale avfilter
#   nanomsg
# )

# # ros_msg_src and pb_msg_src compile library
# ADD_LIBRARY(pb_msg SHARED  ${AIPLORE_PROTO_CPP} )


# 根据src下的hpp生成对应的测试代码

SET(SRC_HOME_PATH ${WORKSPACE_HOME}) 
FILE(GLOB MODULE_DIRECTORIES ${SRC_HOME_PATH}/*)

foreach(DIR ${MODULE_DIRECTORIES})
  IF(IS_DIRECTORY ${DIR})
    IF (NOT "${DIR}" MATCHES "componets")
      MESSAGE(STATUS "MODULE_DIRECTORIES : ${DIR}")   
      continue()
    ENDIF()
    MESSAGE(STATUS "MATCHES MODULE_DIRECTORIES: ${DIR}")     
    ADD_SUBDIRECTORY(${DIR})
  ENDIF()
endforeach()