# Cmake required.
cmake_minimum_required (VERSION 2.6)
project (RayTracer)

# Version number
set (RayTracer_VERSION_MAJOR 0)
set (RayTracer_VERSION_MINOR 1)

# Set compiler and linker flags for gcc
set (GCC_COVERAGE_COMPILE_FLAGS 	"-std=c++11")
set (GCC_COVERAGE_LINK_FLAGS		"-static-libgcc -static-libstdc++")

set (CMAKE_CXX_FLAGS 				"${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS  		"${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Configure a header file to pass CMake settings
configure_file (
	"${PROJECT_SOURCE_DIR}/RayTracerConfig.h.in"
	"${PROJECT_BINARY_DIR}/RayTracerConfig.h"
)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw-3.1.1)

# Add the binary tree to the search path
include_directories(
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/lib/glfw-3.1.1/include"
	"${PROJECT_SOURCE_DIR}/lib/glew/include"
)

# Add the executable
add_executable(RayTracer
	main.cpp
	glutil.cpp
	io/fileloader.cpp
	buffers/VertexBuffer.cpp
	buffers/ElementBuffer.cpp
)

# Include additional libraries
target_link_libraries(RayTracer 
	glfw
	opengl32
	glu32
	gdi32
	${OPENGL_glu_LIBRARY}
	${GLFW_LIBRARIES}
	${PROJECT_SOURCE_DIR}/lib/glew/lib/libglew32.dll.a
)

# add the install targets
install (TARGETS RayTracer DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/RayTracerConfig.h"        
         DESTINATION include)
