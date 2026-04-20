find_package(Doxygen)

if(DOXYGEN_FOUND)
   add_custom_target(Docs
                     ${DOXYGEN_EXECUTABLE}
                     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Docs)
endif()