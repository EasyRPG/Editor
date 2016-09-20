cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project(EasyRPG_Editor CXX)

# Source Files
set(SRCS
	src/core.cpp
	src/dialogcharapicker.cpp
	src/dialogdatabase.cpp
	src/dialogevent.cpp
	src/dialogfacepicker.cpp
	src/dialogimportimage.cpp
	src/dialogimportproject.cpp
	src/dialogmapproperties.cpp
	src/dialognewproject.cpp
	src/dialogopenproject.cpp
	src/dialogresourcemanager.cpp
	src/dialogrtppath.cpp
	src/dialogrungame.cpp
	src/dialogsearch.cpp
	src/dialogsplash.cpp
	src/gamecharacter.cpp
	src/main.cpp
	src/mainwindow.cpp
	src/musicplayer.cpp
	src/stringizer.cpp
	src/tools/qactordelegate.cpp
	src/tools/qdbpageactors.cpp
	src/tools/qdbpageattributes.cpp
	src/tools/qdbpagebattleanimations2.cpp
	src/tools/qdbpagebattleanimations.cpp
	src/tools/qdbpagebattlescreen.cpp
	src/tools/qdbpagechipset.cpp
	src/tools/qdbpageclasses.cpp
	src/tools/qdbpagecommonevents.cpp
	src/tools/qdbpageenemies.cpp
	src/tools/qdbpageenemygroups.cpp
	src/tools/qdbpageherostatus.cpp
	src/tools/qdbpageitems.cpp
	src/tools/qdbpageskills.cpp
	src/tools/qdbpagesystem2.cpp
	src/tools/qdbpagesystem.cpp
	src/tools/qdbpageterrain.cpp
	src/tools/qdbpagevocabulary.cpp
	src/tools/qencounterdelegate.cpp
	src/tools/qeventpagewidget.cpp
	src/tools/qgraphicsbattleanimationitem.cpp
	src/tools/qgraphicscharaitem.cpp
	src/tools/qgraphicscurveitem.cpp
	src/tools/qgraphicsfaceitem.cpp
	src/tools/qgraphicsimportitem.cpp
	src/tools/qgraphicsmapscene.cpp
	src/tools/qgraphicspaletescene.cpp
	src/tools/qgraphicspickerscene.cpp
	src/tools/qundodraw.cpp
	src/tools/qundoevent.cpp
    src/commands/changeitem.cpp
    src/commands/changemoney.cpp
    src/commands/changeparty.cpp
    src/commands/changeexperience.cpp
    src/commands/facegraphics.cpp
    src/commands/inputnumber.cpp
    src/commands/messageoptions.cpp
    src/commands/showchoices.cpp
    src/commands/showmessage.cpp
    src/commands/switchoperations.cpp
    src/commands/variableoperations.cpp
	src/volumebutton.cpp
)

# Entry point and Resources
set(EXE_FILES
	src/main.cpp
	src/Resources.qrc
)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/tools")

# Qt Magic
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Extra FindModule files
list(APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/Modules")

# Dependencies
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(liblcf REQUIRED)

# Additional include directories
include_directories(${LIBLCF_INCLUDE_DIRS})

# Libraries
list(APPEND EASYRPG_EDITOR_LIBRARIES ${LIBLCF_LIBRARIES})
list(APPEND EASYRPG_EDITOR_LIBRARIES Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)
set(EASYRPG_EDITOR_LIBRARIES_ALL ${EASYRPG_EDITOR_LIBRARIES} "${PROJECT_NAME}_Static")

# Output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs)

# Add prefix (CMAKE_CURRENT_SOURCE_DIR) to list elements
FUNCTION(PREPEND var prefix)
	SET(listVar "")
	FOREACH(f ${ARGN})
		LIST(APPEND listVar "${prefix}/${f}")
	ENDFOREACH(f)
	SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

PREPEND(SRCS ${CMAKE_CURRENT_SOURCE_DIR} ${SRCS})
PREPEND(EXE_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${EXE_FILES})

# Static library
add_library(${PROJECT_NAME}_Static STATIC ${SRCS})
target_link_libraries(${PROJECT_NAME}_Static ${EASYRPG_EDITOR_LIBRARIES})

# Executable
add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${EXE_FILES})
target_link_libraries(${PROJECT_NAME} ${EASYRPG_EDITOR_LIBRARIES_ALL})
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION bin)
