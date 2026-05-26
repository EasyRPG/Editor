// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

PickerBase {
    id: root

    directory: "FaceSet"

    Ez.FaceSetPaintedItem {
        id: facesetGrid
        pickerMode: true
        projectData: Ez.ProjectData
        filename: root.filename
        cellIndex: root.pickerData.index
        onCellIndexChanged: {
            root.pickerData.index = cellIndex
        }
        Layout.fillWidth: true
        implicitWidth: 192
        implicitHeight: 192
    }
}
