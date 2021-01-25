/*
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

#include <lcf/rpg/eventcommand.h>
#include <vector>

class EventCommandList {
public:
	EventCommandList() {};
	EventCommandList(std::vector<lcf::rpg::EventCommand>& commands, int current_index);

	std::vector<lcf::rpg::EventCommand>& commands();
	const std::vector<lcf::rpg::EventCommand>& commands() const;

	lcf::rpg::EventCommand& command();
	const lcf::rpg::EventCommand& command() const;

	size_t size() const;

	int index() const;

private:
	std::vector<lcf::rpg::EventCommand>* m_commands = nullptr;
	int m_current_index = 0;
};
