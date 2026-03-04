// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import QtQuick.Dialogs as Dialogs
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

/**
 * Displays a list view with the items belonging to a certain category.
 * Shows e.g. a list of Actors for the key "actors"
 */
Kirigami.ScrollablePage {
    id: root

    Kirigami.ColumnView.fillWidth: false

    // Database data rooted at the current list
    property Ez.JsonListView jsonData

    property var data
    property string targetPage
    property string key

    ListView {
        id: entryList
    	model: root.jsonData

        onCurrentIndexChanged: {
            root.selectEntry(currentIndex)
        }

        delegate: Controls.ItemDelegate {
            required property int listindex
            required property string name

    		width: ListView.view.width
            text: (listindex+1).toString().padStart(4, '0') + ": " + name

            highlighted: entryList.currentIndex === listindex

            action: Controls.Action {
                onTriggered: {
                    entryList.currentIndex = listindex
                }
            }
        }
    }

    function selectEntry(index) {
        if (index < 0) return;

        var pageStack = applicationWindow().pageStack

        // Reuse the already loaded Ui when item type (key) stays the same
        if (pageStack.lastItem.key !== root.key) {
            while (pageStack.depth > 2) {
                pageStack.pop();
            }
        }

        if (pageStack.depth <= 2) {
            //console.log("Pushing:", root.targetPage);
            pageStack.push(Qt.resolvedUrl(root.targetPage), {
                // Use the index passed to the function
                jsonData: jsonData.subtree("/" + index)
            });
        }
    }

    Component.onCompleted: {
        // Trigger first item
        Qt.callLater(root.selectEntry, 0)
    }
}
