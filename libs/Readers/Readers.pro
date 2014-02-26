#-------------------------------------------------
#
# Project created by QtCreator 2014-02-22T18:11:30
#
#-------------------------------------------------

QT       -= core gui

TARGET = Readers
TEMPLATE = lib
CONFIG += staticlib

DEFINES += READER_SUPPORT_XML

SOURCES += \
    src/data.cpp \
    src/ini.cpp \
    src/inireader.cpp \
    src/ldb_equipment.cpp \
    src/ldb_eventcommand.cpp \
    src/ldb_parameters.cpp \
    src/ldb_reader.cpp \
    src/lmt_reader.cpp \
    src/lmt_rect.cpp \
    src/lmt_treemap.cpp \
    src/lmu_movecommand.cpp \
    src/lmu_reader.cpp \
    src/lsd_reader.cpp \
    src/reader_flags.cpp \
    src/reader_lcf.cpp \
    src/reader_struct.cpp \
    src/reader_util.cpp \
    src/reader_xml.cpp \
    src/rpg_setup.cpp \
    src/writer_lcf.cpp \
    src/writer_xml.cpp \
    src/generated/ldb_actor.cpp \
    src/generated/ldb_animation.cpp \
    src/generated/ldb_animationcelldata.cpp \
    src/generated/ldb_animationframe.cpp \
    src/generated/ldb_animationtiming.cpp \
    src/generated/ldb_attribute.cpp \
    src/generated/ldb_battlecommand.cpp \
    src/generated/ldb_battlecommands.cpp \
    src/generated/ldb_battleranimation.cpp \
    src/generated/ldb_battleranimationdata.cpp \
    src/generated/ldb_battleranimationextension.cpp \
    src/generated/ldb_chipset.cpp \
    src/generated/ldb_class.cpp \
    src/generated/ldb_commonevent.cpp \
    src/generated/ldb_database.cpp \
    src/generated/ldb_enemy.cpp \
    src/generated/ldb_enemyaction.cpp \
    src/generated/ldb_item.cpp \
    src/generated/ldb_itemanimation.cpp \
    src/generated/ldb_learning.cpp \
    src/generated/ldb_music.cpp \
    src/generated/ldb_skill.cpp \
    src/generated/ldb_sound.cpp \
    src/generated/ldb_state.cpp \
    src/generated/ldb_switch.cpp \
    src/generated/ldb_system.cpp \
    src/generated/ldb_terms.cpp \
    src/generated/ldb_terrain.cpp \
    src/generated/ldb_terrain_flags.cpp \
    src/generated/ldb_testbattler.cpp \
    src/generated/ldb_troop.cpp \
    src/generated/ldb_troopmember.cpp \
    src/generated/ldb_trooppage.cpp \
    src/generated/ldb_trooppagecondition.cpp \
    src/generated/ldb_trooppagecondition_flags.cpp \
    src/generated/ldb_variable.cpp \
    src/generated/lmt_encounter.cpp \
    src/generated/lmt_mapinfo.cpp \
    src/generated/lmt_start.cpp \
    src/generated/lmu_event.cpp \
    src/generated/lmu_eventpage.cpp \
    src/generated/lmu_eventpagecondition.cpp \
    src/generated/lmu_eventpagecondition_flags.cpp \
    src/generated/lmu_map.cpp \
    src/generated/lmu_moveroute.cpp \
    src/generated/lsd_save.cpp \
    src/generated/lsd_saveactor.cpp \
    src/generated/lsd_savecommonevent.cpp \
    src/generated/lsd_saveeventcommands.cpp \
    src/generated/lsd_saveeventdata.cpp \
    src/generated/lsd_saveevents.cpp \
    src/generated/lsd_saveinventory.cpp \
    src/generated/lsd_savemapevent.cpp \
    src/generated/lsd_savemapinfo.cpp \
    src/generated/lsd_savepartylocation.cpp \
    src/generated/lsd_savepicture.cpp \
    src/generated/lsd_savescreen.cpp \
    src/generated/lsd_savesystem.cpp \
    src/generated/lsd_savetarget.cpp \
    src/generated/lsd_savetitle.cpp \
    src/generated/lsd_savevehiclelocation.cpp \
    src/generated/rpg_actor.cpp \
    src/generated/rpg_animation.cpp \
    src/generated/rpg_animationcelldata.cpp \
    src/generated/rpg_animationframe.cpp \
    src/generated/rpg_animationtiming.cpp \
    src/generated/rpg_attribute.cpp \
    src/generated/rpg_battlecommand.cpp \
    src/generated/rpg_battlecommands.cpp \
    src/generated/rpg_battleranimation.cpp \
    src/generated/rpg_battleranimationdata.cpp \
    src/generated/rpg_battleranimationextension.cpp \
    src/generated/rpg_chipset.cpp \
    src/generated/rpg_class.cpp \
    src/generated/rpg_commonevent.cpp \
    src/generated/rpg_encounter.cpp \
    src/generated/rpg_enemy.cpp \
    src/generated/rpg_enemyaction.cpp \
    src/generated/rpg_equipment.cpp \
    src/generated/rpg_event.cpp \
    src/generated/rpg_eventcommand.cpp \
    src/generated/rpg_eventpage.cpp \
    src/generated/rpg_eventpagecondition.cpp \
    src/generated/rpg_item.cpp \
    src/generated/rpg_itemanimation.cpp \
    src/generated/rpg_learning.cpp \
    src/generated/rpg_map.cpp \
    src/generated/rpg_mapinfo.cpp \
    src/generated/rpg_movecommand.cpp \
    src/generated/rpg_moveroute.cpp \
    src/generated/rpg_music.cpp \
    src/generated/rpg_rect.cpp \
    src/generated/rpg_save.cpp \
    src/generated/rpg_saveactor.cpp \
    src/generated/rpg_savecommonevent.cpp \
    src/generated/rpg_saveeventcommands.cpp \
    src/generated/rpg_saveeventdata.cpp \
    src/generated/rpg_saveevents.cpp \
    src/generated/rpg_saveinventory.cpp \
    src/generated/rpg_savemapevent.cpp \
    src/generated/rpg_savemapinfo.cpp \
    src/generated/rpg_savepartylocation.cpp \
    src/generated/rpg_savepicture.cpp \
    src/generated/rpg_savescreen.cpp \
    src/generated/rpg_savesystem.cpp \
    src/generated/rpg_savetarget.cpp \
    src/generated/rpg_savetitle.cpp \
    src/generated/rpg_savevehiclelocation.cpp \
    src/generated/rpg_skill.cpp \
    src/generated/rpg_sound.cpp \
    src/generated/rpg_start.cpp \
    src/generated/rpg_state.cpp \
    src/generated/rpg_switch.cpp \
    src/generated/rpg_system.cpp \
    src/generated/rpg_terms.cpp \
    src/generated/rpg_terrain.cpp \
    src/generated/rpg_testbattler.cpp \
    src/generated/rpg_treemap.cpp \
    src/generated/rpg_troop.cpp \
    src/generated/rpg_troopmember.cpp \
    src/generated/rpg_trooppage.cpp \
    src/generated/rpg_trooppagecondition.cpp \
    src/generated/rpg_variable.cpp

