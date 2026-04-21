// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import QtQuick.Dialogs as Dialogs
import QtQml.Models as Models
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

DatabaseEntryPage {
    id: root

    Models.ListModel {
        id: rateModel
        Models.ListElement { key: "a_rate"; label: "A Rate:" }
        Models.ListElement { key: "b_rate"; label: "B Rate:" }
        Models.ListElement { key: "c_rate"; label: "C Rate:" }
        Models.ListElement { key: "d_rate"; label: "D Rate:" }
        Models.ListElement { key: "e_rate"; label: "E Rate:" }
    }

    Kirigami.FormLayout {
        anchors.fill: parent

        Ez.TextField {
            jsonData: root.jsonData
            key: "name"
            Kirigami.FormData.label: "Name:"
        }

        ColumnLayout {
            Kirigami.FormData.label: "Attribute Type:"
            Kirigami.FormData.buddyFor: radio_physical
            Ez.RadioButton {
                id: radio_physical
                jsonData: root.jsonData
                key: "type"
                text: "Physical"
                value: 0
            }
            Ez.RadioButton {
                jsonData: root.jsonData
                key: "type"
                text: "Magical"
                value: 1
            }
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Damage Multipliers"
        }

        Repeater {
            model: rateModel

            Ez.SpinBox {
                jsonData: root.jsonData
                key: model.key
                Kirigami.FormData.label: model.label
                from: -9999
                to: 9999
            }
        }
    }
}
