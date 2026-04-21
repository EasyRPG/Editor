// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

/**
 * Displays categories (e.g. Actors and Skills) in the left-most column of the
 * database window.
 */
Kirigami.ScrollablePage {
    id: root
    property var data

    /** Database of the current project */
    property Ez.JsonView jsonData

    /**
     * name: Text shown to the user
     * key: JSON pointer to access the list items of this category
     * targetPage: Page to load for the items
     * single: The key references a single object, not a list
     */
    ListModel {
        id: pageModel
        ListElement {
            name: "Actors"
            key: "actors"
            targetPage: "ActorPage.qml"
        }
        ListElement {
            name: "Items"
            key: "items"
            targetPage: "ItemPage.qml"
        }
        ListElement {
            name: "Skills"
            key: "skills"
            targetPage: "SkillPage.qml"
        }
        ListElement {
            name: "Attributes"
            key: "attributes"
            targetPage: "AttributePage.qml"
        }
        ListElement {
            name: "Vocabulary"
            key: "terms"
            single: true
            targetPage: "VocabularyPage.qml"
        }
    }

    ListView {
        id: categoryList
        model: pageModel
        delegate: Controls.ItemDelegate {
            required property int index
            required property string name

            text: name
            width: ListView.view.width
            highlighted: ListView.isCurrentItem

            action: Controls.Action {
                onTriggered: {
                    root.selectCategory(index)
                }
            }
        }
    }

    function selectCategory(index) {
        var item = pageModel.get(index)
        if (!item) return

        categoryList.currentIndex = index

        var pageStack = applicationWindow().pageStack
        console.log(pageStack.depth)

        while (pageStack.depth > 1) {
            pageStack.pop();
        }

        if (item.single === true) {
            pageStack.push(Qt.resolvedUrl(item.targetPage), {
                "jsonData": jsonData.subtree(item.key)
            })
        } else {
            pageStack.push(Qt.resolvedUrl("DatabaseEntryListPage.qml"), {
                "jsonData": jsonData.list(item.key),
                "targetPage": item.targetPage
            })
        }
    }

    Component.onCompleted: {
        // Trigger Actors
        // (with a short delay because Kirigami hasn't pushed the current page yet)
        Qt.callLater(root.selectCategory, 0)
    }
}
