// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.SpinBox {
    id: root

    property string key
    property Ez.JsonView jsonData

    onKeyChanged: updateData()
    onJsonDataChanged: updateData()

    property string prefix: ""
    property string suffix: ""

    onValueChanged: {
        if (jsonData !== null && key !== "") {
            jsonData.set(key, value)
        }
    }

    Component.onCompleted: {
        updateData()
    }

    function updateData() {
        if (jsonData !== null && key !== "") {
            value = jsonData.num(key)
        } else {
            value = 0;
        }
    }

    textFromValue: function(value, locale) {
        return prefix + Number(value).toLocaleString(locale, 'f', 0) + suffix;
    }

    valueFromText: function(text, locale) {
        if (prefix !== "" && text.startsWith(prefix)) {
            text = text.substring(prefix.length);
        }

        if (suffix !== "" && text.endsWith(suffix)) {
            text = text.substring(0, text.length - suffix.length);
        }

        return Number.fromLocaleString(locale, text);
    }
}
