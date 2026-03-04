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

#include "json_view.h"
#include "json_list_view.h"
#include "json.h"

namespace {
	QString makePath(const QString& left, const QString& right) {
		assert(!left.isEmpty() && !right.isEmpty());
		assert(!right.endsWith('/'));

		// normalize the path: Ensure initial / and avoid double /
		QString out;

		bool slash_l = left.endsWith('/');
		bool slash_r = right.startsWith('/');

		if (!slash_l && !slash_r) {
			out = left + '/' + right;
		} else if (slash_l && slash_r) {
			out = left + right.mid(1);
		} else {
			out = left + right;
		}

		//qDebug() << left << " " << right << " " << out;

		return out;
	}
}

QString JsonView::str(QString jsonPtr) const {
	return static_cast<Json*>(parent())->str(makePath(m_pathPrefix, jsonPtr));
}

int JsonView::num(QString jsonPtr) const {
	return static_cast<Json*>(parent())->num(makePath(m_pathPrefix, jsonPtr));
}

bool JsonView::boolean(QString jsonPtr) const {
	return static_cast<Json*>(parent())->boolean(makePath(m_pathPrefix, jsonPtr));
}

void JsonView::set(QString jsonPtr, const QVariant& value) {
	static_cast<Json*>(parent())->set(makePath(m_pathPrefix, jsonPtr), value);
}

JsonView* JsonView::subtree(QString jsonPtr) {
	return qvariant_cast<JsonView*>(static_cast<Json*>(parent())->subtree(makePath(m_pathPrefix, jsonPtr)));
}

JsonListView* JsonView::list(QString jsonPtr) {
	return qvariant_cast<JsonListView*>(static_cast<Json*>(parent())->list(makePath(m_pathPrefix, jsonPtr)));
}

QString JsonView::pathPrefix() const {
	return m_pathPrefix;
}

void JsonView::setPathPrefix(QString prefix) {
	if (!prefix.startsWith('/')) {
		prefix.prepend('/');
	}

	if (prefix.endsWith('/')) {
		prefix.removeLast();
	}

	if (prefix.isEmpty()) {
		prefix = '/';
	}

	m_pathPrefix = prefix;
}
