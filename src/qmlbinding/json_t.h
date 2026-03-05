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

#include "json.h"

#include <lcf/rpg/database.h>
#include <lcf/rpg/map.h>
#include <lcf/rpg/treemap.h>

template<typename LCFTYPE>
class JsonT : public Json {
public:
	explicit JsonT(QObject* parent = nullptr);

	QString str(QString jsonPtr) const override;
	int num(QString jsonPtr) const override;
	bool boolean(QString jsonPtr) const override;
	void set(QString jsonPtr, const QVariant& value) override;
	QVariant subtree(QString jsonPtr) override;
	QVariant list(QString jsonPtr) override;
	QString toJson(QString jsonPtr) const override;
	void setData(LCFTYPE* data);

private:
	LCFTYPE* m_data = nullptr;
};

extern template class JsonT<lcf::rpg::Database>;
extern template class JsonT<lcf::rpg::TreeMap>;
extern template class JsonT<lcf::rpg::Map>;
