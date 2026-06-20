// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

RowLayout {
    id: root

    property alias value: component.text

    property Ez.PickerData pickerData

    property Component pickerComponent

    /** Signal emitted when confirming in the picker dialog */
    signal accepted()

    Controls.TextField {
        id: component
        text: pickerData.filename
        onTextEdited: {
            pickerData.filename = text
            root.accepted()
        }
    }

    Controls.Button {
        //icon.name: "document-open"
        text: "..."

        onClicked: {
            applicationWindow().pageStack.pushDialogLayer(root.pickerComponent, {
                pickerData: root.pickerData
            });
        }
    }
}

