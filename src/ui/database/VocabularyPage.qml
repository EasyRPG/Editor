// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami
import org.easyrpg.editor as Ez

DatabaseEntryPage {
    id: root

    readonly property var categoryModel: [
    {
        label: qsTr("Title"),
        section: 0,
        settings: [
            { label: qsTr("New Game"), key: "new_game" },
            { label: qsTr("Continue"), key: "load_game" },
            { label: qsTr("Exit"), key: "exit_game" }
        ]
    },
    {
        label: qsTr("Menu"),
        section: 0,
        settings: [
            { label: qsTr("Items (Shared with Battle)"), key: "command_item" },
            { label: qsTr("Skills (Shared with Battle)"), key: "command_skill" },
            { label: qsTr("Equipment"), key: "menu_equipment" },
            { label: qsTr("Status"), key: "status" },
            { label: qsTr("Order"), key: "order" },
            { label: qsTr("Save"), key: "menu_save" },
            { label: qsTr("Quit"), key: "menu_quit" },
            { label: qsTr("Change Row (Shared with Battle)"), key: "row" },
            { label: qsTr("Enable Wait"), key: "wait_on" },
            { label: qsTr("Disable Wait"), key: "wait_off" }
        ]
    },
    {
        label: qsTr("Attributes"),
        section: 0,
        settings: [
            { label: qsTr("HP"), key: "health_points" },
            { label: qsTr("HP (Short Form)"), key: "hp_short" },
            { label: qsTr("MP"), key: "spirit_points" },
            { label: qsTr("MP (Short Form)"), key: "sp_short" },
            { label: qsTr("Level"), key: "level" },
            { label: qsTr("Level (Short Form)"), key: "lvl_short" },
            { label: qsTr("Experience"), key: "exp_short" },
            { label: qsTr("Attack"), key: "attack" },
            { label: qsTr("Defense"), key: "defense" },
            { label: qsTr("Mind"), key: "spirit" },
            { label: qsTr("Agility"), key: "agility" }
        ]
    },
    {
        label: qsTr("Equipment"),
        section: 0,
        settings: [
            { label: qsTr("Weapon"), key: "weapon" },
            { label: qsTr("Shield"), key: "shield" },
            { label: qsTr("Armor"), key: "armor" },
            { label: qsTr("Helmet"), key: "helmet" },
            { label: qsTr("Accessory"), key: "accessory" }
        ]
    },
    {
        label: qsTr("Save/Load/Exit"),
        section: 0,
        settings: [
            { label: qsTr("Yes"), key: "yes" },
            { label: qsTr("No"), key: "no" },
            { label: qsTr("Save Name"), key: "file" },
            { label: qsTr("Save Select"), key: "save_game_message" },
            { label: qsTr("Load Select"), key: "load_game_message" },
            { label: qsTr("Exit Message"), key: "exit_game_message" }
        ]
    },
    {
        label: qsTr("Other"),
        section: 0,
        settings: [
            { label: qsTr("Normal Status"), key: "normal_status" },
            { label: qsTr("Currency"), key: "gold" },
            { label: qsTr("MP Cost"), key: "sp_cost" },
            { label: qsTr("Level Up"), key: "level_up" },
            { label: qsTr("New Skill"), key: "skill_learned" }
        ]
    },
    {
        label: qsTr("Shop Type A"),
        section: 1,
        settings: [
            { label: qsTr("Greeting"), key: "shop_greeting1" },
            { label: qsTr("Regreeting"), key: "shop_regreeting1" },
            { label: qsTr("Buy"), key: "shop_buy1" },
            { label: qsTr("Sell"), key: "shop_sell1" },
            { label: qsTr("Leave"), key: "shop_leave1" },
            { label: qsTr("Purchasing"), key: "shop_buy_select1" },
            { label: qsTr("Amount"), key: "shop_buy_number1" },
            { label: qsTr("Purchase Done"), key: "shop_purchased1" },
            { label: qsTr("Selling"), key: "shop_sell_select1" },
            { label: qsTr("Amount"), key: "shop_sell_number1" },
            { label: qsTr("Sold"), key: "shop_sold1" }
        ]
    },
    {
        label: qsTr("Shop Type B"),
        section: 1,
        settings: [
            { label: qsTr("Greeting"), key: "shop_greeting2" },
            { label: qsTr("Regreeting"), key: "shop_regreeting2" },
            { label: qsTr("Buy"), key: "shop_buy2" },
            { label: qsTr("Sell"), key: "shop_sell2" },
            { label: qsTr("Leave"), key: "shop_leave2" },
            { label: qsTr("Purchasing"), key: "shop_buy_select2" },
            { label: qsTr("Amount"), key: "shop_buy_number2" },
            { label: qsTr("Purchase Done"), key: "shop_purchased2" },
            { label: qsTr("Selling"), key: "shop_sell_select2" },
            { label: qsTr("Amount"), key: "shop_sell_number2" },
            { label: qsTr("Sold"), key: "shop_sold2" }
        ]
    },
    {
        label: qsTr("Shop Type C"),
        section: 1,
        settings: [
            { label: qsTr("Greeting"), key: "shop_greeting3" },
            { label: qsTr("Regreeting"), key: "shop_regreeting3" },
            { label: qsTr("Buy"), key: "shop_buy3" },
            { label: qsTr("Sell"), key: "shop_sell3" },
            { label: qsTr("Leave"), key: "shop_leave3" },
            { label: qsTr("Purchasing"), key: "shop_buy_select3" },
            { label: qsTr("Amount"), key: "shop_buy_number3" },
            { label: qsTr("Purchase Done"), key: "shop_purchased3" },
            { label: qsTr("Selling"), key: "shop_sell_select3" },
            { label: qsTr("Amount"), key: "shop_sell_number3" },
            { label: qsTr("Sold"), key: "shop_sold3" }
        ]
    },
    {
        label: qsTr("Shop Common"),
        section: 2,
        settings: [
            { label: qsTr("Items owned"), key: "possessed_items" },
            { label: qsTr("Equipped"), key: "equipped_items" }
        ]
    },
    {
        label: qsTr("Inn Type A"),
        section: 2,
        settings: [
            { label: qsTr("Greeting (Line 1)"), key: "inn_a_greeting_1" },
            { label: qsTr("Greeting (Line 2)"), key: "inn_a_greeting_3" },
            { label: qsTr("Stay"), key: "inn_a_accept" },
            { label: qsTr("Don't Stay"), key: "inn_a_cancel" }
        ]
    },
    {
        label: qsTr("Inn Type B"),
        section: 2,
        settings: [
            { label: qsTr("Greeting (Line 1)"), key: "inn_b_greeting_1" },
            { label: qsTr("Greeting (Line 2)"), key: "inn_b_greeting_3" },
            { label: qsTr("Stay"), key: "inn_b_accept" },
            { label: qsTr("Don't Stay"), key: "inn_b_cancel" }
        ]
    },
    {
        label: qsTr("Battle Commands"),
        section: 3,
        settings: [
            { label: qsTr("Fight"), key: "battle_fight" },
            { label: qsTr("Auto Battle"), key: "battle_auto" },
            { label: qsTr("Escape"), key: "battle_escape" },
            { label: qsTr("Attack"), key: "command_attack" },
            { label: qsTr("Defend"), key: "command_defend" }
        ]
    },
    {
        label: qsTr("Actor (Battle)"),
        section: 3,
        settings: [
            { label: qsTr("Critical Hit"), key: "actor_critical" },
            { label: qsTr("Took Damage"), key: "actor_damaged" },
            { label: qsTr("Took No Damage"), key: "actor_undamaged" },
            { label: qsTr("Absorbed"), key: "actor_hp_absorbed" },
            { label: qsTr("Escaped"), key: "escape_success" },
            { label: qsTr("Escape failed"), key: "escape_failure" },
            { label: qsTr("Use Item"), key: "use_item" }
        ]
    },
    {
        label: qsTr("Enemy (Battle)"),
        section: 3,
        settings: [
            { label: qsTr("Critical Hit"), key: "enemy_critical" },
            { label: qsTr("Took Damage"), key: "enemy_damaged" },
            { label: qsTr("Took No Damage"), key: "enemy_undamaged" },
            { label: qsTr("Absorbed"), key: "enemy_hp_absorbed" },
            { label: qsTr("Escaped"), key: "enemy_escape" },
            { label: qsTr("Encounter"), key: "encounter" },
            { label: qsTr("Waiting"), key: "observing" },
            { label: qsTr("Charging"), key: "focus" },
            { label: qsTr("Self Destruct"), key: "autodestruction" },
            { label: qsTr("Transform"), key: "enemy_transform" }
        ]
    },
    {
        label: qsTr("Shared (Battle)"),
        section: 3,
        settings: [
            { label: qsTr("Basic Attack"), key: "attacking" },
            { label: qsTr("Defending"), key: "defending" },
            { label: qsTr("Skill A failed"), key: "skill_failure_a" },
            { label: qsTr("Skill B failed"), key: "skill_failure_b" },
            { label: qsTr("Skill C failed"), key: "skill_failure_c" },
            { label: qsTr("Dodged"), key: "dodge" },
            { label: qsTr("HP/MP Recovery"), key: "hp_recovery" },
            { label: qsTr("Attribute up"), key: "parameter_increase" },
            { label: qsTr("Attribute down"), key: "parameter_decrease" },
            { label: qsTr("Resistance up"), key: "resistance_increase" },
            { label: qsTr("Resistance down"), key: "resistance_decrease" }
        ]
    },
    {
        label: qsTr("Battle State"),
        section: 3,
        settings: [
            { label: qsTr("Battle Start"), key: "battle_start" },
            { label: qsTr("Miss"), key: "miss" },
            { label: qsTr("Preemptive"), key: "special_combat" },
            { label: qsTr("Victory"), key: "victory" },
            { label: qsTr("Defeat"), key: "defeat" },
            { label: qsTr("Receive Exp"), key: "exp_received" },
            { label: qsTr("Receive Gold"), key: "gold_recieved_a" },
            { label: qsTr("Receive Item"), key: "item_recieved" }
        ]
    }
    ]

    actions: [
    ]

    ColumnLayout {
        spacing: Kirigami.Units.largeSpacing

        Repeater {
            model: root.categoryModel
            delegate: ColumnLayout {
                Layout.maximumWidth: Kirigami.Units.gridUnit * 48
                Layout.alignment: Qt.AlignHCenter
                Layout.fillWidth: true

                Kirigami.Heading {
                    Layout.alignment: Qt.AlignVCenter

                    level: 2
                    type: Kirigami.Heading.Primary
                    text: modelData.label
                    elide: Text.ElideRight
                }

                Kirigami.Separator {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                }

                GridLayout {
                    Layout.alignment: Qt.AlignHCenter
                    columns: Math.max(1, Math.min(Math.floor(root.width / (Kirigami.Units.gridUnit * 16)), 3))
                    Layout.fillWidth: true

                    Repeater {
                        model: modelData.settings
                        delegate: ColumnLayout {
                            Controls.Label { text: modelData.label }
                            Ez.TextField { jsonData: root.jsonData; key: modelData.key; Layout.fillWidth: true }
                        }
                    }
                }
            }
        }
    }
}
