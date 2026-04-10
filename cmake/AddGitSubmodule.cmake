function(add_git_submodule dir)
    find_package(Git REQUIRED)

    if(NOT EXISTS ${dir}/CmakeLists.txt)
        execute_process(COMMAND ${GIT_EXECUTABLE}
        submodlue update --init --recursive -- ${dir}
        WORKING_DIRECTORY ${PROJCECT_SOURCE_DIR})
    endif()
endfunction()