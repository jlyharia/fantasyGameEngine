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
include_Boost()
message("-- CMAKE_SOURCE_DIR = " ${CMAKE_SOURCE_DIR})

set(HEADER_FILES
        ${HEADER_FILES}
        ${CMAKE_SOURCE_DIR}/src/gl_platform.hpp
        ${CMAKE_SOURCE_DIR}/src/shaderloader.hpp
        ${CMAKE_SOURCE_DIR}/src/file_system_utils.hpp
        ${CMAKE_SOURCE_DIR}/src/GLRenderContext.hpp
        ${CMAKE_SOURCE_DIR}/src/gl_handler.hpp
        ${CMAKE_SOURCE_DIR}/src/VertexShaderType.hpp
        ${CMAKE_SOURCE_DIR}/src/FragmentShaderType.hpp
        ${CMAKE_SOURCE_DIR}/src/shader_loader.hpp
        ${CMAKE_SOURCE_DIR}/src/ShaderType.hpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/EBO_sample_handler.hpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/BufferHandler.hpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/Simple_triangle_handler.hpp
        ${CMAKE_SOURCE_DIR}/src/model/Mesh.hpp
        ${CMAKE_SOURCE_DIR}/src/modelLoader/WavefrontLoader.hpp
        ${CMAKE_SOURCE_DIR}/src/VectorUtil.hpp
        ${CMAKE_SOURCE_DIR}/src/modelLoader/AssimpModelLoader.hpp
        ${CMAKE_SOURCE_DIR}/src/model/Vertex.hpp
        ${CMAKE_SOURCE_DIR}/src/model/MeshV2.cpp src/model/MeshV2.hpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/CubeHandler.hpp
        ${CMAKE_SOURCE_DIR}/src/DisplayManager.hpp)

set(SOURCE_FILES
        ${SOURCE_FILES}
        ${CMAKE_SOURCE_DIR}/src/gl_platform.cpp
        ${CMAKE_SOURCE_DIR}/src/shaderloader.cpp
        ${CMAKE_SOURCE_DIR}/src/gl_handler.cpp
        ${CMAKE_SOURCE_DIR}/src/shader_loader.cpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/EBO_sample_handler.cpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/Simple_triangle_handler.cpp
        ${CMAKE_SOURCE_DIR}/src/model/Mesh.cpp
        ${CMAKE_SOURCE_DIR}/src/modelLoader/WavefrontLoader.cpp
        ${CMAKE_SOURCE_DIR}/src/modelLoader/AssimpModelLoader.cpp
        ${CMAKE_SOURCE_DIR}/src/model/Vertex.cpp
        ${CMAKE_SOURCE_DIR}/src/bufferHandler/CubeHandler.cpp
        ${CMAKE_SOURCE_DIR}/src/DisplayManager.cpp)


message("-- Generator is " ${CMAKE_GENERATOR})
message("-- Cmake system Type: " ${CMAKE_SYSTEM_NAME})
message("-- Project binary dir: " ${PROJECT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
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
