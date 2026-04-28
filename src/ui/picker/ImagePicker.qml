// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

PickerBase {
    id: root

    Ez.SpritePaintedItem {
        id: sprite

        directory: root.directory
        filename: root.filename
        projectData: Ez.ProjectData

        Layout.fillWidth: true
    }
}
