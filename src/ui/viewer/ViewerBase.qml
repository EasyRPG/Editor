// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

Item {
    id: root

    property Ez.PickerData pickerData
    property Component pickerComponent
    property var pickerProperties: ({})

    /** Signal emitted when confirming in the picker dialog */
    signal accepted()

    default property alias viewerContent: container.data

    Item {
        id: container
        anchors.fill: parent
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            let props = Object.assign({ pickerData: root.pickerData }, root.pickerProperties);
            applicationWindow().pageStack.pushDialogLayer(root.pickerComponent, props);
        }
    }
}
