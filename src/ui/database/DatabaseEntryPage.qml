// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

/**
 * Shared code for the entry edit pages such as editing single Actors or Skills
 */
Kirigami.ScrollablePage {
    id: root

    /** Database data rooted at the current item */
    property Ez.JsonView jsonData

    // Ensure the column fills the remaining space of the window
    Kirigami.ColumnView.fillWidth: true
    Kirigami.ColumnView.reservedSpace: applicationWindow().pageStack.defaultColumnWidth * (applicationWindow().pageStack.depth - 1)

    /** When the object comes from a list, contains the index. Otherwise -1. */
    property int objIndex: -1

    // Update the Page title when the name changes
    Connections {
        target: jsonData
        function onValueChanged(jsonPtr) {
            if (objIndex >= 0 && jsonPtr.endsWith("/name")) {
                console.log(jsonPtr);
                root.title = jsonData.str("name");
            }
        }
    }

    onJsonDataChanged: {
        if (objIndex >= 0) {
            root.title = jsonData.str("name");
        }
    }

    // TODO: Not used. Just for testing
    property bool showActions: false

    Layout.fillWidth: true

    actions: [
        Kirigami.Action {
            text: "Cancel"
            icon.name: "cancel"
            onTriggered: {
                applicationWindow().pageStack.pop()
                applicationWindow().pageStack.pop()
            }
            visible: showActions
        },
        Kirigami.Action {
            text: "Select"
            icon.name: "confirm"
            onTriggered: {
                applicationWindow().pageStack.pop()
                applicationWindow().pageStack.pop()
            }
            visible: showActions
        }
    ]
}
