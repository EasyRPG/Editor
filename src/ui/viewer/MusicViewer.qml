// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import org.easyrpg.editor as Ez

FileViewerBase {
    id: root

    pickerComponent: Component {
        Ez.MusicPicker {
            onAccepted: root.accepted()
        }
    }
}

