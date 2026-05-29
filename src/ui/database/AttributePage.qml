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

    Ez.GridLaneLayout {
        id: cardLayout
        model: [card_general, card_dmg]
    }

    Component {
        id: card_general
        Ez.Card {
            title: qsTr("General")

            Ez.TextField {
                jsonData: root.jsonData
                key: "name"
                Kirigami.FormData.label: qsTr("Name")
            }

            ColumnLayout {
                Kirigami.FormData.label: qsTr("Attribute Type")
                Kirigami.FormData.buddyFor: radio_physical
                Ez.RadioButton {
                    id: radio_physical
                    jsonData: root.jsonData
                    key: "type"
                    text: qsTr("Physical")
                    value: 0
                }
                Ez.RadioButton {
                    jsonData: root.jsonData
                    key: "type"
                    text: qsTr("Magical")
                    value: 1
                }
            }
        }
    }

    Component {
        id: card_dmg
        Ez.Card {
            title: qsTr("Damage Multipliers")

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "a_rate"
                Kirigami.FormData.label: qsTr("A Rate")
                from: -9999
                to: 9999
                suffix: qsTr("%")
                Layout.fillWidth: true
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "b_rate"
                Kirigami.FormData.label: qsTr("B Rate")
                from: -9999
                to: 9999
                suffix: qsTr("%")
                Layout.fillWidth: true
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "c_rate"
                Kirigami.FormData.label: qsTr("C Rate")
                from: -9999
                to: 9999
                suffix: qsTr("%")
                Layout.fillWidth: true
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "d_rate"
                Kirigami.FormData.label: qsTr("D Rate")
                from: -9999
                to: 9999
                suffix: qsTr("%")
                Layout.fillWidth: true
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "e_rate"
                Kirigami.FormData.label: qsTr("E Rate")
                from: -9999
                to: 9999
                suffix: qsTr("%")
                Layout.fillWidth: true
            }
        }
    }
}
