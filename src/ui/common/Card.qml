// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

/**
 * Card layout with a preconfigured heading and a Form Layout
 */
Kirigami.Card {
    id: root

    property string title: ""
    default property alias cardChildren: formLayout.data

    Layout.fillWidth: true
    Layout.alignment: Qt.AlignTop

    // Override the default background to improve the contrast
    background: Rectangle {
        color: Qt.alpha(Kirigami.Theme.backgroundColor, 0.5)
        radius: Kirigami.Units.smallSpacing
        border.color: Qt.alpha(Kirigami.Theme.textColor, 0.15)
        border.width: 1
    }

    header: Kirigami.Heading {
        text: root.title
        level: 2
        visible: text.length > 0
    }

    contentItem: Ez.FormLayout {
        id: formLayout
    }
}
