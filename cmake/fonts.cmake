
function(copy_assets project)
    set(ORIG_FOLDER ${mvvm_SOURCE_DIR}/assets/fonts)
    set(DEST_FOLDER ${CMAKE_BINARY_DIR}/${project})
    add_custom_target(copy_fonts COMMAND ${CMAKE_COMMAND} -E copy_directory ${ORIG_FOLDER} ${DEST_FOLDER})
    file(COPY ${ORIG_FOLDER} DESTINATION ${DEST_FOLDER})
endfunction()