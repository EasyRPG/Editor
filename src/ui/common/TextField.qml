// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.TextField {
    id: root

    property string key
    property Ez.JsonView jsonData

    onKeyChanged: updateData()
    onJsonDataChanged: updateData()

    onTextEdited: {
        if (jsonData !== null && key !== "") {
            jsonData.set(key, text)
        }
    }

    Component.onCompleted: {
        updateData()
    }

    function updateData() {
        if (jsonData !== null && key !== "") {
            let jsonText = jsonData.str(key);
            if (text !== jsonText) {
                text = jsonText;
            }
        } else {
            text = "";
        }
    }
}
