// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

PickerBase {
    id: root

    directory: "CharSet"
    property bool showTransparency: true

    Ez.CharSetPaintedItem {
        id: charsetPainted
        pickerMode: true
        projectData: Ez.ProjectData
        filename: root.filename
        cellIndex: root.pickerData.index
        transparent: root.pickerData.transparent
        onCellIndexChanged: {
            root.pickerData.index = cellIndex
        }
        Layout.fillWidth: true
        implicitWidth: 192
        implicitHeight: 192
    }

    Kirigami.Separator {
        visible: root.showTransparency
        Kirigami.FormData.isSection: true
        Kirigami.FormData.label: "Options"
    }

    Controls.CheckBox {
        visible: root.showTransparency
        text: "Transparent"
        checked: root.pickerData.transparent
        onClicked: root.pickerData.transparent = checked
    }

    Kirigami.Separator {
        Kirigami.FormData.isSection: true
        Kirigami.FormData.label: "Facing (Preview Only)"
    }

    ColumnLayout {
        Controls.RadioButton {
            text: "Up"
            checked: charsetPainted.facing === Ez.CharSetPaintedItem.Direction_up
            onClicked: charsetPainted.facing = Ez.CharSetPaintedItem.Direction_up
        }
        Controls.RadioButton {
            text: "Right"
            checked: charsetPainted.facing === Ez.CharSetPaintedItem.Direction_right
            onClicked: charsetPainted.facing = Ez.CharSetPaintedItem.Direction_right
        }
        Controls.RadioButton {
            text: "Down"
            checked: charsetPainted.facing === Ez.CharSetPaintedItem.Direction_down
            onClicked: charsetPainted.facing = Ez.CharSetPaintedItem.Direction_down
        }
        Controls.RadioButton {
            text: "Left"
            checked: charsetPainted.facing === Ez.CharSetPaintedItem.Direction_left
            onClicked: charsetPainted.facing = Ez.CharSetPaintedItem.Direction_left
        }
    }

    Kirigami.Separator {
        Kirigami.FormData.isSection: true
        Kirigami.FormData.label: "Pattern (Preview Only)"
    }

    ColumnLayout {
        Controls.RadioButton {
            text: "Left"
            checked: charsetPainted.frame === Ez.CharSetPaintedItem.Frame_left
            onClicked: charsetPainted.frame = Ez.CharSetPaintedItem.Frame_left
        }
        Controls.RadioButton {
            text: "Middle"
            checked: charsetPainted.frame === Ez.CharSetPaintedItem.Frame_middle
            onClicked: charsetPainted.frame = Ez.CharSetPaintedItem.Frame_middle
        }
        Controls.RadioButton {
            text: "Right"
            checked: charsetPainted.frame === Ez.CharSetPaintedItem.Frame_right
            onClicked: charsetPainted.frame = Ez.CharSetPaintedItem.Frame_right
        }
    }
}
