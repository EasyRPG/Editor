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

#include <QString>
#include "rpg_eventcommand.h"

namespace Stringizer {
	QString stringize(const RPG::EventCommand& com);

	// Common stringize operations
	QString varName(int id);
	QString switchName(int id);
	QString itemName(int id);
	QString heroName(int id);
	QString className(int id);
	QString stateName(int id);
	QString skillName(int id);
	QString battleCommandName(int id);
	QString animationName(int id);
	QString conditionName(int id);
	QString eventName(int id);
	QString commonEventName(int id);
	QString troopName(int id);
	QString terrainName(int id);
	QString mapName(int id);
	QString direction(int id);
	QString moveCommand(int id);
	QString eraseTransitionName(int id);
	QString showTransitionName(int id);
}
