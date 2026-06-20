// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

PickerBase {
    id: root

    directory: "Sound"

    Controls.SpinBox {
        id: volumeInput
        value: root.pickerData.volume
        Kirigami.FormData.label: "Volume:"
    }

    Controls.SpinBox {
        id: tempoInput
        value: root.pickerData.tempo
        Kirigami.FormData.label: "Pitch:"
    }

    Controls.SpinBox {
        id: balanceInput
        value: root.pickerData.balance
        Kirigami.FormData.label: "Balance:"
    }

    onAccepted: {
        root.pickerData.volume = volumeInput.value
        root.pickerData.tempo = tempoInput.value
        root.pickerData.balance = balanceInput.value
    }
}
