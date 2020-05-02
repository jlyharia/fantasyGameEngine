cmake_minimum_required(VERSION 3.16)

project(FantasyGameEngine)

# Set main target name
SET(MAIN_TARGET ${PROJECT_NAME})
include(${PROJECT_SOURCE_DIR}/cmake/macro.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/LibFindMacros.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules)
set(CMAKE_DEFAULT_MODULE_LIST /usr/local/share/cmake/Modules)
# Enable debug symbols by default
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif ()

# include library
include_OpenGL()
include_module(GLEW)
include_module(GLM)
include_module(GLFW)
include_module(ASSIMP)
#include_Boost()
message("-- CMAKE_SOURCE_DIR = " ${CMAKE_SOURCE_DIR})

set(HEADER_FILES
        ${HEADER_FILES}
        ${CMAKE_SOURCE_DIR}/src/model/Mesh.hpp
        ${CMAKE_SOURCE_DIR}/src/VectorUtil.hpp
        ${CMAKE_SOURCE_DIR}/src/DisplayManager.hpp
        ${CMAKE_SOURCE_DIR}/src/Loader.hpp
        ${CMAKE_SOURCE_DIR}/src/models/RawModel.hpp
        ${CMAKE_SOURCE_DIR}/src/Renderer.hpp
        ${CMAKE_SOURCE_DIR}/src/ShaderProgram.hpp
        ${CMAKE_SOURCE_DIR}/src/StaticShader.hpp
        ${CMAKE_SOURCE_DIR}/src/ImageLoader.hpp
        ${CMAKE_SOURCE_DIR}/src/texture/ModelTexture.hpp
        ${CMAKE_SOURCE_DIR}/src/models/TexturedModel.hpp
        ${CMAKE_SOURCE_DIR}/src/stb_image.h
        ${CMAKE_SOURCE_DIR}/src/Image.hpp
#        ${CMAKE_SOURCE_DIR}/src/glad/glad.h
#        ${CMAKE_SOURCE_DIR}/src/glad/khrplatform.h
        ${CMAKE_SOURCE_DIR}/src/entities/Camera.hpp
        ${CMAKE_SOURCE_DIR}/src/toolbox/Maths.hpp
        ${CMAKE_SOURCE_DIR}/src/entities/Entity.hpp
        ${CMAKE_SOURCE_DIR}/src/toolbox/DebugHelper.hpp
        ${CMAKE_SOURCE_DIR}/src/model/Model.hpp
        )

set(SOURCE_FILES
        ${SOURCE_FILES}
        ${CMAKE_SOURCE_DIR}/src/DisplayManager.cpp
        ${CMAKE_SOURCE_DIR}/src/Loader.cpp
        ${CMAKE_SOURCE_DIR}/src/models/RawModel.cpp
        ${CMAKE_SOURCE_DIR}/src/Renderer.cpp
        ${CMAKE_SOURCE_DIR}/src/ShaderProgram.cpp
        ${CMAKE_SOURCE_DIR}/src/StaticShader.cpp
        ${CMAKE_SOURCE_DIR}/src/texture/ModelTexture.cpp
        ${CMAKE_SOURCE_DIR}/src/models/TexturedModel.cpp
        ${CMAKE_SOURCE_DIR}/src/ImageLoader.cpp
        ${CMAKE_SOURCE_DIR}/src/Image.cpp
#        ${CMAKE_SOURCE_DIR}/src/glad/glad.c
        ${CMAKE_SOURCE_DIR}/src/entities/Camera.cpp
        ${CMAKE_SOURCE_DIR}/src/toolbox/Maths.cpp
        ${CMAKE_SOURCE_DIR}/src/entities/Entity.cpp
        ${CMAKE_SOURCE_DIR}/src/toolbox/DebugHelper.cpp
        )


message("-- Generator is " ${CMAKE_GENERATOR})
message("-- Cmake system Type: " ${CMAKE_SYSTEM_NAME})
message("-- Project binary dir: " ${PROJECT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE on)  # make debug flag
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_DEBUG "-v")

message("-- HEADER_FILES: " ${HEADER_FILES})
message("-- SOURCE_FILES: " ${SOURCE_FILES})
message("-- Libraries: " ${LIBRARIES})
message("-- CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
message("-- CMAKE_COMMAND " ${CMAKE_COMMAND})
# Copy resource files, shaders files into execute directory

add_library(myLib ${SOURCE_FILES} ${HEADER_FILES})

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

