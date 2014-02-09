#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui multimedia winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  multimedia winextras

TARGET = EasyRPG-Editor
TEMPLATE = app

DEFINES += READER_SUPPORT_XML

SOURCES += src/mainwindow.cpp \
    src/main.cpp \
    src/dialogresourcemanager.cpp \
    src/dialogdatabase.cpp \
    src/dialogimportimage.cpp \
    src/dialognewproject.cpp \
    src/tools/QGraphicsImportItem.cpp \
    src/gamecharacter.cpp \
    src/dialogopenproject.cpp \
    src/musicplayer.cpp \
    src/tools/QGraphicsPaleteScene.cpp \
    src/volumebutton.cpp \
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
    src/rpg_variable.cpp \
    src/rpg_trooppagecondition.cpp \
    src/rpg_trooppage.cpp \
    src/rpg_troopmember.cpp \
    src/rpg_troop.cpp \
    src/rpg_treemap.cpp \
    src/rpg_testbattler.cpp \
    src/rpg_terrain.cpp \
    src/rpg_terms.cpp \
    src/rpg_system.cpp \
    src/rpg_switch.cpp \
    src/rpg_state.cpp \
    src/rpg_start.cpp \
    src/rpg_sound.cpp \
    src/rpg_skill.cpp \
    src/rpg_savevehiclelocation.cpp \
    src/rpg_savetitle.cpp \
    src/rpg_savetarget.cpp \
    src/rpg_savesystem.cpp \
    src/rpg_savescreen.cpp \
    src/rpg_savepicture.cpp \
    src/rpg_savepartylocation.cpp \
    src/rpg_savemapinfo.cpp \
    src/rpg_savemapevent.cpp \
    src/rpg_saveinventory.cpp \
    src/rpg_saveevents.cpp \
    src/rpg_saveeventdata.cpp \
    src/rpg_saveeventcommands.cpp \
    src/rpg_savecommonevent.cpp \
    src/rpg_saveactor.cpp \
    src/rpg_save.cpp \
    src/rpg_rect.cpp \
    src/rpg_music.cpp \
    src/rpg_moveroute.cpp \
    src/rpg_movecommand.cpp \
    src/rpg_mapinfo.cpp \
    src/rpg_map.cpp \
    src/rpg_learning.cpp \
    src/rpg_itemanimation.cpp \
    src/rpg_item.cpp \
    src/rpg_eventpagecondition.cpp \
    src/rpg_eventpage.cpp \
    src/rpg_eventcommand.cpp \
    src/rpg_event.cpp \
    src/rpg_equipment.cpp \
    src/rpg_enemyaction.cpp \
    src/rpg_enemy.cpp \
    src/rpg_encounter.cpp \
    src/rpg_commonevent.cpp \
    src/rpg_class.cpp \
    src/rpg_chipset.cpp \
    src/rpg_battleranimationextension.cpp \
    src/rpg_battleranimationdata.cpp \
    src/rpg_battleranimation.cpp \
    src/rpg_battlecommands.cpp \
    src/rpg_battlecommand.cpp \
    src/rpg_attribute.cpp \
    src/rpg_animationtiming.cpp \
    src/rpg_animationframe.cpp \
    src/rpg_animationcelldata.cpp \
    src/rpg_animation.cpp \
    src/rpg_actor.cpp \
    src/lsd_savevehiclelocation.cpp \
    src/lsd_savetitle.cpp \
    src/lsd_savetarget.cpp \
    src/lsd_savesystem.cpp \
    src/lsd_savescreen.cpp \
    src/lsd_savepicture.cpp \
    src/lsd_savepartylocation.cpp \
    src/lsd_savemapinfo.cpp \
    src/lsd_savemapevent.cpp \
    src/lsd_saveinventory.cpp \
    src/lsd_saveevents.cpp \
    src/lsd_saveeventdata.cpp \
    src/lsd_saveeventcommands.cpp \
    src/lsd_savecommonevent.cpp \
    src/lsd_saveactor.cpp \
    src/lsd_save.cpp \
    src/lmu_moveroute.cpp \
    src/lmu_map.cpp \
    src/lmu_eventpagecondition_flags.cpp \
    src/lmu_eventpagecondition.cpp \
    src/lmu_eventpage.cpp \
    src/lmu_event.cpp \
    src/lmt_start.cpp \
    src/lmt_mapinfo.cpp \
    src/lmt_encounter.cpp \
    src/ldb_variable.cpp \
    src/ldb_trooppagecondition_flags.cpp \
    src/ldb_trooppagecondition.cpp \
    src/ldb_trooppage.cpp \
    src/ldb_troopmember.cpp \
    src/ldb_troop.cpp \
    src/ldb_testbattler.cpp \
    src/ldb_terrain_flags.cpp \
    src/ldb_terrain.cpp \
    src/ldb_terms.cpp \
    src/ldb_system.cpp \
    src/ldb_switch.cpp \
    src/ldb_state.cpp \
    src/ldb_sound.cpp \
    src/ldb_skill.cpp \
    src/ldb_music.cpp \
    src/ldb_learning.cpp \
    src/ldb_itemanimation.cpp \
    src/ldb_item.cpp \
    src/ldb_enemyaction.cpp \
    src/ldb_enemy.cpp \
    src/ldb_database.cpp \
    src/ldb_commonevent.cpp \
    src/ldb_class.cpp \
    src/ldb_chipset.cpp \
    src/ldb_battleranimationextension.cpp \
    src/ldb_battleranimationdata.cpp \
    src/ldb_battleranimation.cpp \
    src/ldb_battlecommands.cpp \
    src/ldb_battlecommand.cpp \
    src/ldb_attribute.cpp \
    src/ldb_animationtiming.cpp \
    src/ldb_animationframe.cpp \
    src/ldb_animationcelldata.cpp \
    src/ldb_animation.cpp \
    src/ldb_actor.cpp \
    src/core.cpp \
    src/tools/QGraphicsMapScene.cpp \
    src/dialogimportproject.cpp

