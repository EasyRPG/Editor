// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

Kirigami.Page {
    id: root

    required property Ez.PickerData pickerData

    readonly property alias filename: nameInput.text
    property string directory

    default property alias formContent: formLayout.data

    /** Signal emitted when confirming */
    signal accepted()

    actions: [
        Kirigami.Action {
            text: "Cancel"
            icon.name: "cancel"
            onTriggered: {
                Kirigami.PageStack.closeDialog()
            }
        },
        Kirigami.Action {
            text: "Select"
            icon.name: "confirm"
            onTriggered: {
                root.pickerData.filename = nameInput.text
                root.accepted()
                Kirigami.PageStack.closeDialog()
            }
        }
    ]

    RowLayout {
        anchors.fill: parent

        Controls.ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.25

            background: Rectangle {
                //color: Kirigami.Theme.viewBackgroundColor
            }

            ListView {
                id: dirList
                clip: true

                model: Ez.DirectoryModel {
                    path: Ez.ProjectData.findDirectory(root.directory)
                }

                delegate: Controls.ItemDelegate {
                    width: ListView.view.width
                    text: baseName

                    highlighted: baseName === nameInput.text

                    action: Controls.Action {
                        onTriggered: {
                            nameInput.text = baseName
                        }
                    }

                    Component.onCompleted: {
                        if (highlighted) {
                            dirList.positionViewAtIndex(index, ListView.Center)
                        }
                    }
                }
            }
        }

        Kirigami.FormLayout {
            id: formLayout
            Layout.alignment: Qt.AlignTop

            Controls.TextField {
                id: nameInput
                text: root.pickerData.filename
                Kirigami.FormData.label: "Name:"
                visible: false
            }
        }
    }
}
