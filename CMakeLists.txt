cmake_minimum_required(VERSION 3.7)

project(EasyRPG_Editor VERSION 0.1.0 LANGUAGES CXX)

# Source Files
add_library(${PROJECT_NAME} STATIC
	src/core.cpp
	src/dialogcharapicker.cpp
	src/dialogdatabase.cpp
	src/dialogedit.cpp
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
	src/volumebutton.cpp
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
	src/tools/qgraphicspalettescene.cpp
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
	src/dialogcharapicker.ui
	src/dialogdatabase.ui
	src/dialogedit.ui
	src/dialogevent.ui
	src/dialogimportimage.ui
	src/dialogimportproject.ui
	src/dialognewproject.ui
	src/dialogmapproperties.ui
	src/dialogopenproject.ui
	src/dialogresourcemanager.ui
	src/dialogrtppath.ui
	src/dialogrungame.ui
	src/dialogsearch.ui
	src/dialogsplash.ui
	src/mainwindow.ui
	src/tools/qdbpageactors.ui
	src/tools/qdbpageattributes.ui
	src/tools/qdbpagebattleanimations.ui
	src/tools/qdbpagebattleanimations2.ui
	src/tools/qdbpagebattlescreen.ui
	src/tools/qdbpagechipset.ui
	src/tools/qdbpageclasses.ui
	src/tools/qdbpagecommonevents.ui
	src/tools/qdbpageenemies.ui
	src/tools/qdbpageenemygroups.ui
	src/tools/qdbpageherostatus.ui
	src/tools/qdbpageitems.ui
	src/tools/qdbpageskills.ui
	src/tools/qdbpagesystem.ui
	src/tools/qdbpagesystem2.ui
	src/tools/qdbpageterrain.ui
	src/tools/qdbpagevocabulary.ui
	src/tools/qeventpagewidget.ui
	src/commands/changeexperience.ui
	src/commands/changeitem.ui
	src/commands/changemoney.ui
	src/commands/changeparty.ui
	src/commands/facegraphics.ui
	src/commands/inputnumber.ui
	src/commands/showchoices.ui
	src/commands/showmessage.ui
	src/commands/switchoperations.ui
	src/commands/messageoptions.ui
	src/commands/variableoperations.ui
)

# C++17 is required
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Qt Magic
set_target_properties(${PROJECT_NAME} PROPERTIES
	AUTOMOC ON
	AUTOUIC ON
	AUTORCC ON
)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Extra FindModule files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(ConfigureWindows)

# Dependencies
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(liblcf REQUIRED)

# Libraries
target_link_libraries(${PROJECT_NAME}
	liblcf::liblcf
	Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia
)

# Executable
# Windows: Only open console for Debug builds
if(CMAKE_BUILD_TYPE MATCHES "Debug")
	add_executable(${PROJECT_NAME}_exe "src/main.cpp")
else()
	add_executable(${PROJECT_NAME}_exe WIN32 "src/main.cpp")
endif()

if(WIN32)
	set_target_properties(${PROJECT_NAME}_exe PROPERTIES OUTPUT_NAME "Editor")
else()
	set_target_properties(${PROJECT_NAME}_exe PROPERTIES OUTPUT_NAME "easyrpg-editor")
endif()

target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME})

# Add resources
target_sources(${PROJECT_NAME}_exe PRIVATE "src/Resources.qrc")

if(WIN32)
	target_sources(${PROJECT_NAME}_exe PRIVATE "src/Resources.rc")
endif()

# Installation
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}_exe
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
