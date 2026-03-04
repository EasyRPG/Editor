// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.SpinBox {
    id: root

    property string key
    property Ez.JsonView jsonData

    onValueChanged: {
        if (jsonData !== null && key !== "") {
            jsonData.set(key, value)
        }
    }

    Component.onCompleted: {
        onDataChanged()
    }

    function onDataChanged() {
        value = jsonData.num(key)
    }
}
