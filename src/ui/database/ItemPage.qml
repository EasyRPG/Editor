// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

DatabaseEntryPage {
    id: root

    property Ez.JsonView jsonData

    Kirigami.FormLayout {
        anchors.fill: parent

    	Ez.TextField {
    		jsonData: root.jsonData
    		key: "name"
    		Kirigami.FormData.label: "Name:"
    	}

    	Ez.TextField {
    		jsonData: root.jsonData
    		key: "description"
    		Kirigami.FormData.label: "Description:"
    	}
    }
}
