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
        Models.ListElement { value: 0; text: "Normal" }
        Models.ListElement { value: 1; text: "Teleport" }
        Models.ListElement { value: 2; text: "Escape" }
        Models.ListElement { value: 3; text: "Switch" }
    }

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

        Ez.ComboBox {
            id: cbType
            jsonData: root.jsonData
            key: "type"
            Kirigami.FormData.label: "Type: "
            model: typeModel
        }
    }
}
