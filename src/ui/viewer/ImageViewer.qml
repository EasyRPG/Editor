// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

Item {
    id: root

    implicitWidth: sprite.implicitWidth
    implicitHeight: sprite.implicitHeight

    property Ez.PickerData pickerData

    property Component pickerComponent: Ez.ImagePicker {
        onAccepted: root.accepted()
    }

    /** Signal emitted when confirming in the picker dialog */
    signal accepted()

    property alias directory: sprite.directory
    property alias filename: sprite.filename

    Ez.SpritePaintedItem {
        id: sprite

        anchors.fill: parent

        projectData: Ez.ProjectData

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                applicationWindow().pageStack.pushDialogLayer(root.pickerComponent, {
                    pickerData: root.pickerData,
                    directory: sprite.directory
                });
            }
        }
    }
}
