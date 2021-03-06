#-------------------------------
# TUTORIAL CONFIGURATION
#-------------------------------

set(PROJECT_NAME "001-creating-opengl4-window")
project(${PROJECT_NAME}) # Project's name
cmake_minimum_required(VERSION 3.1) # Specify the minimum version for CMake
set (CMAKE_CXX_STANDARD 14) # Support C++14

file(GLOB TUTORIAL_001_SOURCE_FILES *.cpp)

set(COMMON_CLASSES_SOURCE_FILES
"${COMMON_CLASSES_ROOT}/OpenGLWindow.cpp"
)

set(COMMON_CLASSES_HEADER_FILES
"${COMMON_CLASSES_ROOT}/OpenGLWindow.h"
)

# Need to add header files as well in order for source grouping to work
set(ALL_SOURCE_FILES
${TUTORIAL_001_SOURCE_FILES}
${GLAD_SOURCE_FILES}
${GLAD_HEADER_FILES}
${COMMON_CLASSES_SOURCE_FILES}
${COMMON_CLASSES_HEADER_FILES}
)

# Setup include directories of the tutorial
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLAD_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})

# Add executable
add_executable(${PROJECT_NAME} ${ALL_SOURCE_FILES})

# Link this tutorial with GLFW static libraries
target_link_libraries(${PROJECT_NAME} ${GLFW_STATIC_LIBRARIES})

# On Unix systems, we will also need pthread library
if(UNIX)
	target_link_libraries(${PROJECT_NAME} pthread)
endif()

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${EXECUTABLE_OUTPUT_PATH}"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${EXECUTABLE_OUTPUT_PATH}"
)

if(IS_64BIT_BUILD)
	set_target_properties(${PROJECT_NAME}
		PROPERTIES
		OUTPUT_NAME_DEBUG "${PROJECT_NAME}_d64"
		OUTPUT_NAME_RELEASE "${PROJECT_NAME}64"
	)
else()
	set_target_properties(${PROJECT_NAME}
		PROPERTIES
		OUTPUT_NAME_DEBUG "${PROJECT_NAME}_d"
		OUTPUT_NAME_RELEASE ${PROJECT_NAME}
	)
endif()

#-------------------------------
# SOURCE GROUPING
#-------------------------------

source_group("Source Files\\common_classes" FILES ${COMMON_CLASSES_SOURCE_FILES})
source_group("Source Files\\glad" FILES ${GLAD_SOURCE_FILES})

source_group("Header Files\\common_classes" FILES ${COMMON_CLASSES_HEADER_FILES})
source_group("Header Files\\glad" FILES ${GLAD_HEADER_FILES})