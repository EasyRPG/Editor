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

#include "json_list_view.h"

QHash<int, QByteArray> JsonListView::roleNames() const {
    QHash<int, QByteArray> roles;
	roles[Qt::DisplayRole] = "text";
    roles[NameRole] = "name";
    roles[TitleRole] = "title";
	roles[IdRole] = "value";
	roles[IndexRole] = "index";
    return roles;
}
void JsonListView::onValueChanged(QString jsonPtr) {
	// No filtering required as the JsonView we listen on already does this
	// ptr looks like this: /INDEX/VALUE/
	// extract the index and notify a row change

	int slash_idx = jsonPtr.indexOf('/', 1);
	if (slash_idx != -1) {
		bool ok;
		int row = jsonPtr.mid(1, slash_idx - 1).toInt(&ok);
		if (ok) {
			if (hasFallback()) {
				row++;
			}
			QModelIndex idx = index(row, 0);
			emit QAbstractListModel::dataChanged(idx, idx);
		}
	}
}

QString JsonListView::str(QString jsonPtr) const {
	return m_view->str(jsonPtr);
}

int JsonListView::num(QString jsonPtr) const {
	return m_view->num(jsonPtr);
}

bool JsonListView::boolean(QString jsonPtr) const {
	return m_view->boolean(jsonPtr);
}

void JsonListView::set(QString jsonPtr, const QVariant& value) {
	return m_view->set(jsonPtr, value);
}

JsonView* JsonListView::subtree(QString jsonPtr) {
	return m_view->subtree(jsonPtr);
}

JsonListView* JsonListView::list(QString jsonPtr) {
	return m_view->list(jsonPtr);
}

QString JsonListView::toJson(QString jsonPtr) const {
	return m_view->toJson(jsonPtr);
}
