
# SET(CORE_HOME_PATH ${MVIZ_HOME}/core)

# FILE(GLOB MODULE_DIRECTORIES ${CORE_HOME_PATH}/*)


# foreach(DIR ${MODULE_DIRECTORIES})
#   IF(IS_DIRECTORY ${DIR})
#   ADD_SUBDIRECTORY(${DIR})
#   ENDIF()
# endforeach()

SET(MODULE_NAME componets)

SET(MODULE_HOME_PATH ${WORKSPACE_HOME}/${MODULE_NAME})
set(CMAKE_CXX_STANDARD 17)


INCLUDE_DIRECTORIES(
  ${MODULE_HOME_PATH}
  ${MODULE_HOME_PATH}/test
  ${WORKSPACE_HOME}/../
)
LINK_DIRECTORIES()



file(GLOB SRC_FILES "${MODULE_HOME_PATH}/*.hpp")

foreach(src ${SRC_FILES})
  get_filename_component(FILENAME ${src} NAME_WE)
  message(STATUS "File name: ${FILENAME}")
  SET(SRC_HEADER "${FILENAME}.h" )

  add_executable(${FILENAME}_node "${FILENAME}.hpp" "${MODULE_HOME_PATH}/test/${FILENAME}_test.cpp")
  # add_library(${FILENAME} SHARED "${FILENAME}.cpp" )

  target_link_libraries(${FILENAME}_node
    # ${MODULE_NAME_GLOBAL_LINK_LIBS}
    # ${GLOBAL_LINKS_LIBS}
  )

endforeach()








