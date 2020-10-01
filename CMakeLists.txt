cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0091 NEW) # Support MSVC_RUNTIME_LIBRARY

project(EasyRPG_Editor VERSION 0.1.0 LANGUAGES CXX)

# Extra CMake Module files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
include(ConfigureWindows)

# C++17 is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source Files
add_library(${PROJECT_NAME} STATIC
	src/common/dbstring.h
	src/common/filefinder.cpp
	src/common/filefinder.h
	src/common/image_loader.cpp
	src/common/image_loader.h
	src/common/lcf_widget_binding.cpp
	src/common/lcf_widget_binding.h
	src/common/scope_guard.h
	src/common/signal_blocker.h
	src/common/sortfilter_proxy_models.cpp
	src/common/sortfilter_proxy_models.h
	src/core.cpp
	src/core.h
	src/defines.h
	src/gamecharacter.cpp
	src/gamecharacter.h
	src/main.cpp
	src/model/actor.cpp
	src/model/actor.h
	src/model/animation.cpp
	src/model/animation.h
	src/model/attribute.cpp
	src/model/attribute.h
	src/model/battleranimation.cpp
	src/model/battleranimation.h
	src/model/chipset.cpp
	src/model/chipset.h
	src/model/class.cpp
	src/model/class.h
	src/model/commonevent.cpp
	src/model/commonevent.h
	src/model/enemy.cpp
	src/model/enemy.h
	src/model/item.cpp
	src/model/item.h
	src/model/project.cpp
	src/model/project.h
	src/model/project_data.cpp
	src/model/project_data.h
	src/model/rpg_base.cpp
	src/model/rpg_base.h
	src/model/rpg_reflect.h
	src/model/skill.cpp
	src/model/skill.h
	src/model/state.cpp
	src/model/state.h
	src/model/switch.cpp
	src/model/switch.h
	src/model/terrain.cpp
	src/model/terrain.h
	src/model/troop.cpp
	src/model/troop.h
	src/model/variable.cpp
	src/model/variable.h
	src/stringizer.cpp
	src/stringizer.h
	src/ui/commands/all_commands.h
	src/ui/commands/change_experience_widget.cpp
	src/ui/commands/change_experience_widget.h
	src/ui/commands/change_experience_widget.ui
	src/ui/commands/change_item_widget.cpp
	src/ui/commands/change_item_widget.h
	src/ui/commands/change_item_widget.ui
	src/ui/commands/change_money_widget.cpp
	src/ui/commands/change_money_widget.h
	src/ui/commands/change_money_widget.ui
	src/ui/commands/change_party_widget.cpp
	src/ui/commands/change_party_widget.h
	src/ui/commands/change_party_widget.ui
	src/ui/commands/face_graphics_widget.cpp
	src/ui/commands/face_graphics_widget.h
	src/ui/commands/face_graphics_widget.ui
	src/ui/commands/input_number_widget.cpp
	src/ui/commands/input_number_widget.h
	src/ui/commands/input_number_widget.ui
	src/ui/commands/message_options_widget.cpp
	src/ui/commands/message_options_widget.h
	src/ui/commands/message_options_widget.ui
	src/ui/commands/show_choices_widget.cpp
	src/ui/commands/show_choices_widget.h
	src/ui/commands/show_choices_widget.ui
	src/ui/commands/show_message_widget.cpp
	src/ui/commands/show_message_widget.h
	src/ui/commands/show_message_widget.ui
	src/ui/commands/switch_operations_widget.cpp
	src/ui/commands/switch_operations_widget.h
	src/ui/commands/switch_operations_widget.ui
	src/ui/commands/variable_operations_widget.cpp
	src/ui/commands/variable_operations_widget.h
	src/ui/commands/variable_operations_widget.ui
	src/ui/common/battle_animation_item.cpp
	src/ui/common/battle_animation_item.h
	src/ui/common/charset_item.cpp
	src/ui/common/charset_item.h
	src/ui/common/charset_picker_dialog.cpp
	src/ui/common/charset_picker_dialog.h
	src/ui/common/charset_picker_dialog.ui
	src/ui/common/edit_dialog.cpp
	src/ui/common/edit_dialog.h
	src/ui/common/edit_dialog.ui
	src/ui/common/encounter_delegate.cpp
	src/ui/common/encounter_delegate.h
	src/ui/common/faceset_item.cpp
	src/ui/common/faceset_item.h
	src/ui/common/faceset_picker_dialog.cpp
	src/ui/common/faceset_picker_dialog.h
	src/ui/common/import_image_dialog.cpp
	src/ui/common/import_image_dialog.h
	src/ui/common/import_image_dialog.ui
	src/ui/common/import_item.cpp
	src/ui/common/import_item.h
	src/ui/common/palette_scene.cpp
	src/ui/common/palette_scene.h
	src/ui/common/picker_scene.cpp
	src/ui/common/picker_scene.h
	src/ui/common/rpg_combobox.h
	src/ui/common/rpg_model.h
	src/ui/common/stat_curve_item.cpp
	src/ui/common/stat_curve_item.h
	src/ui/common/widget_as_dialog_model_wrapper.h
	src/ui/common/widget_as_dialog_wrapper.h
	src/ui/database/actor_delegate.cpp
	src/ui/database/actor_delegate.h
	src/ui/database/actor_widget.cpp
	src/ui/database/actor_widget.h
	src/ui/database/actor_widget.ui
	src/ui/database/attribute_widget.cpp
	src/ui/database/attribute_widget.h
	src/ui/database/attribute_widget.ui
	src/ui/database/battle_animation2_widget.cpp
	src/ui/database/battle_animation2_widget.h
	src/ui/database/battle_animation2_widget.ui
	src/ui/database/battle_animation_widget.cpp
	src/ui/database/battle_animation_widget.h
	src/ui/database/battle_animation_widget.ui
	src/ui/database/battle_screen_widget.cpp
	src/ui/database/battle_screen_widget.h
	src/ui/database/battle_screen_widget.ui
	src/ui/database/chipset_widget.cpp
	src/ui/database/chipset_widget.h
	src/ui/database/chipset_widget.ui
	src/ui/database/class_widget.cpp
	src/ui/database/class_widget.h
	src/ui/database/class_widget.ui
	src/ui/database/common_event_widget.cpp
	src/ui/database/common_event_widget.h
	src/ui/database/common_event_widget.ui
	src/ui/database/database_dialog.cpp
	src/ui/database/database_dialog.h
	src/ui/database/database_dialog.ui
	src/ui/database/database_split_widget.cpp
	src/ui/database/database_split_widget.h
	src/ui/database/database_split_widget.ui
	src/ui/database/enemy_group_widget.cpp
	src/ui/database/enemy_group_widget.h
	src/ui/database/enemy_group_widget.ui
	src/ui/database/enemy_widget.cpp
	src/ui/database/enemy_widget.h
	src/ui/database/enemy_widget.ui
	src/ui/database/item_widget.cpp
	src/ui/database/item_widget.h
	src/ui/database/item_widget.ui
	src/ui/database/skill_widget.cpp
	src/ui/database/skill_widget.h
	src/ui/database/skill_widget.ui
	src/ui/database/state_widget.cpp
	src/ui/database/state_widget.h
	src/ui/database/state_widget.ui
	src/ui/database/switch_widget.cpp
	src/ui/database/switch_widget.h
	src/ui/database/switch_widget.ui
	src/ui/database/system2_widget.cpp
	src/ui/database/system2_widget.h
	src/ui/database/system2_widget.ui
	src/ui/database/system_widget.cpp
	src/ui/database/system_widget.h
	src/ui/database/system_widget.ui
	src/ui/database/terrain_widget.cpp
	src/ui/database/terrain_widget.h
	src/ui/database/terrain_widget.ui
	src/ui/database/variable_widget.cpp
	src/ui/database/variable_widget.h
	src/ui/database/variable_widget.ui
	src/ui/database/vocabulary_widget.cpp
	src/ui/database/vocabulary_widget.h
	src/ui/database/vocabulary_widget.ui
	src/ui/event/battle_page_widget.cpp
	src/ui/event/battle_page_widget.h
	src/ui/event/battle_page_widget.ui
	src/ui/event/event_commands_widget.cpp
	src/ui/event/event_commands_widget.h
	src/ui/event/event_dialog.cpp
	src/ui/event/event_dialog.h
	src/ui/event/event_dialog.ui
	src/ui/event/event_page_widget.cpp
	src/ui/event/event_page_widget.h
	src/ui/event/event_page_widget.ui
	src/ui/event/event_raw_widget.cpp
	src/ui/event/event_raw_widget.h
	src/ui/event/event_raw_widget.ui
	src/ui/main_window.cpp
	src/ui/main_window.h
	src/ui/main_window.ui
	src/ui/map/map_scene.cpp
	src/ui/map/map_scene.h
	src/ui/map/undo_draw.cpp
	src/ui/map/undo_draw.h
	src/ui/map/undo_event.cpp
	src/ui/map/undo_event.h
	src/ui/maptree/map_properties_dialog.cpp
	src/ui/maptree/map_properties_dialog.h
	src/ui/maptree/map_properties_dialog.ui
	src/ui/other/import_project_dialog.cpp
	src/ui/other/import_project_dialog.h
	src/ui/other/import_project_dialog.ui
	src/ui/other/musicplayer.cpp
	src/ui/other/musicplayer.h
	src/ui/other/new_project_dialog.cpp
	src/ui/other/new_project_dialog.h
	src/ui/other/new_project_dialog.ui
	src/ui/other/open_project_dialog.cpp
	src/ui/other/open_project_dialog.h
	src/ui/other/open_project_dialog.ui
	src/ui/other/resource_manager_dialog.cpp
	src/ui/other/resource_manager_dialog.h
	src/ui/other/resource_manager_dialog.ui
	src/ui/other/rtp_path_dialog.cpp
	src/ui/other/rtp_path_dialog.h
	src/ui/other/rtp_path_dialog.ui
	src/ui/other/run_game_dialog.cpp
	src/ui/other/run_game_dialog.h
	src/ui/other/run_game_dialog.ui
	src/ui/other/search_dialog.cpp
	src/ui/other/search_dialog.h
	src/ui/other/search_dialog.ui
	src/ui/other/splash_dialog.cpp
	src/ui/other/splash_dialog.h
	src/ui/other/splash_dialog.ui
	src/ui/other/volumebutton.cpp
	src/ui/other/volumebutton.h
)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Add autogen include dirs to include path, otherwise the includes are not found
# when used in the header (via https://stackoverflow.com/q/44746308/)
get_property(_isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(_isMultiConfig)
	set(AUTOGEN_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}_autogen/include_$<CONFIG>)
