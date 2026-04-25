// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.CheckBox {
    id: root

    property string key
    property Ez.JsonView jsonData

    onToggled: {
        if (jsonData !== null && key !== "") {
            jsonData.set(key, checked);
        }
    }

    Component.onCompleted: {
        onDataChanged()
    }

    function onDataChanged() {
        if (jsonData !== null && key !== "") {
            checked = jsonData.boolean(key);
        } else {
            checked = false;
        }
    }
}
