// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

ViewerBase {
    id: root

    implicitWidth: 48
    implicitHeight: 48

    pickerComponent: Ez.FaceSetPicker {
        onAccepted: root.accepted()
    }

    property alias filename: paintedItem.filename
    property alias cellIndex: paintedItem.cellIndex

    Ez.FaceSetPaintedItem {
        id: paintedItem

        anchors.fill: parent

        projectData: Ez.ProjectData
    }
}
