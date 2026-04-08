// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as Controls
import org.easyrpg.editor as Ez

Controls.TextField {
    id: root

    property string key
    property Ez.JsonView jsonData

    onTextChanged: {
    	//console.log("Text changed to:", key, jsonData, text)
    	if (jsonData !== null && key !== "") {
    		jsonData.set(key, text)
    	}
    }

    Component.onCompleted: {
        onDataChanged()
    }

    function onDataChanged() {
    	//console.log("data changed", jsonData.str(key))
    	text = jsonData.str(key)
    }
}