HEADERS  += src/mainwindow.h \
    src/dialogresourcemanager.h \
    src/dialogdatabase.h \
    src/gamecharacter.h \
    src/gamecharactermodel.h \
    src/dialogimportimage.h \
    src/dialognewproject.h \
    src/tools/QGraphicsImportItem.h \
    src/tools/picojson.h \
    src/dialogopenproject.h \
    src/musicplayer.h \
    src/tools/QGraphicsPaleteScene.h \
    src/volumebutton.h \
    src/command_codes.h \
    src/data.h \
    src/ini.h \
    src/inireader.h \
    src/ldb_chunks.h \
    src/ldb_reader.h \
    src/lmt_chunks.h \
    src/lmt_reader.h \
    src/lmu_chunks.h \
    src/lmu_reader.h \
    src/lsd_chunks.h \
    src/lsd_reader.h \
    src/reader_lcf.h \
    src/reader_options.h \
    src/reader_struct.h \
    src/reader_types.h \
    src/reader_util.h \
    src/reader_xml.h \
    src/rpg_actor.h \
    src/rpg_animation.h \
    src/rpg_animationcelldata.h \
    src/rpg_animationframe.h \
    src/rpg_animationtiming.h \
    src/rpg_attribute.h \
    src/rpg_battlecommand.h \
    src/rpg_battlecommands.h \
    src/rpg_battleranimation.h \
    src/rpg_battleranimationdata.h \
    src/rpg_battleranimationextension.h \
    src/rpg_chipset.h \
    src/rpg_class.h \
    src/rpg_commonevent.h \
    src/rpg_database.h \
    src/rpg_encounter.h \
    src/rpg_enemy.h \
    src/rpg_enemyaction.h \
    src/rpg_equipment.h \
    src/rpg_event.h \
    src/rpg_eventcommand.h \
    src/rpg_eventpage.h \
    src/rpg_eventpagecondition.h \
    src/rpg_item.h \
    src/rpg_itemanimation.h \
    src/rpg_learning.h \
    src/rpg_map.h \
    src/rpg_mapinfo.h \
    src/rpg_movecommand.h \
    src/rpg_moveroute.h \
    src/rpg_music.h \
    src/rpg_parameters.h \
    src/rpg_rect.h \
    src/rpg_save.h \
    src/rpg_saveactor.h \
    src/rpg_savecommonevent.h \
    src/rpg_saveeventcommands.h \
    src/rpg_saveeventdata.h \
    src/rpg_saveevents.h \
    src/rpg_saveinventory.h \
    src/rpg_savemapevent.h \
    src/rpg_savemapinfo.h \
    src/rpg_savepartylocation.h \
    src/rpg_savepicture.h \
    src/rpg_savescreen.h \
    src/rpg_savesystem.h \
    src/rpg_savetarget.h \
    src/rpg_savetitle.h \
    src/rpg_savevehiclelocation.h \
    src/rpg_skill.h \
    src/rpg_sound.h \
    src/rpg_start.h \
    src/rpg_state.h \
    src/rpg_switch.h \
    src/rpg_system.h \
    src/rpg_terms.h \
    src/rpg_terrain.h \
    src/rpg_testbattler.h \
    src/rpg_treemap.h \
    src/rpg_troop.h \
    src/rpg_troopmember.h \
    src/rpg_trooppage.h \
    src/rpg_trooppagecondition.h \
    src/rpg_variable.h \
    src/writer_lcf.h \
    src/writer_xml.h \
    src/boost/preprocessor/cat.hpp \
    src/boost/preprocessor/stringize.hpp \
    src/boost/preprocessor/config/config.hpp \
    src/core.h \
    src/tools/QGraphicsMapScene.h \
    src/dialogimportproject.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui \
    src/dialogopenproject.ui \
    src/dialogimportproject.ui

RESOURCES += \
    src/Resources.qrc

win32:CONFIG(release, debug|release): LIBS += -LC:/Expat/Bin/ -llibexpat
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Expat/Bin/ -llibexpat

INCLUDEPATH += C:/Expat/Source/lib
DEPENDPATH += C:/Expat/Source/lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/Expat/Bin/liblibexpat.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/Expat/Bin/liblibexpat.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/Expat/Bin/libexpat.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/Expat/Bin/libexpat.lib
