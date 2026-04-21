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

    Kirigami.FormLayout {
        anchors.fill: parent

        Ez.TextField {
            jsonData: root.jsonData
            key: "name"
            Kirigami.FormData.label: "Name:"
        }

        Ez.TextField {
            jsonData: root.jsonData
            key: "title"
            Kirigami.FormData.label: "Title:"
        }

        RowLayout {
            Kirigami.FormData.label: "Level:"

            Controls.Label {
                text: "From:"
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "initial_level"
            }

            Controls.Label {
                text: "To:"
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "final_level"
            }
        }

        RowLayout {
            Kirigami.FormData.label: "Crit:"
            Ez.CheckBox {
                id: critical_hit_cb
                jsonData: root.jsonData
                key: "critical_hit"
            }

            Controls.Label {
                text: "One in:"
                enabled: critical_hit_cb.checked
            }

            Ez.SpinBox {
                jsonData: root.jsonData
                key: "critical_hit_chance"
                enabled: critical_hit_cb.checked
            }
        }


        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Equipment"
        }

        Ez.ComboBox {
            jsonData: root.jsonData
            key: "initial_equipment/weapon_id"
            Kirigami.FormData.label: "Weapon Type:"
            model: Ez.ProjectData.database().list("items")
            fallbackString: "(None)"
        }
    }
}
