cmake_minimum_required(VERSION 3.7)

project(EasyRPG_Editor VERSION 0.1.0 LANGUAGES CXX)

# Source Files
add_library(EasyRPG_Editor STATIC
	src/core.cpp
	src/core.h
	src/gamecharacter.cpp
	src/gamecharacter.h
	src/main.cpp
	src/stringizer.cpp
	src/stringizer.h
	src/ui/commands/allcommands.h
	src/ui/commands/changeexperience.cpp
	src/ui/commands/changeexperience.h
	src/ui/commands/changeexperience.ui
	src/ui/commands/changeitem.cpp
	src/ui/commands/changeitem.h
	src/ui/commands/changeitem.ui
	src/ui/commands/changemoney.cpp
	src/ui/commands/changemoney.h
	src/ui/commands/changemoney.ui
	src/ui/commands/changeparty.cpp
	src/ui/commands/changeparty.h
	src/ui/commands/changeparty.ui
	src/ui/commands/facegraphics.cpp
	src/ui/commands/facegraphics.h
	src/ui/commands/facegraphics.ui
	src/ui/commands/inputnumber.cpp
	src/ui/commands/inputnumber.h
	src/ui/commands/inputnumber.ui
	src/ui/commands/messageoptions.cpp
	src/ui/commands/messageoptions.h
	src/ui/commands/messageoptions.ui
	src/ui/commands/showchoices.cpp
	src/ui/commands/showchoices.h
	src/ui/commands/showchoices.ui
	src/ui/commands/showmessage.cpp
	src/ui/commands/showmessage.h
	src/ui/commands/showmessage.ui
	src/ui/commands/switchoperations.cpp
	src/ui/commands/switchoperations.h
	src/ui/commands/switchoperations.ui
	src/ui/commands/variableoperations.cpp
	src/ui/commands/variableoperations.h
	src/ui/commands/variableoperations.ui
	src/ui/common/dialogcharapicker.cpp
	src/ui/common/dialogcharapicker.h
	src/ui/common/dialogcharapicker.ui
	src/ui/common/dialogedit.cpp
	src/ui/common/dialogedit.h
	src/ui/common/dialogedit.ui
	src/ui/common/dialogfacepicker.cpp
	src/ui/common/dialogfacepicker.h
	src/ui/common/dialogimportimage.cpp
	src/ui/common/dialogimportimage.h
	src/ui/common/dialogimportimage.ui
	src/ui/common/qencounterdelegate.cpp
	src/ui/common/qencounterdelegate.h
	src/ui/common/qgraphicsbattleanimationitem.cpp
	src/ui/common/qgraphicsbattleanimationitem.h
	src/ui/common/qgraphicscharaitem.cpp
	src/ui/common/qgraphicscharaitem.h
	src/ui/common/qgraphicscurveitem.cpp
	src/ui/common/qgraphicscurveitem.h
	src/ui/common/qgraphicsfaceitem.cpp
	src/ui/common/qgraphicsfaceitem.h
	src/ui/common/qgraphicsimportitem.cpp
	src/ui/common/qgraphicsimportitem.h
	src/ui/common/qgraphicspalettescene.cpp
	src/ui/common/qgraphicspalettescene.h
	src/ui/common/qgraphicspickerscene.cpp
	src/ui/common/qgraphicspickerscene.h
	src/ui/common/rpgcombobox.h
	src/ui/common/rpgmodel.h
	src/ui/database/dialogdatabase.cpp
	src/ui/database/dialogdatabase.h
	src/ui/database/dialogdatabase.ui
	src/ui/database/qactordelegate.cpp
	src/ui/database/qactordelegate.h
	src/ui/database/qdbpageactors.cpp
	src/ui/database/qdbpageactors.h
	src/ui/database/qdbpageactors.ui
	src/ui/database/qdbpageattributes.cpp
	src/ui/database/qdbpageattributes.h
	src/ui/database/qdbpageattributes.ui
	src/ui/database/qdbpagebattleanimations.cpp
	src/ui/database/qdbpagebattleanimations.h
	src/ui/database/qdbpagebattleanimations.ui
	src/ui/database/qdbpagebattleanimations2.cpp
	src/ui/database/qdbpagebattleanimations2.h
	src/ui/database/qdbpagebattleanimations2.ui
	src/ui/database/qdbpagebattlescreen.cpp
	src/ui/database/qdbpagebattlescreen.h
	src/ui/database/qdbpagebattlescreen.ui
	src/ui/database/qdbpagechipset.cpp
	src/ui/database/qdbpagechipset.h
	src/ui/database/qdbpagechipset.ui
	src/ui/database/qdbpageclasses.cpp
	src/ui/database/qdbpageclasses.h
	src/ui/database/qdbpageclasses.ui
	src/ui/database/qdbpagecommonevents.cpp
	src/ui/database/qdbpagecommonevents.h
	src/ui/database/qdbpagecommonevents.ui
	src/ui/database/qdbpageenemies.cpp
	src/ui/database/qdbpageenemies.h
	src/ui/database/qdbpageenemies.ui
	src/ui/database/qdbpageenemygroups.cpp
	src/ui/database/qdbpageenemygroups.h
	src/ui/database/qdbpageenemygroups.ui
	src/ui/database/qdbpageherostatus.cpp
	src/ui/database/qdbpageherostatus.h
	src/ui/database/qdbpageherostatus.ui
	src/ui/database/qdbpageitems.cpp
	src/ui/database/qdbpageitems.h
	src/ui/database/qdbpageitems.ui
	src/ui/database/qdbpageskills.cpp
	src/ui/database/qdbpageskills.h
	src/ui/database/qdbpageskills.ui
	src/ui/database/qdbpagesystem.cpp
	src/ui/database/qdbpagesystem.h
	src/ui/database/qdbpagesystem.ui
	src/ui/database/qdbpagesystem2.cpp
	src/ui/database/qdbpagesystem2.h
	src/ui/database/qdbpagesystem2.ui
	src/ui/database/qdbpageterrain.cpp
	src/ui/database/qdbpageterrain.h
	src/ui/database/qdbpageterrain.ui
	src/ui/database/qdbpagevocabulary.cpp
	src/ui/database/qdbpagevocabulary.h
	src/ui/database/qdbpagevocabulary.ui
	src/ui/event/dialogevent.cpp
	src/ui/event/dialogevent.h
	src/ui/event/dialogevent.ui
	src/ui/event/qeventpagewidget.cpp
	src/ui/event/qeventpagewidget.h
	src/ui/event/qeventpagewidget.ui
	src/ui/mainwindow.cpp
	src/ui/mainwindow.h
	src/ui/mainwindow.ui
	src/ui/map/qgraphicsmapscene.cpp
	src/ui/map/qgraphicsmapscene.h
	src/ui/map/qundodraw.cpp
	src/ui/map/qundodraw.h
	src/ui/map/qundoevent.cpp
	src/ui/map/qundoevent.h
	src/ui/maptree/dialogmapproperties.cpp
	src/ui/maptree/dialogmapproperties.h
	src/ui/maptree/dialogmapproperties.ui
	src/ui/other/dialogimportproject.cpp
	src/ui/other/dialogimportproject.h
	src/ui/other/dialogimportproject.ui
	src/ui/other/dialognewproject.cpp
	src/ui/other/dialognewproject.h
	src/ui/other/dialognewproject.ui
	src/ui/other/dialogopenproject.cpp
	src/ui/other/dialogopenproject.h
	src/ui/other/dialogopenproject.ui
	src/ui/other/dialogresourcemanager.cpp
	src/ui/other/dialogresourcemanager.h
	src/ui/other/dialogresourcemanager.ui
	src/ui/other/dialogrtppath.cpp
	src/ui/other/dialogrtppath.h
	src/ui/other/dialogrtppath.ui
	src/ui/other/dialogrungame.cpp
	src/ui/other/dialogrungame.h
	src/ui/other/dialogrungame.ui
	src/ui/other/dialogsearch.cpp
	src/ui/other/dialogsearch.h
	src/ui/other/dialogsearch.ui
	src/ui/other/dialogsplash.cpp
	src/ui/other/dialogsplash.h
	src/ui/other/dialogsplash.ui
	src/ui/other/musicplayer.cpp
	src/ui/other/musicplayer.h
	src/ui/other/volumebutton.cpp
	src/ui/other/volumebutton.h
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
