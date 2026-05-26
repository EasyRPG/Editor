// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

ViewerBase {
    id: root

    implicitWidth: 48
    implicitHeight: 64

    pickerComponent: Ez.CharSetPicker {
        onAccepted: root.accepted()
    }

    property alias filename: paintedItem.filename
    property alias cellIndex: paintedItem.cellIndex
    property alias spin: paintedItem.spin
    property alias walk: paintedItem.walk
    property alias transparent: paintedItem.transparent
    property bool showTransparency: true

    pickerProperties: { "showTransparency": root.showTransparency }

    Ez.CharSetPaintedItem {
        id: paintedItem

        anchors.fill: parent

        projectData: Ez.ProjectData
    }
}
