// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.ComboBox {
    id: root

    property string key
    property var jsonData

    textRole: "text" // In a JsonListView this is "ID: NAME", e.g. "0001: Aina"
    valueRole: "value" // In a JsonListView is the "ID"

    onActivated: {
        if (jsonData !== null && key !== "") {
            jsonData.set(key, currentValue)
        }
    }

    Component.onCompleted: {
        onDataChanged()
    }

    function onDataChanged() {
        if (jsonData !== null && key !== "") {
            currentIndex = indexOfValue(jsonData.num(key))
            if (currentIndex === -1) {
                console.log(`ComboBox: ${jsonData.num(key)} not found for ${key}`);

                let isProxy = (root.model.sourceModel !== undefined);
                let model = isProxy ? root.model.sourceModel : root.model;

                if (model.fallbackString !== "") {
                    currentIndex = indexOfValue(model.fallbackValue);
                }
            }
        }
    }
}