else()
	set(AUTOGEN_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}_autogen/include)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE
	$<BUILD_INTERFACE:${AUTOGEN_INCLUDE_DIR}>
)

# Qt Magic
set_target_properties(${PROJECT_NAME} PROPERTIES
	AUTOMOC ON
	AUTOUIC ON
)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# App Icon (for macOS)
set(${PROJECT_NAME}_BUNDLE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/resources/app/Editor.icns")

# Do not code sign on Macs
set(CMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO")
set(CMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "")
set(CMAKE_XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "org.easyrpg.editor")

# Dependencies
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(ZLIB REQUIRED)
# liblcf
option(EDITOR_BUILD_LIBLCF "Instead of detecting liblcf the liblcf repository is cloned into lib/liblcf and built together with the Player. This is convenient for development" OFF)
set(EDITOR_BUILD_LIBLCF_GIT "https://github.com/EasyRPG/liblcf.git" CACHE STRING "Git repository of liblcf to clone when building liblcf. Requires EDITOR_BUILD_LIBLCF=ON.")

if(EDITOR_BUILD_LIBLCF)
	# liblcf is built as part of this cmake file
	set(LIBLCF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/liblcf")
	if(NOT EXISTS ${LIBLCF_PATH})
		find_package(Git REQUIRED)
		execute_process(COMMAND ${GIT_EXECUTABLE} clone "--depth=1"
			"${EDITOR_BUILD_LIBLCF_GIT}"
			"${LIBLCF_PATH}")
	endif()
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/liblcf/builds/cmake/Modules")

	option(BUILD_SHARED_LIBS "Not used. Supresses CMP0077 in liblcf" ON)

	# Always build static liblcf
	function(add_liblcf)
		set(BUILD_SHARED_LIBS OFF)
		add_subdirectory(${LIBLCF_PATH})
	endfunction()
	add_liblcf()
	target_link_libraries(${PROJECT_NAME} lcf)
else()
	# Use system package
	find_package(liblcf REQUIRED)
	target_link_libraries(${PROJECT_NAME} liblcf::liblcf)
endif()

# Find Qt deployment apps
if(APPLE)
	get_target_property(_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
	get_filename_component(_QT_BIN_DIR "${_QMAKE_EXECUTABLE}" DIRECTORY)
	find_program(MACDEPLOYQT_EXECUTABLE macdeployqt HINTS "${_QT_BIN_DIR}")
endif()

# Libraries
target_link_libraries(${PROJECT_NAME}
	ZLIB::ZLIB
	Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia Qt5::Svg
	Qt5::QSvgIconPlugin
)

# Executable
# Windows: Only open console for Debug builds
if(APPLE)
	set(EXE_NAME "EasyRPG-Editor.app")
	set_source_files_properties(${${PROJECT_NAME}_BUNDLE_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
	add_executable("${EXE_NAME}" MACOSX_BUNDLE "src/main.cpp" ${${PROJECT_NAME}_BUNDLE_ICON})
else()
	set(EXE_NAME "${PROJECT_NAME}_exe")
	if(CMAKE_BUILD_TYPE MATCHES "Debug")
		add_executable(${PROJECT_NAME}_exe "src/main.cpp")
	else()
		add_executable(${PROJECT_NAME}_exe WIN32 "src/main.cpp")
	endif()
endif()

if(WIN32)
	set_target_properties(${PROJECT_NAME}_exe PROPERTIES OUTPUT_NAME "Editor")
elseif(APPLE)
	set(EXE_OUTPUT_NAME "EasyRPG Editor")
	set_target_properties("${EXE_NAME}" PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/resources/app/Info.plist.in")
	set_target_properties("${EXE_NAME}" PROPERTIES OUTPUT_NAME ${EXE_OUTPUT_NAME})
else()
	set_target_properties(${PROJECT_NAME}_exe PROPERTIES OUTPUT_NAME "easyrpg-editor")
endif()

target_link_libraries(${EXE_NAME} ${PROJECT_NAME})

# Qt Magic (Enable resource compiler for exe)
set_target_properties(${EXE_NAME} PROPERTIES
	AUTORCC ON
)

# Add resources
target_sources(${EXE_NAME} PRIVATE "resources/Resources.qrc")

if(WIN32)
	target_sources(${EXE_NAME} PRIVATE "resources/Resources.rc")
endif()

# Installation
include(GNUInstallDirs)
if(APPLE)
	set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
	install(TARGETS ${EXE_NAME} RUNTIME DESTINATION BUNDLE DESTINATION "${CMAKE_BINARY_DIR}/Package")
	# Run macdeployqt
	install(CODE "
		execute_process(COMMAND 
			${MACDEPLOYQT_EXECUTABLE}
			\"${CMAKE_BINARY_DIR}/Package/${EXE_OUTPUT_NAME}.app\" 
			-always-overwrite
		)
	")
	# Run cmake fixup_bundle to fix runpath for any non-Qt dylibs and to verify
	install(CODE "
		include(BundleUtilities)
		set(BU_CHMOD_BUNDLE_ITEMS TRUE)
		fixup_bundle(\"${CMAKE_BINARY_DIR}/Package/${EXE_OUTPUT_NAME}.app\" \"\" \"\")
	" COMPONENT RUNTIME)
else()
	install(TARGETS ${EXE_NAME}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)
endif()
