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

#include "json_seek.h"
#include "json_view.h"
#include "json_list_view.h"
#include "lcf_glaze.h"

// Without this filter glz::seek has an awful compile time performance because
// we have so many structs in lcf::rpg::Database
// Opt-in here for all structs that use JsonViewT functionality in QML code
template<typename T>
concept LcfStructFilter =
	std::same_as<T, lcf::rpg::Terms>;

template <typename T>
concept IsVector = requires {
    typename T::value_type;
} && std::is_class_v<typename T::value_type>;

template<typename LCFTYPE>
JsonListView* lcf_seek_list_impl(LCFTYPE* data, const QString& jsonPtr, Json* parent) {
	JsonListView* list_view = nullptr;

	glz::seek([&](auto& val) {
		using T = std::decay_t<decltype(val)>;

		if constexpr (IsVector<T>) {
			auto view = new JsonView(parent);
			view->setPathPrefix(jsonPtr);
			list_view = new JsonListViewT<typename T::value_type>(parent, &val, view);
		}
	}, *data, jsonPtr.toStdString());

	return list_view;
}

template<typename LCFTYPE>
JsonView* lcf_seek_subtree_impl(LCFTYPE* data, const QString& jsonPtr, Json* parent) {
	JsonView* view = nullptr;

	glz::seek([&](auto& val) {
		using T = std::decay_t<decltype(val)>;

		if constexpr (LcfStructFilter<T>) {
			view = new JsonViewT<LCFTYPE, T>(parent);
			view->setPathPrefix(jsonPtr);
		}
	}, *data, jsonPtr.toStdString());

	if (view == nullptr) {
		view = new JsonView(parent);
		view->setPathPrefix(jsonPtr);
	}

	return view;
}
