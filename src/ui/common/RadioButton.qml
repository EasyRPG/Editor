// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.RadioButton {
    id: root

    property string key
    property Ez.JsonView jsonData

    property int value

    onKeyChanged: onDataChanged()
    onJsonDataChanged: onDataChanged()

    onCheckedChanged: {
        if (checked && jsonData !== null && key !== "") {
            jsonData.set(key, value)
        }
    }

    Component.onCompleted: {
        onDataChanged()
    }

    function onDataChanged() {
        checked = (jsonData.num(key) === value)
    }
}
