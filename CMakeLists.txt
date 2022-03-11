cmake_minimum_required(VERSION 3.9)
if(POLICY CMP0091)
	cmake_policy(SET CMP0091 NEW) # Support MSVC_RUNTIME_LIBRARY
endif()

project(EasyRPG_Editor VERSION 0.1.0 LANGUAGES CXX)

# Extra CMake Module files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
include(ConfigureWindows)

# C++17 is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source Files
set(EDITOR_SOURCES
	src/binding/actor.cpp
	src/binding/actor.h
	src/binding/animationcelldata.cpp
	src/binding/animationcelldata.h
	src/binding/animation.cpp
	src/binding/animationframe.cpp
	src/binding/animationframe.h
	src/binding/animation.h
	src/binding/animationtiming.cpp
	src/binding/animationtiming.h
	src/binding/array_adapter.h
	src/binding/array_adapter.cpp
	src/binding/attribute.cpp
	src/binding/attribute.h
	src/binding/battlecommand.cpp
	src/binding/battlecommand.h
	src/binding/battlecommands.cpp
	src/binding/battlecommands.h
	src/binding/battleranimation.cpp
	src/binding/battleranimation.h
	src/binding/battleranimationitemskill.cpp
	src/binding/battleranimationitemskill.h
	src/binding/battleranimationpose.cpp
	src/binding/battleranimationpose.h
	src/binding/battleranimationweapon.cpp
	src/binding/battleranimationweapon.h
	src/binding/binding_base.h
	src/binding/binding_base.cpp
	src/binding/chipset.cpp
	src/binding/chipset.h
	src/binding/class.cpp
	src/binding/class.h
	src/binding/commonevent.cpp
	src/binding/commonevent.h
	src/binding/database.cpp
	src/binding/database.h
	src/binding/encounter.cpp
	src/binding/encounter.h
	src/binding/enemyaction.cpp
	src/binding/enemyaction.h
	src/binding/enemy.cpp
	src/binding/enemy.h
	src/binding/equipment.cpp
	src/binding/equipment.h
	src/binding/eventcommand.cpp
	src/binding/eventcommand.h
	src/binding/event.cpp
	src/binding/event.h
	src/binding/eventpagecondition.cpp
	src/binding/eventpagecondition.h
	src/binding/eventpage.cpp
	src/binding/eventpage.h
	src/binding/item.cpp
	src/binding/item.h
	src/binding/learning.cpp
	src/binding/learning.h
	src/binding/map.cpp
	src/binding/map.h
	src/binding/mapinfo.cpp
	src/binding/mapinfo.h
	src/binding/movecommand.cpp
	src/binding/movecommand.h
	src/binding/moveroute.cpp
	src/binding/moveroute.h
	src/binding/music.cpp
	src/binding/music.h
	src/binding/parameters.cpp
	src/binding/parameters.h
	src/binding/rect.cpp
	src/binding/rect.h
	src/binding/saveactor.cpp
	src/binding/saveactor.h
	src/binding/savecommonevent.cpp
	src/binding/savecommonevent.h
	src/binding/save.cpp
	src/binding/saveeasyrpgdata.cpp
	src/binding/saveeasyrpgdata.h
	src/binding/saveeventexecframe.cpp
	src/binding/saveeventexecframe.h
	src/binding/saveeventexecstate.cpp
	src/binding/saveeventexecstate.h
	src/binding/save.h
	src/binding/saveinventory.cpp
	src/binding/saveinventory.h
	src/binding/savemapeventbase.cpp
	src/binding/savemapeventbase.h
	src/binding/savemapevent.cpp
	src/binding/savemapevent.h
	src/binding/savemapinfo.cpp
	src/binding/savemapinfo.h
	src/binding/savepanorama.cpp
	src/binding/savepanorama.h
	src/binding/savepartylocation.cpp
	src/binding/savepartylocation.h
	src/binding/savepicture.cpp
	src/binding/savepicture.h
	src/binding/savescreen.cpp
	src/binding/savescreen.h
	src/binding/savesystem.cpp
	src/binding/savesystem.h
	src/binding/savetarget.cpp
	src/binding/savetarget.h
	src/binding/savetitle.cpp
	src/binding/savetitle.h
	src/binding/savevehiclelocation.cpp
	src/binding/savevehiclelocation.h
	src/binding/skill.cpp
	src/binding/skill.h
	src/binding/sound.cpp
	src/binding/sound.h
	src/binding/start.cpp
	src/binding/start.h
	src/binding/state.cpp
	src/binding/state.h
	src/binding/switch.cpp
	src/binding/switch.h
	src/binding/system.cpp
	src/binding/system.h
	src/binding/terms.cpp
	src/binding/terms.h
	src/binding/terrain.cpp
	src/binding/terrain.h
	src/binding/testbattler.cpp
	src/binding/testbattler.h
	src/binding/treemap.cpp
	src/binding/treemap.h
	src/binding/troop.cpp
	src/binding/troop.h
	src/binding/troopmember.cpp
	src/binding/troopmember.h
	src/binding/trooppagecondition.cpp
	src/binding/trooppagecondition.h
	src/binding/trooppage.cpp
	src/binding/trooppage.h
	src/binding/variable.cpp
	src/binding/variable.h
	src/binding/generated/actor.cpp
	src/binding/generated/actor.h
	src/binding/generated/animationcelldata.cpp
	src/binding/generated/animationcelldata.h
	src/binding/generated/animation.cpp
	src/binding/generated/animationframe.cpp
	src/binding/generated/animationframe.h
	src/binding/generated/animation.h
	src/binding/generated/animationtiming.cpp
	src/binding/generated/animationtiming.h
	src/binding/generated/attribute.cpp
	src/binding/generated/attribute.h
	src/binding/generated/battlecommand.cpp
	src/binding/generated/battlecommand.h
	src/binding/generated/battlecommands.cpp
	src/binding/generated/battlecommands.h
	src/binding/generated/battleranimation.cpp
	src/binding/generated/battleranimation.h
	src/binding/generated/battleranimationitemskill.cpp
	src/binding/generated/battleranimationitemskill.h
	src/binding/generated/battleranimationpose.cpp
	src/binding/generated/battleranimationpose.h
	src/binding/generated/battleranimationweapon.cpp
	src/binding/generated/battleranimationweapon.h
	src/binding/generated/chipset.cpp
	src/binding/generated/chipset.h
	src/binding/generated/class.cpp
	src/binding/generated/class.h
	src/binding/generated/commonevent.cpp
	src/binding/generated/commonevent.h
	src/binding/generated/database.cpp
	src/binding/generated/database.h
	src/binding/generated/encounter.cpp
	src/binding/generated/encounter.h
	src/binding/generated/enemyaction.cpp
	src/binding/generated/enemyaction.h
	src/binding/generated/enemy.cpp
	src/binding/generated/enemy.h
	src/binding/generated/equipment.cpp
	src/binding/generated/equipment.h
	src/binding/generated/eventcommand.cpp
	src/binding/generated/eventcommand.h
	src/binding/generated/event.cpp
	src/binding/generated/event.h
	src/binding/generated/eventpagecondition.cpp
	src/binding/generated/eventpagecondition.h
	src/binding/generated/eventpage.cpp
	src/binding/generated/eventpage.h
	src/binding/generated/item.cpp
	src/binding/generated/item.h
	src/binding/generated/learning.cpp
	src/binding/generated/learning.h
	src/binding/generated/map.cpp
	src/binding/generated/map.h
	src/binding/generated/mapinfo.cpp
	src/binding/generated/mapinfo.h
	src/binding/generated/movecommand.cpp
	src/binding/generated/movecommand.h
	src/binding/generated/moveroute.cpp
	src/binding/generated/moveroute.h
	src/binding/generated/music.cpp
	src/binding/generated/music.h
	src/binding/generated/parameters.cpp
	src/binding/generated/parameters.h
	src/binding/generated/rect.cpp
	src/binding/generated/rect.h
	src/binding/generated/saveactor.cpp
	src/binding/generated/saveactor.h
	src/binding/generated/savecommonevent.cpp
	src/binding/generated/savecommonevent.h
	src/binding/generated/save.cpp
	src/binding/generated/saveeasyrpgdata.cpp
	src/binding/generated/saveeasyrpgdata.h
	src/binding/generated/saveeventexecframe.cpp
	src/binding/generated/saveeventexecframe.h
	src/binding/generated/saveeventexecstate.cpp
	src/binding/generated/saveeventexecstate.h
	src/binding/generated/save.h
	src/binding/generated/saveinventory.cpp
	src/binding/generated/saveinventory.h
	src/binding/generated/savemapeventbase.cpp
	src/binding/generated/savemapeventbase.h
	src/binding/generated/savemapevent.cpp
	src/binding/generated/savemapevent.h
	src/binding/generated/savemapinfo.cpp
	src/binding/generated/savemapinfo.h
	src/binding/generated/savepanorama.cpp
	src/binding/generated/savepanorama.h
	src/binding/generated/savepartylocation.cpp
	src/binding/generated/savepartylocation.h
	src/binding/generated/savepicture.cpp
	src/binding/generated/savepicture.h
	src/binding/generated/savescreen.cpp
	src/binding/generated/savescreen.h
	src/binding/generated/savesystem.cpp
	src/binding/generated/savesystem.h
	src/binding/generated/savetarget.cpp
	src/binding/generated/savetarget.h
	src/binding/generated/savetitle.cpp
	src/binding/generated/savetitle.h
	src/binding/generated/savevehiclelocation.cpp
	src/binding/generated/savevehiclelocation.h
	src/binding/generated/skill.cpp
	src/binding/generated/skill.h
	src/binding/generated/sound.cpp
	src/binding/generated/sound.h
	src/binding/generated/start.cpp
	src/binding/generated/start.h
	src/binding/generated/state.cpp
	src/binding/generated/state.h
	src/binding/generated/switch.cpp
	src/binding/generated/switch.h
	src/binding/generated/system.cpp
	src/binding/generated/system.h
	src/binding/generated/terms.cpp
	src/binding/generated/terms.h
	src/binding/generated/terrain.cpp
	src/binding/generated/terrain.h
	src/binding/generated/testbattler.cpp
	src/binding/generated/testbattler.h
	src/binding/generated/treemap.cpp
	src/binding/generated/treemap.h
	src/binding/generated/troop.cpp
	src/binding/generated/troop.h
	src/binding/generated/troopmember.cpp
	src/binding/generated/troopmember.h
	src/binding/generated/trooppagecondition.cpp
	src/binding/generated/trooppagecondition.h
	src/binding/generated/trooppage.cpp
	src/binding/generated/trooppage.h
	src/binding/generated/variable.cpp
	src/binding/generated/variable.h
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
	src/model/event_command_list.cpp
	src/model/event_command_list.h
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
	src/ui/commands/change_actor_face_widget.cpp
	src/ui/commands/change_actor_face_widget.h
	src/ui/commands/change_actor_face_widget.ui
	src/ui/commands/change_actor_graphic_widget.cpp
	src/ui/commands/change_actor_graphic_widget.h
	src/ui/commands/change_actor_graphic_widget.ui
	src/ui/commands/change_actor_name_widget.cpp
	src/ui/commands/change_actor_name_widget.h
	src/ui/commands/change_actor_name_widget.ui
	src/ui/commands/change_actor_title_widget.cpp
	src/ui/commands/change_actor_title_widget.h
	src/ui/commands/change_actor_title_widget.ui
	src/ui/commands/change_experience_widget.cpp
	src/ui/commands/change_experience_widget.h
	src/ui/commands/change_experience_widget.ui
	src/ui/commands/change_item_widget.cpp
	src/ui/commands/change_item_widget.h
	src/ui/commands/change_item_widget.ui
	src/ui/commands/change_level_widget.cpp
	src/ui/commands/change_level_widget.h
	src/ui/commands/change_level_widget.ui
	src/ui/commands/change_money_widget.cpp
	src/ui/commands/change_money_widget.h
	src/ui/commands/change_money_widget.ui
	src/ui/commands/change_party_widget.cpp
	src/ui/commands/change_party_widget.h
	src/ui/commands/change_party_widget.ui
	src/ui/commands/change_vehicle_graphic_widget.cpp
	src/ui/commands/change_vehicle_graphic_widget.h
	src/ui/commands/change_vehicle_graphic_widget.ui
	src/ui/commands/enable_disable_widget.cpp
	src/ui/commands/enable_disable_widget.h
	src/ui/commands/enable_disable_widget.ui
	src/ui/commands/face_graphics_widget.cpp
	src/ui/commands/face_graphics_widget.h
	src/ui/commands/face_graphics_widget.ui
	src/ui/commands/flash_screen_widget.cpp
	src/ui/commands/flash_screen_widget.h
	src/ui/commands/flash_screen_widget.ui
	src/ui/commands/full_heal_widget.cpp
	src/ui/commands/full_heal_widget.h
	src/ui/commands/full_heal_widget.ui
	src/ui/commands/input_number_widget.cpp
	src/ui/commands/input_number_widget.h
	src/ui/commands/input_number_widget.ui
	src/ui/commands/message_options_widget.cpp
	src/ui/commands/message_options_widget.h
	src/ui/commands/message_options_widget.ui
	src/ui/commands/shake_screen_widget.cpp
	src/ui/commands/shake_screen_widget.h
	src/ui/commands/shake_screen_widget.ui
	src/ui/commands/show_choices_widget.cpp
	src/ui/commands/show_choices_widget.h
	src/ui/commands/show_choices_widget.ui
	src/ui/commands/show_message_widget.cpp
	src/ui/commands/show_message_widget.h
	src/ui/commands/show_message_widget.ui
	src/ui/commands/switch_operations_widget.cpp
	src/ui/commands/switch_operations_widget.h
	src/ui/commands/switch_operations_widget.ui
	src/ui/commands/timer_operation_widget.cpp
	src/ui/commands/timer_operation_widget.h
	src/ui/commands/timer_operation_widget.ui
	src/ui/commands/tint_screen_widget.cpp
	src/ui/commands/tint_screen_widget.h
	src/ui/commands/tint_screen_widget.ui
	src/ui/commands/variable_operations_widget.cpp
	src/ui/commands/variable_operations_widget.h
	src/ui/commands/variable_operations_widget.ui
	src/ui/commands/weather_effects_widget.cpp
	src/ui/commands/weather_effects_widget.h
	src/ui/commands/weather_effects_widget.ui
	src/ui/common/edit_dialog.cpp
	src/ui/common/edit_dialog.h
	src/ui/common/edit_dialog.ui
	src/ui/common/encounter_delegate.cpp
	src/ui/common/encounter_delegate.h
	src/ui/common/import_image_dialog.cpp
	src/ui/common/import_image_dialog.h
	src/ui/common/import_image_dialog.ui
	src/ui/common/import_item.cpp
	src/ui/common/import_item.h
	src/ui/common/operand_widget.cpp
	src/ui/common/operand_widget.h
	src/ui/common/palette_scene.cpp
	src/ui/common/palette_scene.h
	src/ui/common/picker_scene.cpp
	src/ui/common/picker_scene.h
	src/ui/common/rpg_combobox.h
	src/ui/common/rpg_model.h
	src/ui/common/rpg_audio_lineedit.cpp
	src/ui/common/rpg_audio_lineedit.h
	src/ui/common/rpg_slider.cpp
	src/ui/common/rpg_slider.h
	src/ui/common/rpg_spinbox.cpp
	src/ui/common/rpg_spinbox.h
	src/ui/common/system_color_combobox.cpp
	src/ui/common/system_color_combobox.h
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
	src/ui/event/event_command_base_widget.cpp
	src/ui/event/event_command_base_widget.h
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
	src/ui/picker/picker_audio_widget.cpp
	src/ui/picker/picker_audio_widget.h
	src/ui/picker/picker_audio_widget.ui
	src/ui/picker/picker_backdrop_widget.cpp
	src/ui/picker/picker_backdrop_widget.h
	src/ui/picker/picker_child_widget.cpp
	src/ui/picker/picker_child_widget.h
	src/ui/picker/picker_charset_widget.cpp
	src/ui/picker/picker_charset_widget.h
	src/ui/picker/picker_faceset_widget.cpp
	src/ui/picker/picker_faceset_widget.h
	src/ui/picker/picker_panorama_widget.cpp
	src/ui/picker/picker_panorama_widget.h
	src/ui/picker/picker_dialog.cpp
	src/ui/picker/picker_dialog.h
	src/ui/picker/picker_dialog.ui
	src/ui/viewer/battle_animation_graphics_item.cpp
	src/ui/viewer/battle_animation_graphics_item.h
	src/ui/viewer/charset_graphics_item.cpp
	src/ui/viewer/charset_graphics_item.h
	src/ui/viewer/faceset_graphics_item.cpp
	src/ui/viewer/faceset_graphics_item.h
	src/ui/viewer/rpg_graphics_view.cpp
	src/ui/viewer/rpg_graphics_view.h
	src/ui/viewer/stat_curve_graphics_item.cpp
	src/ui/viewer/stat_curve_graphics_item.h
)
add_library(${PROJECT_NAME} STATIC ${EDITOR_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# IDE source grouping
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "Editor" FILES ${EDITOR_SOURCES})

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
find_package(Qt5 REQUIRED NO_MODULE COMPONENTS Core Widgets Multimedia Gui Svg Quick QuickControls2)
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
	Qt5::QSvgIconPlugin Qt5::Quick Qt5::Qml
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
