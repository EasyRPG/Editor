cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project(EasyRPG_Editor CXX)

# Qt Magic
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Extra FindModule files
list(APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/Modules")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs)

# Dependencies
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(liblcf REQUIRED)

# Set include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/tools")
include_directories(${LIBLCF_INCLUDE_DIR} ${LIBLCF_INCLUDE_DIRS})

# Set libraries
list(APPEND EASYRPG_EDITOR_LIBRARIES ${LIBLCF_LIBRARY} ${LIBLCF_LIBRARIES})
list(APPEND EASYRPG_EDITOR_LIBRARIES Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)
set(EASYRPG_EDITOR_LIBRARIES_ALL ${EASYRPG_EDITOR_LIBRARIES} "${PROJECT_NAME}_Static")

# entry point
set(MAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# static library
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/tools SRCS)
list(REMOVE_ITEM SRCS ${MAIN_FILE})

add_library(${PROJECT_NAME}_Static STATIC ${SRCS})
target_link_libraries(${PROJECT_NAME}_Static ${EASYRPG_EDITOR_LIBRARIES})

# executable
add_executable(${PROJECT_NAME} ${MAIN_FILE} src/Resources.qrc)
target_link_libraries(${PROJECT_NAME} ${EASYRPG_EDITOR_LIBRARIES_ALL})
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION bin)