HEADERS += \
    include/command_codes.h \
    include/data.h \
    include/ini.h \
    include/inireader.h \
    include/ldb_chunks.h \
    include/ldb_reader.h \
    include/lmt_chunks.h \
    include/lmt_reader.h \
    include/lmu_chunks.h \
    include/lmu_reader.h \
    include/lsd_chunks.h \
    include/lsd_reader.h \
    include/reader_lcf.h \
    include/reader_options.h \
    include/reader_struct.h \
    include/reader_types.h \
    include/reader_util.h \
    include/reader_xml.h \
    include/rpg_actor.h \
    include/rpg_animation.h \
    include/rpg_animationcelldata.h \
    include/rpg_animationframe.h \
    include/rpg_animationtiming.h \
    include/rpg_attribute.h \
    include/rpg_battlecommand.h \
    include/rpg_battlecommands.h \
    include/rpg_battleranimation.h \
    include/rpg_battleranimationdata.h \
    include/rpg_battleranimationextension.h \
    include/rpg_chipset.h \
    include/rpg_class.h \
    include/rpg_commonevent.h \
    include/rpg_database.h \
    include/rpg_encounter.h \
    include/rpg_enemy.h \
    include/rpg_enemyaction.h \
    include/rpg_equipment.h \
    include/rpg_event.h \
    include/rpg_eventcommand.h \
    include/rpg_eventpage.h \
    include/rpg_eventpagecondition.h \
    include/rpg_item.h \
    include/rpg_itemanimation.h \
    include/rpg_learning.h \
    include/rpg_map.h \
    include/rpg_mapinfo.h \
    include/rpg_movecommand.h \
    include/rpg_moveroute.h \
    include/rpg_music.h \
    include/rpg_parameters.h \
    include/rpg_rect.h \
    include/rpg_save.h \
    include/rpg_saveactor.h \
    include/rpg_savecommonevent.h \
    include/rpg_saveeventcommands.h \
    include/rpg_saveeventdata.h \
    include/rpg_saveevents.h \
    include/rpg_saveinventory.h \
    include/rpg_savemapevent.h \
    include/rpg_savemapinfo.h \
    include/rpg_savepartylocation.h \
    include/rpg_savepicture.h \
    include/rpg_savescreen.h \
    include/rpg_savesystem.h \
    include/rpg_savetarget.h \
    include/rpg_savetitle.h \
    include/rpg_savevehiclelocation.h \
    include/rpg_skill.h \
    include/rpg_sound.h \
    include/rpg_start.h \
    include/rpg_state.h \
    include/rpg_switch.h \
    include/rpg_system.h \
    include/rpg_terms.h \
    include/rpg_terrain.h \
    include/rpg_testbattler.h \
    include/rpg_treemap.h \
    include/rpg_troop.h \
    include/rpg_troopmember.h \
    include/rpg_trooppage.h \
    include/rpg_trooppagecondition.h \
    include/rpg_variable.h \
    include/writer_lcf.h \
    include/writer_xml.h \
    include/boost/preprocessor/cat.hpp \
    include/boost/preprocessor/stringize.hpp \
    include/boost/preprocessor/config/config.hpp

INCLUDEPATH += $$(EASYDEV_MSVC)\include

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32: LIBS += -LC:/Expat/Bin/ -llibexpat

INCLUDEPATH += C:/Expat/Bin
DEPENDPATH += C:/Expat/Bin
