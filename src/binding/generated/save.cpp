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

// Headers
#include "save.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Save::Save(ProjectData& project, lcf::rpg::Save& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_title = new Binding::SaveTitle(m_project, m_data.title, this);
		m_system = new Binding::SaveSystem(m_project, m_data.system, this);
		m_screen = new Binding::SaveScreen(m_project, m_data.screen, this);
		{
			m_pictures = new ArrayAdapter(this);
			auto& arr = m_pictures->data();
			for (auto& var: m_data.pictures)
				arr.push_back(new Binding::SavePicture(m_project, var, this));
		}
		m_party_location = new Binding::SavePartyLocation(m_project, m_data.party_location, this);
		m_boat_location = new Binding::SaveVehicleLocation(m_project, m_data.boat_location, this);
		m_ship_location = new Binding::SaveVehicleLocation(m_project, m_data.ship_location, this);
		m_airship_location = new Binding::SaveVehicleLocation(m_project, m_data.airship_location, this);
		{
			m_actors = new ArrayAdapter(this);
			auto& arr = m_actors->data();
			for (auto& var: m_data.actors)
				arr.push_back(new Binding::SaveActor(m_project, var, this));
		}
		m_inventory = new Binding::SaveInventory(m_project, m_data.inventory, this);
		{
			m_targets = new ArrayAdapter(this);
			auto& arr = m_targets->data();
			for (auto& var: m_data.targets)
				arr.push_back(new Binding::SaveTarget(m_project, var, this));
		}
		m_map_info = new Binding::SaveMapInfo(m_project, m_data.map_info, this);
		m_panorama = new Binding::SavePanorama(m_project, m_data.panorama, this);
		m_foreground_event_execstate = new Binding::SaveEventExecState(m_project, m_data.foreground_event_execstate, this);
		{
			m_common_events = new ArrayAdapter(this);
			auto& arr = m_common_events->data();
			for (auto& var: m_data.common_events)
				arr.push_back(new Binding::SaveCommonEvent(m_project, var, this));
		}
		m_easyrpg_data = new Binding::SaveEasyRpgData(m_project, m_data.easyrpg_data, this);
	}
	Binding::SaveTitle* Save::title() {
		return m_title;
	}

	Binding::SaveSystem* Save::system() {
		return m_system;
	}

	Binding::SaveScreen* Save::screen() {
		return m_screen;
	}

	ArrayAdapter* Save::pictures() {
		return m_pictures;
	}

	Binding::SavePartyLocation* Save::party_location() {
		return m_party_location;
	}

	Binding::SaveVehicleLocation* Save::boat_location() {
		return m_boat_location;
	}

	Binding::SaveVehicleLocation* Save::ship_location() {
		return m_ship_location;
	}

	Binding::SaveVehicleLocation* Save::airship_location() {
		return m_airship_location;
	}

	ArrayAdapter* Save::actors() {
		return m_actors;
	}

	Binding::SaveInventory* Save::inventory() {
		return m_inventory;
	}

	ArrayAdapter* Save::targets() {
		return m_targets;
	}

	Binding::SaveMapInfo* Save::map_info() {
		return m_map_info;
	}

	Binding::SavePanorama* Save::panorama() {
		return m_panorama;
	}

	Binding::SaveEventExecState* Save::foreground_event_execstate() {
		return m_foreground_event_execstate;
	}

	ArrayAdapter* Save::common_events() {
		return m_common_events;
	}

	Binding::SaveEasyRpgData* Save::easyrpg_data() {
		return m_easyrpg_data;
	}

} // namespace Binding::Generated
