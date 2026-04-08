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
    	//console.log("Text changed to:", text)
    	if (jsonData !== null && key !== "") {
    		jsonData.set(key, checkState);
    	}
    }

    Component.onCompleted: {
        onDataChanged()
    }

    function onDataChanged() {
    	checkState = (jsonData.boolean(key));
    }
}
