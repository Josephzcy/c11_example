

SET(MODULE_DIR ${SUBMODULE_WORKSPACE_DIR}/subsrc)
MESSAGE(STATUS "MODULE_DIR:${MODULE_DIR}")

SET(SRC_SUFFIX .hpp)
file(GLOB_RECURSE MODULE_SRC_LIST ${MODULE_DIR}/*${SRC_SUFFIX})

include_directories(${MODULE_DIR})

SET(SUBMODULE_GLOBAL_LINK_LIBS
  pthread
)


foreach(src ${MODULE_SRC_LIST})

string(REGEX MATCH "subsrc.*" relative_path ${src})  
string(REGEX REPLACE "subsrc/" "" target_name ${relative_path})
string(REGEX MATCH "/.*" target_name ${target_name})
string(REGEX REPLACE "/" "" target_name ${target_name})
string(REGEX REPLACE ${SRC_SUFFIX} "" target_name ${target_name})
MESSAGE(STATUS "target_name: ${target_name}")

add_executable(${target_name}_node ${src} ${SUBMODULE_WORKSPACE_DIR}/code_test/${target_name}_test.cpp)

target_link_libraries(${target_name}_node
  ${SUBMODULE_GLOBAL_LINK_LIBS}
)

endforeach()
  











