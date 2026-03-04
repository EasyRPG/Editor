// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

/**
 * The Main Window of the Database.
 * The Database uses a pageStack with three columns:
 * 1. Categories (e.g. Actors and Skills) defined in DatabasePage.pageModel
 * 2. Items in the Category (DatabaseEntryListPage)
 * 3. Edit area for an item (defined in pageModel.targetPage)
 */
Kirigami.ApplicationWindow {
    id: root

    width: 1024
    height: 600

    title: "EasyRPG Editor - Database"

    pageStack.defaultColumnWidth: 200

    /** Database of the current project */
    property Ez.JsonView jsonData: Ez.ProjectData.database()

    pageStack {
        initialPage: pageRoot
        columnView.interactive: true
    }

    Component {
        id: pageRoot
        DatabasePage {
            jsonData: root.jsonData
        }
    }
}
