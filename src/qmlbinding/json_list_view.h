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
#include <QtQmlIntegration>
#include <QAbstractItemModel>
#include <lcf/dbstring.h>
#include "common/dbstring.h"

#include "json_view.h"

class JsonListView : public QAbstractListModel {
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(int fallbackValue MEMBER m_fallbackValue NOTIFY fallbackValueChanged)
	Q_PROPERTY(QString fallbackString MEMBER m_fallbackString NOTIFY fallbackStringChanged)

public:
	enum RoleNames {
		NameRole = Qt::UserRole + 1,
		TitleRole,
		IndexRole,
		IdRole
	};

	explicit JsonListView(QObject* parent = nullptr) : QAbstractListModel(parent) {}

	Q_INVOKABLE virtual QString str(QString) const;
	Q_INVOKABLE virtual int num(QString) const;
	Q_INVOKABLE virtual bool boolean(QString) const;
	Q_INVOKABLE virtual void set(QString, const QVariant&);
	Q_INVOKABLE virtual JsonView* subtree(QString);
	Q_INVOKABLE virtual JsonListView* list(QString);
	Q_INVOKABLE virtual QString toJson(QString jsonPtr) const;

	// QAbstractListModel overrides
	QHash<int, QByteArray> roleNames() const override;

	// Stub implementations to make JsonListView default constructable for QML
	// Actual implementation in JsonListViewT
	int rowCount(const QModelIndex& = QModelIndex()) const override { return -1; }
	QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override { return {}; };
	bool insertRows(int, int, const QModelIndex& = QModelIndex()) override { return false; };

	JsonView* view() const { return m_view; }
	void setView(JsonView* view) { m_view = view; }

	bool hasFallback() const {
		return !m_fallbackString.isEmpty();
	}

public slots:
	void onValueChanged(QString jsonPtr);

signals:
	void dataChanged();
	void fallbackValueChanged();
	void fallbackStringChanged();

protected:
	JsonView* m_view = nullptr;
	int m_fallbackValue = 0;
	QString m_fallbackString;
};

template<typename LCFTYPE>
class JsonListViewT : public JsonListView {
public:
	explicit JsonListViewT(QObject* parent, std::vector<LCFTYPE>* data, JsonView* view) :
	JsonListView(parent), m_data(data) {
		m_view = view;
		assert(view);

		// Listen to all changes in the attached JsonView object
		connect(view, &JsonView::valueChanged, this, &JsonListView::onValueChanged);
	}

	// QAbstractListModel overrides
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

	std::vector<LCFTYPE>* data() const { return m_data; }
	void setData(std::vector<LCFTYPE>* data) { m_data = data; }

private:
	std::vector<LCFTYPE>* m_data = nullptr;
};

template<typename LCFTYPE>
inline int JsonListViewT<LCFTYPE>::rowCount(const QModelIndex &parent) const {
	return m_data->size() + (hasFallback() ? 1 : 0);
}

template<typename LCFTYPE>
inline QVariant JsonListViewT<LCFTYPE>::data(const QModelIndex &index, int role) const {
	if (!index.isValid() || index.row() >= rowCount(index)) {
	    return QVariant();
	}

	std::string role_str;

	switch (role) {
		case NameRole:
			role_str = "name";
			break;
		case TitleRole:
			role_str = "title";
			break;
		case IdRole:
			role_str = "ID";
			break;
		case IndexRole:
			return QVariant::fromValue(index.row());
		case Qt::DisplayRole: {
			auto id = data(index, IdRole);
			auto name = data(index, NameRole);
			auto s = QString("%1: %2").arg(id.toInt(), 4, 10, u'0').arg(name.toString());
			return QVariant::fromValue(s);
		}
		default:
			return QVariant();
	}

	if (hasFallback() && index.row() == 0) {
		switch (role) {
			case NameRole:
				return QVariant::fromValue(m_fallbackString);
			case IdRole:
				return QVariant::fromValue(m_fallbackValue);
			default:
				return {};
		}
	}

	// Shift row back in case of fallback
	int row = index.row();
	if (hasFallback()) {
		--row;
	}

	role_str = std::format("/{}/{}", row, role_str);

	auto res = glz::get<lcf::DBString>(*m_data, role_str);
	if (res.has_value()) {
		return QVariant::fromValue(ToQString(res.value()));
	}

	auto res2 = glz::get<int>(*m_data, role_str);
	if (res2.has_value()) {
		return QVariant::fromValue(res2.value().get());
	}

	return {};
}

template<typename LCFTYPE>
inline bool JsonListViewT<LCFTYPE>::insertRows(int row, int count, const QModelIndex &parent) {
	if (row < 0 || row > rowCount()) {
		return false;
	}

	m_data->insert(m_data->begin() + row, LCFTYPE{});

	return true;
}
