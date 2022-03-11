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

#include <QObject>
#include <QQmlPropertyMap>
#include <lcf/rpg/database.h>
#include <lcf/rpg/treemap.h>
#include "binding/database.h"
#include "binding/treemap.h"

class Project;
class ProjectData;

class ProjectBinding : public QObject {
	Q_OBJECT
	Q_PROPERTY(Binding::Database* database READ databaseModel CONSTANT)
	Q_PROPERTY(Binding::TreeMap* treemap READ treeModel CONSTANT)
public:
	ProjectBinding(ProjectData& project_data, QObject* parent = nullptr);

	~ProjectBinding();

	Binding::Database* databaseModel() {
		return m_database_model;
	}

	Binding::TreeMap* treeModel() {
		return m_tree_model;
	}

private:
	ProjectData& m_project_data;

	Binding::Database* m_database_model = nullptr;
	Binding::TreeMap* m_tree_model = nullptr;
};

class ProjectData {
public:
	ProjectData() = default;
	explicit ProjectData(Project& project);
	ProjectData(Project& project, lcf::rpg::Database database, lcf::rpg::TreeMap treemap);

	lcf::rpg::Database& database() {
		return m_database;
	}

	const lcf::rpg::Database& database() const {
		return m_database;
	}

	lcf::rpg::TreeMap& treeMap() {
		return m_treemap;
	}

	const lcf::rpg::TreeMap& treeMap() const {
		return m_treemap;
	}

	const Project& project() const {
		return *m_project;
	}

private:
	Project* m_project = nullptr;
	lcf::rpg::Database m_database;
	lcf::rpg::TreeMap m_treemap;
};
