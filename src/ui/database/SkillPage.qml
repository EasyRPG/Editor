// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import QtQml.Models as Models
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

DatabaseEntryPage {
    id: root

    Models.ListModel {
        id: typeModel
        Models.ListElement { value: 0; text: qsTr("Normal") }
        Models.ListElement { value: 1; text: qsTr("Teleport") }
        Models.ListElement { value: 2; text: qsTr("Escape") }
        Models.ListElement { value: 3; text: qsTr("Switch") }
    }

    Ez.FormLayout {
        anchors.fill: parent

        Ez.TextField {
            jsonData: root.jsonData
            key: "name"
            Kirigami.FormData.label: qsTr("Name")
        }

        Ez.TextField {
            jsonData: root.jsonData
            key: "description"
            Kirigami.FormData.label: qsTr("Description")
        }

        Ez.ComboBox {
            id: cbType
            jsonData: root.jsonData
            key: "type"
            Kirigami.FormData.label: qsTr("Type")
            model: typeModel
        }
    }
}
