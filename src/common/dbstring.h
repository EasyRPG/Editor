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

#include <string_view>
#include <lcf/dbstring.h>
#include <QString>
#include <QStringView>

inline QString ToQString(const std::string& s) {
	return QString::fromStdString(s);
}

inline QString ToQString(std::string_view s) {
	return QString::fromUtf8(s.data(), s.size());
}

inline QString ToQString(const lcf::DBString& s) {
	return QString::fromUtf8(s.c_str(), s.size());
}

inline lcf::DBString ToDBString(const QString& s) {
	return lcf::DBString(s.toStdString());
}
