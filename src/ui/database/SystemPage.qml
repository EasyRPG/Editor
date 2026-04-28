// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import Qt.labs.folderlistmodel 2.11
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import QtQml.Models as Models
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

DatabaseEntryPage {
    id: root

    component JsonImageViewer : Ez.ImageViewer {
        id: imageViewer

        Layout.fillWidth: true

        property string key
        filename: root.jsonData.str(key)

        pickerData: Ez.PickerData {
            Component.onCompleted: filename = imageViewer.filename
        }
        onAccepted: {
            imageViewer.filename = pickerData.filename
            jsonData.set(key, pickerData.filename)
        }
    }

    component JsonMusicViewer : Ez.MusicViewer {
        property string key
        readonly property var musicData: root.jsonData.subtree(key)
        pickerData: Ez.PickerData {
            Component.onCompleted: fromMusic(musicData)
        }
        onAccepted: pickerData.toMusic(musicData)
    }

    component JsonSoundViewer : Ez.SoundViewer {
        property string key
        readonly property var soundData: root.jsonData.subtree(key)
        pickerData: Ez.PickerData {
            Component.onCompleted: fromSound(soundData)
        }
        onAccepted: pickerData.toSound(soundData)
    }

    Kirigami.FormLayout {
        anchors.fill: parent

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Title"
        }

        JsonImageViewer {
            directory: "Title"
            key: "title_name"
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Game Over"
        }

        JsonImageViewer {
            directory: "GameOver"
            key: "gameover_name"
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "System"
        }

        JsonImageViewer {
            directory: "System"
            key: "system_name"
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "System 2"
        }

        JsonImageViewer {
            directory: "System 2"
            key: "system2_name"
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Music"
        }

        JsonMusicViewer {
            key: "title_music"
            Kirigami.FormData.label: "Title:"
        }

        JsonMusicViewer {
            key: "gameover_music"
            Kirigami.FormData.label: "Game Over:"
        }

        JsonMusicViewer {
            key: "inn_music"
            Kirigami.FormData.label: "Inn:"
        }

        JsonMusicViewer {
            key: "boat_music"
            Kirigami.FormData.label: "Boat:"
        }

        JsonMusicViewer {
            key: "ship_music"
            Kirigami.FormData.label: "Ship:"
        }

        JsonMusicViewer {
            key: "airship_music"
            Kirigami.FormData.label: "Airship:"
        }

        JsonMusicViewer {
            key: "battle_music"
            Kirigami.FormData.label: "Battle:"
        }

        JsonMusicViewer {
            key: "battle_end_music"
            Kirigami.FormData.label: "Battle End:"
        }

        Kirigami.Separator {
            Kirigami.FormData.isSection: true
            Kirigami.FormData.label: "Sound"
        }


        JsonSoundViewer {
            key: "cursor_se"
            Kirigami.FormData.label: "Cursor:"
        }

        JsonSoundViewer {
            key: "decision_se"
            Kirigami.FormData.label: "Decision:"
        }

        JsonSoundViewer {
            key: "cancel_se"
            Kirigami.FormData.label: "Cancel:"
        }

        JsonSoundViewer {
            key: "buzzer_se"
            Kirigami.FormData.label: "Buzzer:"
        }

        JsonSoundViewer {
            key: "battle_se"
            Kirigami.FormData.label: "Battle:"
        }

        JsonSoundViewer {
            key: "escape_se"
            Kirigami.FormData.label: "Escape:"
        }

        JsonSoundViewer {
            key: "enemy_attack_se"
            Kirigami.FormData.label: "Enemy Attack:"
        }

        JsonSoundViewer {
            key: "enemy_damaged_se"
            Kirigami.FormData.label: "Enemy Damaged:"
        }

        JsonSoundViewer {
            key: "actor_damaged_se"
            Kirigami.FormData.label: "Actor Damaged:"
        }

        JsonSoundViewer {
            key: "dodge_se"
            Kirigami.FormData.label: "Dodge:"
        }

        JsonSoundViewer {
            key: "enemy_death_se"
            Kirigami.FormData.label: "Enemy Death:"
        }

        JsonSoundViewer {
            key: "item_se"
            Kirigami.FormData.label: "Item:"
        }
    }
}
