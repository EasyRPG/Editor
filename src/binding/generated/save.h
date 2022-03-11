/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Headers
#include <lcf/rpg/save.h>
#include "binding/binding_base.h"
#include "binding/saveactor.h"
#include "binding/savevehiclelocation.h"
#include "binding/savevehiclelocation.h"
#include "binding/savecommonevent.h"
#include "binding/saveeasyrpgdata.h"
#include "binding/saveeventexecstate.h"
#include "binding/saveinventory.h"
#include "binding/savemapinfo.h"
#include "binding/savepanorama.h"
#include "binding/savepartylocation.h"
#include "binding/savepicture.h"
#include "binding/savescreen.h"
#include "binding/savevehiclelocation.h"
#include "binding/savesystem.h"
#include "binding/savetarget.h"
#include "binding/savetitle.h"

class ProjectData;

/**
 * Binding::Generated::Save class.
 * Exposes lcf::rpg::Save to QML.
 */
namespace Binding::Generated {
class Save : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(Binding::SaveTitle* title READ title CONSTANT)
	Q_PROPERTY(Binding::SaveSystem* system READ system CONSTANT)
	Q_PROPERTY(Binding::SaveScreen* screen READ screen CONSTANT)
	Q_PROPERTY(QVector<Binding::SavePicture*> pictures READ pictures CONSTANT)
	Q_PROPERTY(Binding::SavePartyLocation* party_location READ party_location CONSTANT)
	Q_PROPERTY(Binding::SaveVehicleLocation* boat_location READ boat_location CONSTANT)
	Q_PROPERTY(Binding::SaveVehicleLocation* ship_location READ ship_location CONSTANT)
	Q_PROPERTY(Binding::SaveVehicleLocation* airship_location READ airship_location CONSTANT)
	Q_PROPERTY(QVector<Binding::SaveActor*> actors READ actors CONSTANT)
	Q_PROPERTY(Binding::SaveInventory* inventory READ inventory CONSTANT)
	Q_PROPERTY(QVector<Binding::SaveTarget*> targets READ targets CONSTANT)
	Q_PROPERTY(Binding::SaveMapInfo* map_info READ map_info CONSTANT)
	Q_PROPERTY(Binding::SavePanorama* panorama READ panorama CONSTANT)
	Q_PROPERTY(Binding::SaveEventExecState* foreground_event_execstate READ foreground_event_execstate CONSTANT)
	Q_PROPERTY(QVector<Binding::SaveCommonEvent*> common_events READ common_events CONSTANT)
	Q_PROPERTY(Binding::SaveEasyRpgData* easyrpg_data READ easyrpg_data CONSTANT)

public:
	Save(ProjectData& project, lcf::rpg::Save& data, QObject* parent = nullptr);

	lcf::rpg::Save& data();
	Binding::SaveTitle* title();
	Binding::SaveSystem* system();
	Binding::SaveScreen* screen();
	QVector<Binding::SavePicture*>& pictures();
	Binding::SavePartyLocation* party_location();
	Binding::SaveVehicleLocation* boat_location();
	Binding::SaveVehicleLocation* ship_location();
	Binding::SaveVehicleLocation* airship_location();
	QVector<Binding::SaveActor*>& actors();
	Binding::SaveInventory* inventory();
	QVector<Binding::SaveTarget*>& targets();
	Binding::SaveMapInfo* map_info();
	Binding::SavePanorama* panorama();
	Binding::SaveEventExecState* foreground_event_execstate();
	QVector<Binding::SaveCommonEvent*>& common_events();
	Binding::SaveEasyRpgData* easyrpg_data();

signals:

protected:
	lcf::rpg::Save& m_data;
	Binding::SaveTitle* m_title;
	Binding::SaveSystem* m_system;
	Binding::SaveScreen* m_screen;
	QVector<Binding::SavePicture*> m_pictures;
	Binding::SavePartyLocation* m_party_location;
	Binding::SaveVehicleLocation* m_boat_location;
	Binding::SaveVehicleLocation* m_ship_location;
	Binding::SaveVehicleLocation* m_airship_location;
	QVector<Binding::SaveActor*> m_actors;
	Binding::SaveInventory* m_inventory;
	QVector<Binding::SaveTarget*> m_targets;
	Binding::SaveMapInfo* m_map_info;
	Binding::SavePanorama* m_panorama;
	Binding::SaveEventExecState* m_foreground_event_execstate;
	QVector<Binding::SaveCommonEvent*> m_common_events;
	Binding::SaveEasyRpgData* m_easyrpg_data;
};
} // namespace Binding::Generated
