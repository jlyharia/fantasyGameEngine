
add_executable(${MAIN_TARGET}
        ${CMAKE_SOURCE_DIR}/src/MainGameLoop.cpp
        ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

add_custom_command(TARGET ${MAIN_TARGET}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:${MAIN_TARGET}>/resources)

#add_custom_command(TARGET ${MAIN_TARGET}
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/src/shaders $<TARGET_FILE_DIR:${MAIN_TARGET}>/shaders)
