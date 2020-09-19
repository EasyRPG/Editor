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

#include <lcf/rpg/database.h>
#include <lcf/rpg/terrain.h>
#include "rpg_base.h"

/**
 * A thin wrapper around lcf::rpg::Terrain
 */
class Terrain : public RpgBase
{
public:
	Terrain(lcf::rpg::Terrain& data, lcf::rpg::Database& database);

	lcf::rpg::Terrain& data();

	QPixmap preview() override;

	QDialog* edit(QWidget* parent = nullptr) override;

private:
	lcf::rpg::Terrain& m_data;
	lcf::rpg::Database& database;
};

