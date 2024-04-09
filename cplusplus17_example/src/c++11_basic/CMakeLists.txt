SET(MODULE_NAME c++11_basic)
SET(MODULE_NAME_PATH ${WORKSPACE_HOME}/c++11_basic)
set(CMAKE_CXX_STANDARD 17)


INCLUDE_DIRECTORIES(
  ${MODULE_NAME_PATH}
  ${MODULE_NAME_PATH}/test
)
LINK_DIRECTORIES()

SET(MODULE_HOME_PATH ${WORKSPACE_HOME}/c++11_basic)
SET(MODULE_GLOBAL_LINK_LIBS
 pthread
)

message(STATUS "====MODULE_GLOBAL_LINK_LIBS: ${MODULE_GLOBAL_LINK_LIBS}")

file(GLOB SRC_FILES "${MODULE_HOME_PATH}/*.hpp")

foreach(src ${SRC_FILES})
  get_filename_component(FILENAME ${src} NAME_WE)
  message(STATUS "File name: ${FILENAME}")
  SET(SRC_HEADER "${FILENAME}.h" )

  add_executable(${FILENAME}_node "${FILENAME}.hpp" "${MODULE_NAME_PATH}/test/${FILENAME}_test.cpp")

  target_link_libraries(${FILENAME}_node
    ${MODULE_GLOBAL_LINK_LIBS}
    # ${GLOBAL_LINKS_LIBS}
  )


  # target_compile_definitions(${FILENAME}_node PRIVATE MY_COMPILE_OPTIONS="-fno-elide-constructors")
  
endforeach()








