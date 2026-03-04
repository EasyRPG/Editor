// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

DatabaseEntryPage {
    id: root

    property var jsonKeys:[]

    // Just for demonstration
    // The finished Ui should not be auto-generated :)

    Kirigami.FormLayout {
        anchors.fill: parent

        Repeater {
            model: root.jsonKeys

            delegate: Ez.TextField {
                jsonData: root.jsonData

                key: modelData
                Kirigami.FormData.label: modelData
            }
        }
    }

    Component.onCompleted: {
        let rawString = root.jsonData.toJson()
        console.log(rawString)

        let parsedObj = JSON.parse(rawString)
        root.jsonKeys = Object.keys(parsedObj)
    }
}
