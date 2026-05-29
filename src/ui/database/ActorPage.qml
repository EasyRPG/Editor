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

        model: [
            card_general,
            card_graphics,
            card_equipment
        ]
    }

    Component {
        id: card_general
        Ez.Card {
            title: qsTr("General")

            Ez.TextField {
                jsonData: root.jsonData
                key: "name"
                Kirigami.FormData.label: qsTr("Name")
                Layout.fillWidth: true
            }

            Ez.TextField {
                jsonData: root.jsonData
                key: "title"
                Kirigami.FormData.label: qsTr("Title")
                Layout.fillWidth: true
            }

            RowLayout {
                Kirigami.FormData.label: qsTr("Level")

                Controls.Label {
                    text: qsTr("From")
                }

                Ez.SpinBox {
                    jsonData: root.jsonData
                    key: "initial_level"
                }

                Controls.Label {
                    text: qsTr("To")
                }

                Ez.SpinBox {
                    jsonData: root.jsonData
                    key: "final_level"
                }
            }

            RowLayout {
                Kirigami.FormData.label: qsTr("Critical Hit Rate")
                Ez.CheckBox {
                    id: critical_hit_cb
                    jsonData: root.jsonData
                    key: "critical_hit"
                }

                Controls.Label {
                    text: qsTr("One in")
                    enabled: critical_hit_cb.checked
                }

                Ez.SpinBox {
                    jsonData: root.jsonData
                    key: "critical_hit_chance"
                    enabled: critical_hit_cb.checked
                }
            }
        }
    }

    Component {
        id: card_graphics
        Ez.Card {
            title: qsTr("Graphics")

            Ez.FaceSetViewer {
                id: faceViewer
                Kirigami.FormData.label: qsTr("Face")

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
                Kirigami.FormData.label: qsTr("Character")

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
        }
    }

    Component {
        id: card_equipment
        Ez.Card {
            title: qsTr("Equipment")

            Ez.ComboBox {
                Layout.fillWidth: true
                jsonData: root.jsonData
                key: "initial_equipment/weapon_id"
                Kirigami.FormData.label: qsTr("Weapon")
                model: {
                    let filter = Ez.ProjectData.actorModel(root.objIndex).CreateEquipmentFilter(1);
                    let list = Ez.ProjectData.database().list("items");
                    list.fallbackString = qsTr("(None)");
                    filter.sourceModel = list;
                    return filter;
                }
            }

            Ez.ComboBox {
                Layout.fillWidth: true
                jsonData: root.jsonData
                key: "initial_equipment/shield_id"
                Kirigami.FormData.label: qsTr("Shield")
                model: {
                    let filter = Ez.ProjectData.actorModel(root.objIndex).CreateEquipmentFilter(2);
                    let list = Ez.ProjectData.database().list("items");
                    list.fallbackString = qsTr("(None)");
                    filter.sourceModel = list;
                    return filter;
                }
            }

            Ez.ComboBox {
                Layout.fillWidth: true
                jsonData: root.jsonData
                key: "initial_equipment/armor_id"
                Kirigami.FormData.label: qsTr("Armor")
                model: {
                    let filter = Ez.ProjectData.actorModel(root.objIndex).CreateEquipmentFilter(3);
                    let list = Ez.ProjectData.database().list("items");
                    list.fallbackString = qsTr("(None)");
                    filter.sourceModel = list;
                    return filter;
                }
            }

            Ez.ComboBox {
                Layout.fillWidth: true
                jsonData: root.jsonData
                key: "initial_equipment/helmet_id"
                Kirigami.FormData.label: qsTr("Helmet")
                model: {
                    let filter = Ez.ProjectData.actorModel(root.objIndex).CreateEquipmentFilter(4);
                    let list = Ez.ProjectData.database().list("items");
                    list.fallbackString = qsTr("(None)");
                    filter.sourceModel = list;
                    return filter;
                }
            }

            Ez.ComboBox {
                Layout.fillWidth: true
                jsonData: root.jsonData
                key: "initial_equipment/accessory_id"
                Kirigami.FormData.label: qsTr("Accessory")
                model: {
                    let filter = Ez.ProjectData.actorModel(root.objIndex).CreateEquipmentFilter(5);
                    let list = Ez.ProjectData.database().list("items");
                    list.fallbackString = qsTr("(None)");
                    filter.sourceModel = list;
                    return filter;
                }
            }
        }
    }
}
