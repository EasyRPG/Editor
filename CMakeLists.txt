cmake_minimum_required(VERSION 3.7)

project(EasyRPG_Editor VERSION 0.1.0 LANGUAGES CXX)

# C++17 is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source Files
add_library(${PROJECT_NAME} STATIC
	src/common/filefinder.cpp
	src/common/filefinder.h
	src/common/image_loader.cpp
	src/common/image_loader.h
	src/common/scope_guard.h
	src/common/signal_blocker.h
	src/common/sortfilter_proxy_models.cpp
	src/common/sortfilter_proxy_models.h
	src/common/widget_helper.cpp
	src/common/widget_helper.h
	src/core.cpp
	src/core.h
	src/defines.h
	src/gamecharacter.cpp
	src/gamecharacter.h
	src/main.cpp
	src/model/actor.cpp
	src/model/actor.h
	src/model/list_model.h
	src/model/project.cpp
	src/model/project.h
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
	src/ui/database/system2_widget.cpp
	src/ui/database/system2_widget.h
	src/ui/database/system2_widget.ui
	src/ui/database/system_widget.cpp
	src/ui/database/system_widget.h
	src/ui/database/system_widget.ui
	src/ui/database/terrain_widget.cpp
	src/ui/database/terrain_widget.h
	src/ui/database/terrain_widget.ui
	src/ui/database/vocabulary_widget.cpp
	src/ui/database/vocabulary_widget.h
	src/ui/database/vocabulary_widget.ui
	src/ui/event/event_dialog.cpp
	src/ui/event/event_dialog.h
	src/ui/event/event_dialog.ui
	src/ui/event/event_page_widget.cpp
	src/ui/event/event_page_widget.h
	src/ui/event/event_page_widget.ui
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
find_package(ZLIB REQUIRED)
find_package(liblcf REQUIRED)

# Libraries
target_link_libraries(${PROJECT_NAME}
	liblcf::liblcf
	ZLIB::ZLIB
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
