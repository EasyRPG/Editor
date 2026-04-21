// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.ComboBox {
    id: root

    property string key
    property Ez.JsonView jsonData

    textRole: "display"
    valueRole: "identifier"

    property string fallbackString: ""

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
                console.log("Warning: Value " + jsonData.num(key) + " not found in ComboBox model for key " + key)
            }
        }
    }

    onModelChanged: applyFallbackString()
    onFallbackStringChanged: applyFallbackString()

    function applyFallbackString() {
        root.model.fallbackString = root.fallbackString
    }
}
