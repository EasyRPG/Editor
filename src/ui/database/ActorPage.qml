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
        id: equipmentModel
        Models.ListElement { key: "weapon_id"; label: "Weapon:"; type: 1 }
        Models.ListElement { key: "shield_id"; label: "Shield:"; type: 2 }
        Models.ListElement { key: "armor_id"; label: "Armor:"; type: 3 }
        Models.ListElement { key: "helmet_id"; label: "Helmet:"; type: 4 }
        Models.ListElement { key: "accessory_id"; label: "Accessory:"; type: 5 }
    }

    /*property Ez.PickerData charsetPickerData: Ez.PickerData {
        index: charsetViewer.characterIndex
        Component.onCompleted: filename = charsetViewer.filename
    }

    property Component charsetPickerComponent: Ez.ImagePicker {
        onAccepted: {
            charsetViewer.filename = pickerData.filename
            charsetViewer.characterIndex = pickerData.index
            root.jsonData.set("character_name", pickerData.filename)
            root.jsonData.set("character_index", pickerData.index)
        }
    }*/

    Kirigami.FormLayout {
        id: form1
        Layout.fillWidth: true

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "General"
        }

        Ez.TextField {
            jsonData: root.jsonData
            key: "name"
            Kirigami.FormData.label: "Name:"
            Layout.fillWidth: true
        }

        Ez.TextField {
            jsonData: root.jsonData
            key: "title"
            Kirigami.FormData.label: "Title:"
            Layout.fillWidth: true
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
            Kirigami.FormData.label: "Graphics"
        }

        Ez.FaceSetViewer {
            id: faceViewer
            Kirigami.FormData.label: "Face:"

            filename: root.jsonData.str("face_name")
            cellIndex: root.jsonData.num("face_index")

            pickerData: Ez.PickerData {
                index: faceViewer.cellIndex
                Component.onCompleted: filename = faceViewer.filename
            }

            onAccepted: {
                faceViewer.filename = pickerData.filename
                faceViewer.cellIndex = pickerData.index
                root.jsonData.set("face_name", pickerData.filename)
                root.jsonData.set("face_index", pickerData.index)
            }
        }

        Ez.CharSetViewer {
            id: charViewer
            Kirigami.FormData.label: "Character:"

            spin: true
            walk: true
            filename: root.jsonData.str("character_name")
            cellIndex: root.jsonData.num("character_index")
            transparent: root.jsonData.boolean("transparent")

            pickerData: Ez.PickerData {
                index: charViewer.cellIndex
                transparent: charViewer.transparent
                Component.onCompleted: filename = charViewer.filename
            }

            onAccepted: {
                charViewer.filename = pickerData.filename
                charViewer.cellIndex = pickerData.index
                charViewer.transparent = pickerData.transparent
                root.jsonData.set("character_name", pickerData.filename)
                root.jsonData.set("character_index", pickerData.index)
                root.jsonData.set("transparent", pickerData.transparent)
            }
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Equipment"
        }

        Repeater {
            id: equipmentRepeater
            model: equipmentModel

            Ez.ComboBox {
                readonly property var repdata: equipmentRepeater.model.get(index)
                Layout.fillWidth: true
                jsonData: root.jsonData
                key: "initial_equipment/" + repdata.key
                Kirigami.FormData.label: repdata.label
                model: {
                    let filter = Ez.ProjectData.actorModel(root.objIndex).CreateEquipmentFilter(repdata.type);
                    let list = Ez.ProjectData.database().list("items");
                    list.fallbackString = "(None)";
                    filter.sourceModel = list;
                    return filter;
                }
            }
        }
    }
}
