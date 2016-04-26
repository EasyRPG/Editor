#include <QObject>
#include "stringizer.h"
#include <data.h>
#include "core.h"

namespace
{
    // Helper functions
    QString tr(const char *sourceTex)
    {
        return QObject::tr(sourceTex);
    }

    QString variable(int id, bool show_name = false)
    {
        if (show_name)
            return QString("V[%1:%2]").arg(id, 4, 10, QChar('0')).arg(Stringizer::varName(id));
        else
            return QString("V[%1]").arg(id, 4, 10, QChar('0'));
    }

    QString valueOrVariable(bool is_variable, int value)
    {
        return is_variable ? variable(value)
                           : QString::number(value);
    }

    QString heroes(int mode, int id)
    {
        switch (mode)
        {
        case 0:
            return tr("Entire Party");
        case 1:
            return Stringizer::heroName(id);
        case 2:
            return tr("Hero") + " " + variable(id);
        default:
            return tr("Unknown");
        }
    }

    QString map(int id)
    {
        return QString("%1").arg(id, 4, 10, QChar('0')) + ":" + Stringizer::mapName(id);
    }

    QString tenthSeconds(int t)
    {
        return QString::number(t / 10.0, 'f', 1) + "s";
    }

    QString characterName(int id)
    {
        switch (id)
        {
        case 10001:
            return tr("Hero");
        case 10002:
            return tr("Boat");
        case 10003:
            return tr("Ship");
        case 10004:
            return tr("Airship");
        case 10005:
            return tr("This Event");
        default:
            return Stringizer::eventName(id);
        }
    }

    QString formatTime(int seconds)
    {
        return QString("%1M %2S").arg(seconds / 60).arg(seconds % 60, 2, 10, QChar('0'));
    }

    // Stringizers
    QString stringizeCallCommonEvent(const RPG::EventCommand& com)
    {
        return tr("Call Common Event") + ": " + Stringizer::commonEventName(com.parameters[0]);
    }

    QString stringizeForceFlee(const RPG::EventCommand& com)
    {
        Q_UNUSED(com);
        // TODO
        return tr("Force Flee");
    }

    QString stringizeEnableCombo(const RPG::EventCommand& com)
    {
        return tr("Enable Combo") + ": "
            + Stringizer::heroName(com.parameters[0]) + ", "
            + QString::number(com.parameters[2]) + "x"
            + Stringizer::battleCommandName(com.parameters[1]);
    }

    QString stringizeChangeClass(const RPG::EventCommand& com)
    {
        return tr("Change Class") + ": "
            + Stringizer::heroName(com.parameters[1]) + ", "
            + Stringizer::className(com.parameters[2]);
    }

    QString stringizeChangeBattleCommands(const RPG::EventCommand& com)
    {
        return tr("Change Battle Commands") + ": "
            + Stringizer::heroName(com.parameters[1]) + ", "
            + tr(com.parameters[3] ? "Add" : "Remove") + " "
            + Stringizer::battleCommandName(com.parameters[4]);
    }

    QString stringizeShowMessage(const RPG::EventCommand& com)
    {
        return tr("Show Message") + ":\n    " + QString::fromStdString(com.string);
    }

    QString stringizeMessageOptions(const RPG::EventCommand& com)
    {
        QString position;
        switch (com.parameters[1])
        {
        case 0:
            position = tr("Top"); break;
        case 1:
            position = tr("Center"); break;
        case 2:
            position = tr("Bottom"); break;
        default:
            position = tr("Unknown");
        }
        return tr("Message Options") + ": "
            + tr(com.parameters[0] ? "Transp" : "Normal") + ", "
            + position + ", "
            + tr(com.parameters[2] ? "Auto" : "Fixed") + ", "
            + tr(com.parameters[3] ? "Continue Processes" : "Halt Processes");
    }

    QString stringizeChangeFaceGraphic(const RPG::EventCommand& com)
    {
        return tr("Change Face Graphic") + ": "
            + QString::fromStdString(com.string) + ", "
            + QString::number(com.parameters[0]) + ", "
            + tr(com.parameters[1] ? "Left" : "Right")
            + (com.parameters[2] ? ", " + tr("Flipped") : "");
    }

    QString stringizeShowChoice(const RPG::EventCommand& com)
    {
        return tr("Show Choice") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeInputNumber(const RPG::EventCommand& com)
    {
        return tr("Input Number") + ": "
            + tr("%1 Digits").arg(QString::number(com.parameters[0])) + ", "
            + variable(com.parameters[1]);
    }

    QString stringizeControlSwitches(const RPG::EventCommand& com)
    {
        QString switches, operation;
        switch (com.parameters[0])
        {
        case 0:
            switches = QString("S[%1:%2]").arg(com.parameters[1], 4, 10, QChar('0'))
                                          .arg(Stringizer::switchName(com.parameters[1]));
            break;
        case 1:
            switches = QString("S[%1-%2]").arg(com.parameters[1], 4, 10, QChar('0'))
                                          .arg(com.parameters[2], 4, 10, QChar('0'));
            break;
        case 2:
            switches = QString("S[V%1]").arg(com.parameters[1], 4, 10, QChar('0'));
            break;
        default:
            switches = "S[????]";
        }

        switch (com.parameters[3])
        {
        case 0:
            operation = tr("ON"); break;
        case 1:
            operation = tr("OFF"); break;
        case 2:
            operation = tr("Toggle"); break;
        default:
            operation = tr("Unknown"); break;
        }
        return tr("Control Switches") + ": " + switches + " " + operation;
    }

    QString stringizeControlVars(const RPG::EventCommand& com)
    {
        QString variables, operation, operand;
        switch (com.parameters[0])
        {
        case 0:
            variables = variable(com.parameters[1], true);
            break;
        case 1:
            variables = QString("V[%1-%2]").arg(com.parameters[1], 4, 10, QChar('0'))
                                           .arg(com.parameters[2], 4, 10, QChar('0'));
            break;
        case 2:
            variables = QString("V[%1]").arg(variable(com.parameters[1]));
            break;
        default:
            variables = "[????]";
        }

        switch (com.parameters[3])
        {
        case 0:
            operation = "="; break;
        case 1:
            operation = "+"; break;
        case 2:
            operation = "-"; break;
        case 3:
            operation = "*"; break;
        case 4:
            operation = "/"; break;
        case 5:
            operation = "%"; break;
        default:
            operation = "?";
        }

        switch (com.parameters[4])
        {
        case 0: // Constant
            operand = QString::number(com.parameters[5]);
            break;
        case 1: // Value of Variable
            operand = variable(com.parameters[5]);
            break;
        case 2: // Value of Variable referenced by another Variable
            operand = QString("V[%1]").arg(variable(com.parameters[5]));
            break;
        case 3: // Random Value
            operand = tr("Random %1-%2").arg(com.parameters[5], com.parameters[6]);
            break;
        case 4: // Items
            operand = tr(com.parameters[6] ? "Number Equipped" : "Number Possessed") + " "
                + Stringizer::itemName(com.parameters[5]);
            break;
        case 5: // Hero
            operand = Stringizer::heroName(com.parameters[5]) + " ";
            switch (com.parameters[6])
            {
            case 0:
                operand += tr("Level"); break;
            case 1:
                operand += tr("Experience"); break;
            case 2:
                operand += tr("HP"); break;
            case 3:
                operand += tr("MP"); break;
            case 4:
                operand += tr("Max HP"); break;
            case 5:
                operand += tr("Max MP"); break;
            case 6:
                operand += tr("Attack"); break;
            case 7:
                operand += tr("Defense"); break;
            case 8:
                operand += tr("Intelligence"); break;
            case 9:
                operand += tr("Agility"); break;
            case 10:
                operand += tr("Weapon ID"); break;
            case 11:
                operand += tr("Shield ID"); break;
            case 12:
                operand += tr("Armor ID"); break;
            case 13:
                operand += tr("Helmet ID"); break;
            case 14:
                operand += tr("Accesory ID"); break;
            default:
                operand += tr("Unknown");
            }
            break;
        case 6: // Characters
            operand = characterName(com.parameters[5]) + " ";
            switch (com.parameters[6])
            {
            case 0:
                operand += tr("Map ID"); break;
            case 1:
                operand += tr("X Coordinate"); break;
            case 2:
                operand += tr("Y Coordinate"); break;
            case 3:
                operand += tr("Orientation"); break;
            case 4:
                operand += tr("Screen X"); break;
            case 5:
                operand += tr("Screen Y"); break;
            default:
                operand += tr("Unknown");
            }
            break;
        case 7: // More
            switch (com.parameters[5]) {
            case 0:
                operand = tr("Gold"); break;
            case 1:
                operand = tr("Timer 1"); break;
            case 2:
                operand = tr("Size of Party"); break;
            case 3:
                operand = tr("Number of Saves"); break;
            case 4:
                operand = tr("Number of Battles"); break;
            case 5:
                operand = tr("Number of Won Battles"); break;
            case 6:
                operand = tr("Number of Lost Battles"); break;
            case 7:
                operand = tr("Number of Escapes"); break;
            case 8:
                operand = tr("MIDI Play Position"); break;
            case 9:
                operand = tr("Timer 2"); break;
            default:
                operand = tr("Unknown");
            }
            break;
        default:
            operand = tr("Unknown");
        }

        return tr("Control Vars") + ": "
            + variables + " " + operation + " " + operand;

    }

    QString stringizeTimerOperation(const RPG::EventCommand& com)
    {
        QString command = tr("Timer %1 Operation").arg(com.parameters.size() <= 5 ? 1 : com.parameters[5]+1);

        switch (com.parameters[0])
        {
        case 0:
            return command + ": " + tr("Set") + " "
                + (com.parameters[1] ? variable(com.parameters[2])
                                     : formatTime(com.parameters[2]));
        case 1:
            return command + ": " + tr("Start");
        case 2:
            return command + ": " + tr("Stop");
        default:
            return command + ": " + tr("Unknown");
        }
    }

    QString stringizeChangeGold(const RPG::EventCommand& com)
    {
        return tr("Change Gold") + ": "
            + (com.parameters[0] ? "-" : "+")
            + valueOrVariable(com.parameters[1], com.parameters[2]);
    }

    QString stringizeChangeItems(const RPG::EventCommand& com)
    {
        return tr("Change Items") + ": "
            + (com.parameters[0] ? "-" : "+")
            + valueOrVariable(com.parameters[3], com.parameters[4])
            + (com.parameters[1] ? tr("Item") + " " + variable(com.parameters[2])
                                 : Stringizer::itemName(com.parameters[2]));
    }

    QString stringizeChangePartyMembers(const RPG::EventCommand& com)
    {
        return tr("Change Party Members") + ": "
            + tr(com.parameters[0] ? "Remove" : "Add") + " "
            + (com.parameters[1] ? tr("Hero") + " " + variable(com.parameters[2])
                                 : Stringizer::heroName(com.parameters[2]));
    }

    QString stringizeChangeExp(const RPG::EventCommand& com)
    {
        return tr("Change Exp") + ": "
            + heroes(com.parameters[0], com.parameters[1]) + ", "
            + (com.parameters[2] ? "-" : "+")
            + valueOrVariable(com.parameters[3], com.parameters[4]);
    }

    QString stringizeChangeLevel(const RPG::EventCommand& com)
    {
        return tr("Change Level") + ": "
            + heroes(com.parameters[0], com.parameters[1])+ ", "
            + (com.parameters[2] ? "-" : "+")
            + valueOrVariable(com.parameters[3], com.parameters[4]);
    }

    QString stringizeChangeParameters(const RPG::EventCommand& com)
    {
        QString parameter;
        switch (com.parameters[3])
        {
        case 0:
            parameter = tr("Max HP"); break;
        case 1:
            parameter = tr("Max MP"); break;
        case 2:
            parameter = tr("Attack"); break;
        case 3:
            parameter = tr("Defense"); break;
        case 4:
            parameter = tr("Spirit"); break;
        case 5:
            parameter = tr("Agility"); break;
        default:
            parameter = tr("Unknown");
        }

        return tr("Change Parameters") + ": "
            + heroes(com.parameters[0], com.parameters[1])+ ", "
            + parameter + " "
            + (com.parameters[2] ? "-" : "+")
            + valueOrVariable(com.parameters[4], com.parameters[5]);
    }

    QString stringizeChangeSkills(const RPG::EventCommand& com)
    {
        return tr("Change Skills") + ": "
            + heroes(com.parameters[0], com.parameters[1])+ ", "
            + tr(com.parameters[2] ? "Remove" : "Add")
            + (com.parameters[3] ? variable(com.parameters[4])
                                 : Stringizer::skillName(com.parameters[4]));
    }

    QString stringizeChangeEquipment(const RPG::EventCommand& com)
    {
        QString item, action;
        if (com.parameters[2])
        {
            action = tr("Equip");
            switch (com.parameters[4])
            {
            case 0:
                item = tr("Weapon"); break;
            case 1:
                item = tr("Shield"); break;
            case 2:
                item = tr("Armor"); break;
            case 3:
                item = tr("Helmet"); break;
            case 4:
                item = tr("Accesory"); break;
            case 5:
                item = tr("All"); break;
            default:
                item = tr("Unknown");
            }
        }
        else
        {
            tr("Unequip");
            item = com.parameters[3] ? variable(com.parameters[4])
                                     : Stringizer::itemName(com.parameters[4]);
        }

        return tr("Change Equipment") + ": "
                + heroes(com.parameters[0], com.parameters[1]) + ", "
                + action + " " + item;
    }

    QString stringizeChangeHP(const RPG::EventCommand& com)
    {
        return tr("Change HP") + ": "
            + heroes(com.parameters[0], com.parameters[1])+ ", "
            + (com.parameters[2] ? "-" : "+")
            + valueOrVariable(com.parameters[3], com.parameters[4]);
    }

    QString stringizeChangeSP(const RPG::EventCommand& com)
    {
        return tr("Change SP") + ": "
            + heroes(com.parameters[0], com.parameters[1])+ ", "
            + (com.parameters[2] ? "-" : "+")
            + valueOrVariable(com.parameters[3], com.parameters[4]);
    }

    QString stringizeChangeCondition(const RPG::EventCommand& com)
    {
        return tr("Change Condition") + ": "
            + heroes(com.parameters[0], com.parameters[1])+ ", "
            + tr(com.parameters[2] ? "Add" : "Remove") + " "
            + Stringizer::stateName(com.parameters[3]);
    }

    QString stringizeFullHeal(const RPG::EventCommand& com)
    {
        return tr("Full Heal") + ": "
            + heroes(com.parameters[0], com.parameters[1]);
    }

    QString stringizeSimulatedAttack(const RPG::EventCommand& com)
    {
        return tr("Simulated Attack") + ": "
            + heroes(com.parameters[0], com.parameters[1]);
    }

    QString stringizeChangeHeroName(const RPG::EventCommand& com)
    {
        return tr("Change Hero Name") + ": "
            + Stringizer::heroName(com.parameters[0]) + " -> "
            + QString::fromStdString(com.string);
    }

    QString stringizeChangeHeroTitle(const RPG::EventCommand& com)
    {
        return tr("Change Hero Title") + ": "
            + Stringizer::heroName(com.parameters[0]) + ", "
            + QString::fromStdString(com.string);
    }

    QString stringizeChangeSpriteAssociation(const RPG::EventCommand& com)
    {
        return tr("Change Sprite Association") + ": "
            + Stringizer::heroName(com.parameters[0]) + ", "
            + QString::fromStdString(com.string) + "-"
            + QString::number(com.parameters[1]);
    }

    QString stringizeChangeActorFace(const RPG::EventCommand& com)
    {
        return tr("Change Actor Face") + ": "
            + Stringizer::heroName(com.parameters[0]) + ", "
            + QString::fromStdString(com.string) + "-"
            + QString::number(com.parameters[1]);
    }

    QString stringizeChangeVehicleGraphic(const RPG::EventCommand& com)
    {
        QString vehicle = tr(
            com.parameters[0] == 0 ? "Boat" :
            com.parameters[0] == 1 ? "Ship" :
            com.parameters[0] == 2 ? "Airship" : "Unknown");
        return tr("Change Vehicle Graphic") + ": "
            + vehicle + ", "
            + QString::fromStdString(com.string) + "-"
            + QString::number(com.parameters[1]);
    }

    QString stringizeChangeSystemBGM(const RPG::EventCommand& com)
    {
        static const std::vector<QString> bgm_contexts =
            {
                tr("Battle"),
                tr("Victory"),
                tr("Inn"),
                tr("Boat"),
                tr("Ship"),
                tr("Airship"),
                tr("Game Over")
            };

        QString context;
        if (com.parameters[0] < 0 || com.parameters[0] >= (int)bgm_contexts.size())
            context = tr("Unknown");
        else
            context = bgm_contexts[com.parameters[0]];
        return tr("Change System BGM") + ": " + context + ", "
            + QString::fromStdString(com.string);
    }

    QString stringizeChangeSystemSFX(const RPG::EventCommand& com)
    {
        static const std::vector<QString> system_sfx =
            {
                tr("Cursor"),
                tr("Decision"),
                tr("Cancel"),
                tr("Buzzer"),
                tr("Begin Battle"),
                tr("Escape"),
                tr("Enemy Attacks"),
                tr("Enemy Damage"),
                tr("Ally Damage"),
                tr("Evasion"),
                tr("Enemy Defeated"),
                tr("Use Item")
            };
        QString sfx;
        if (com.parameters[0] < 0 || com.parameters[0] >= (int)system_sfx.size())
            sfx = tr("Unknown");
        else
            sfx = system_sfx[com.parameters[0]];
        return tr("Change System SFX") + ": " + sfx + ", "
            + QString::fromStdString(com.string);
    }

    QString stringizeChangeSystemGraphics(const RPG::EventCommand& com)
    {
        return tr("Change System Graphics") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeChangeScreenTransitions(const RPG::EventCommand& com)
    {
        return tr("Change Screen Transitions") + ": "
            + (com.parameters[0] ? Stringizer::showTransitionName(com.parameters[1])
                                 : Stringizer::eraseTransitionName(com.parameters[1]));
    }

    QString stringizeEnemyEncounter(const RPG::EventCommand& com)
    {
        return tr("Enemy Encounter") + ": "
            + (com.parameters[0] ? tr("Troop") + " " + variable(com.parameters[1])
                                 : Stringizer::troopName(com.parameters[1]));
    }

    QString stringizeOpenShop(const RPG::EventCommand& com)
    {
        QString buysell;
        switch (com.parameters[0])
        {
            case 0:
                buysell = tr("Buy") + "/" + tr("Sell"); break;
            case 1:
                buysell = tr("Buy");
            case 2:
                buysell = tr("Sell");

        }
        return tr("Open Shop") + ": " + buysell;
    }

    QString stringizeShowInn(const RPG::EventCommand& com)
    {
        return tr("Show Inn") + ": " + tr("Price") + " " + QString::number(com.parameters[1]);
    }

    QString stringizeEnterHeroName(const RPG::EventCommand& com)
    {
        return tr("Enter Hero Name") + ": " + Stringizer::heroName(com.parameters[0]);
    }

    QString stringizeTeleport(const RPG::EventCommand& com)
    {
        QString direction;
        if (com.parameters[3] < 0 || com.parameters[3] > 3)
            direction = tr("Retain Facing");
        else
            direction = Stringizer::direction(com.parameters[3]);

        return tr("Teleport") + ": "
            + map(com.parameters[0]) + " "
            + "(" + com.parameters[1] + "," + com.parameters[2] + "), "
            + direction;
    }

    QString stringizeMemorizeLocation(const RPG::EventCommand& com)
    {
        return tr("Memorize Location") + ": "
            + variable(com.parameters[0]) + ", "
            + variable(com.parameters[1]) + ", "
            + variable(com.parameters[2]);
    }

    QString stringizeRecallToLocation(const RPG::EventCommand& com)
    {
        return tr("Recall To Location") + ": "
            + variable(com.parameters[0]) + ", ("
            + variable(com.parameters[1]) + ","
            + variable(com.parameters[2]) + ")";
    }

    QString stringizeSetVehicleLocation(const RPG::EventCommand& com)
    {
        QString vehicle = tr(
            com.parameters[0] == 0 ? "Boat" :
            com.parameters[0] == 1 ? "Ship" :
            com.parameters[0] == 2 ? "Airship" : "Unknown");
        if (com.parameters[1])
            return tr("Set Vehicle Location") + ": " + vehicle + ", "
                + variable(com.parameters[0]) + ", ("
                + variable(com.parameters[1]) + ","
                + variable(com.parameters[2]) + ")";
        else
            return tr("Set Vehicle Location") + ": " + vehicle + ", "
                + map(com.parameters[0]) + " ("
                + com.parameters[1] + "," + com.parameters[2] + ")";
    }

    QString stringizeChangeEventLocation(const RPG::EventCommand& com)
    {
        return tr("Change Event Location") + ": "
            + characterName(com.parameters[0]) + ", "
            + "(" + valueOrVariable(com.parameters[1], com.parameters[2]) + ","
            + valueOrVariable(com.parameters[1], com.parameters[3]) + ")";
    }

    QString stringizeTradeEventLocations(const RPG::EventCommand& com)
    {
        return tr("Trade Event Locations") + ": "
            + characterName(com.parameters[0]) + ", "
            + characterName(com.parameters[1]);
    }

    QString stringizeStoreTerrainID(const RPG::EventCommand& com)
    {
        return tr("Store Terrain ID") + ": "
            + "(" + valueOrVariable(com.parameters[0], com.parameters[1]) + ","
            + valueOrVariable(com.parameters[0], com.parameters[2]) + "), "
            + variable(com.parameters[3]);
    }

    QString stringizeStoreEventID(const RPG::EventCommand& com)
    {
        return tr("Store Event ID") + ": "
            + "(" + valueOrVariable(com.parameters[0], com.parameters[1]) + ","
            + valueOrVariable(com.parameters[0], com.parameters[2]) + "), "
            + variable(com.parameters[3]);
    }

    QString stringizeEraseScreen(const RPG::EventCommand& com)
    {
        return tr("Erase Screen") + ": " + Stringizer::eraseTransitionName(com.parameters[0]);
    }

    QString stringizeShowScreen(const RPG::EventCommand& com)
    {
        return tr("Show Screen") + ": " + Stringizer::showTransitionName(com.parameters[0]);
    }

    QString stringizeTintScreen(const RPG::EventCommand& com)
    {
        return tr("Tint Screen") + ": ("
            + "R" + QString::number(com.parameters[0]) + ","
            + "G" + QString::number(com.parameters[1]) + ","
            + "B" + QString::number(com.parameters[2]) + ","
            + "S" + QString::number(com.parameters[3]) + "), "
            + tenthSeconds(com.parameters[4]) + " "
            + (com.parameters[5] ? tr("(Wait)") : "");
    }

    QString stringizeFlashScreen(const RPG::EventCommand& com)
    {
        if (com.parameters.size() > 6)
        {
            if (com.parameters[6] == 1)
                return tr("Flash Screen") + ": " + tr("Start");
            else if (com.parameters[6] == 2)
                return tr("Flash Screen") + ": " + tr("Stop");
        }

        return tr("Flash Screen") + ": ("
            + "R" + QString::number(com.parameters[0]) + ","
            + "G" + QString::number(com.parameters[1]) + ","
            + "B" + QString::number(com.parameters[2]) + ","
            + "S" + QString::number(com.parameters[3]) + "), "
            + tenthSeconds(com.parameters[4]) + " "
            + (com.parameters[5] ? tr("(Wait)") : "");
    }

    QString stringizeShakeScreen(const RPG::EventCommand& com)
    {
        if (com.parameters.size() > 4)
        {
            if (com.parameters[4] == 1)
                return tr("Shake Screen") + ": " + tr("Start");
            else if (com.parameters[4] == 2)
                return tr("Shake Screen") + ": " + tr("Stop");
        }

        return tr("Shake Screen") + ": "
            + tr("Strength") + QString::number(com.parameters[0]) + ", "
            + tr("Speed") + QString::number(com.parameters[1]) + ", "
            + tenthSeconds(com.parameters[4]) + " "
            + (com.parameters[5] ? tr("(Wait)") : "");
    }

    QString stringizePanScreen(const RPG::EventCommand& com)
    {
        switch (com.parameters[0])
        {
        case 0:
            return tr("Pan Screen") + ": " + tr("Lock Position");
        case 1:
            return tr("Pan Screen") + ": " + tr("Unlock Position");
        case 2:
            return tr("Pan Screen") + ": "
                + Stringizer::direction(com.parameters[1]) + " "
                + QString::number(com.parameters[2]) + " " + tr("Tiles") + ", "
                + tr("Speed") + " " + QString::number(com.parameters[3]) + " "
                + (com.parameters[4] ? tr("(Wait)") : "");
        default:
            return tr("Pan Screen") + ": " + tr("Reset Position")
                + tr("Speed") + " " + QString::number(com.parameters[3]) + " "
                + (com.parameters[4] ? tr("(Wait)") : "");
        }
    }

    QString stringizeWeatherEffects(const RPG::EventCommand& com)
    {
        QString type, strength;
        switch (com.parameters[0])
        {
        case 0:
            type = tr("None"); break;
        case 1:
            type = tr("Rain"); break;
        case 2:
            type = tr("Snow"); break;
        case 3:
            type = tr("Fog"); break;
        case 4:
            type = tr("Sandstorm"); break;
        default:
            type = tr("Unknown"); break;
        }
        switch (com.parameters[1])
        {
        case 0:
            strength = tr("Weak"); break;
        case 1:
            strength = tr("Medium"); break;
        case 2:
            strength = tr("Strong"); break;
        default:
            strength = tr("Unknown"); break;
        }

        return tr("Weather Effects") + ": " + type + ", " + strength;
    }

    QString stringizeShowPicture(const RPG::EventCommand& com)
    {
        return tr("Show Picture") + ": "
            + QString::number(com.parameters[0]) + ", "
            + QString::fromStdString(com.string);
    }

    QString stringizeMovePicture(const RPG::EventCommand& com)
    {
        return tr("Move Picture") + ": "
            + com.parameters[0] + ", ("
            + valueOrVariable(com.parameters[1], com.parameters[2]) + ","
            + valueOrVariable(com.parameters[1], com.parameters[3]) + "), "
            + tenthSeconds(com.parameters[14]) + " "
            + (com.parameters[15] ? tr("(Wait)") : "");
    }

    QString stringizeErasePicture(const RPG::EventCommand& com)
    {
        return tr("Erase Picture") + ": " + QString::number(com.parameters[0]);
    }

    QString stringizeShowBattleAnimation(const RPG::EventCommand& com)
    {
        return tr("Show Battle Animation") + ": "
            + Stringizer::animationName(com.parameters[0]) + ", "
            + characterName(com.parameters[1]) + " "
            + (com.parameters[2] ? tr("(Wait)") : "");
    }

    QString stringizeSpriteTransparency(const RPG::EventCommand& com)
    {
        return tr("Sprite Transparency") + ": "
            + tr(com.parameters[0] ? "Opaque" : "Transparent");
    }

    QString stringizeFlashSprite(const RPG::EventCommand& com)
    {
        return tr("Flash Sprite") + ": "
            + characterName(com.parameters[0]) + ", "
            + tenthSeconds(com.parameters[5]) + " "
            + tr(com.parameters[6] ? "(Wait)" : "");
    }

    QString stringizeMoveEvent(const RPG::EventCommand& com)
    {
        QString movements;
        for (int i = 4; i < 8 && i < (int)com.parameters.size(); ++i)
            movements.append(", ").append(Stringizer::moveCommand(com.parameters[i]));
        if (com.parameters.size() >= 8)
            movements.append("...");
        return tr("Move Event") + ": " + characterName(com.parameters[0]) + movements;
    }

    QString stringizeWait(const RPG::EventCommand& com)
    {
        if (com.parameters.size() <= 1 ||
            (com.parameters.size() > 1 && com.parameters[1] == 0)) {
            return tr("Wait") + ": " + tenthSeconds(com.parameters[0]) + " ";
        } else {
            return tr("Wait") + ": " + tr("Until Key Pressed");
        }
    }

    QString stringizePlayBGM(const RPG::EventCommand& com)
    {
        return tr("Play BGM") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeFadeOutBGM(const RPG::EventCommand& com)
    {
        return tr("Fade Out BGM") + ": " + QString::number(com.parameters[0] / 1000) + "s";
    }

    QString stringizePlaySound(const RPG::EventCommand& com)
    {
        return tr("Play Sound") + ": " + QString::fromStdString(com.string);
    }

    QString stringizePlayMovie(const RPG::EventCommand& com)
    {
        return tr("Play Movie") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeKeyInputProc(const RPG::EventCommand& com)
    {
        return tr("Key Input Proc") + ": " + variable(com.parameters[0]);
    }

    QString stringizeChangeMapTileset(const RPG::EventCommand& com)
    {
        return tr("Change Map Tileset") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeChangePBG(const RPG::EventCommand& com)
    {
        return tr("Change PBG") + ": " + QString::fromStdString(com.string)
            + (com.parameters[0] ? ", " + tr("Horz Scroll") : "")
            + (com.parameters[1] ? ", " + tr("Vert Scroll") : "");
    }

    QString stringizeChangeEncounterRate(const RPG::EventCommand& com)
    {
        return tr("Change Encounter Rate") + ": " + QString::number(com.parameters[0]);
    }

    QString stringizeTileSubstitution(const RPG::EventCommand& com)
    {
        return tr("Tile Substitution") + ": "
            + tr(com.parameters[0] ? "Upper Layer" : "Lower Layer") + ", "
            + QString::number(com.parameters[1]) + " -> "
            + QString::number(com.parameters[2]);
    }

    QString stringizeTeleportTargets(const RPG::EventCommand& com)
    {
        if (com.parameters[1])
            return tr("Teleport Targets") + ": "
                + tr("Remove") + " " + map(com.parameters[1]);
        else
            return tr("Teleport Targets") + ": "
                + tr("Add") + " " + map(com.parameters[1]) + " "
                + "(" + com.parameters[2] + "," + com.parameters[3] + ")";
    }

    QString stringizeChangeTeleportAccess(const RPG::EventCommand& com)
    {
        return tr("Change Teleport Access") + ": "
            + tr(com.parameters[0] ? "Allow" : "Forbid");
    }

    QString stringizeEscapeTarget(const RPG::EventCommand& com)
    {
        return tr("Escape Target") + ": "
            + map(com.parameters[0]) + " ("
            + com.parameters[1] + "," + com.parameters[2] + ")";
    }

    QString stringizeChangeEscapeAccess(const RPG::EventCommand& com)
    {
        return tr("Change Escape Access") + ": "
            + tr(com.parameters[0] ? "Allow" : "Forbid");
    }

    QString stringizeChangeSaveAccess(const RPG::EventCommand& com)
    {
        return tr("Change Save Access") + ": "
            + tr(com.parameters[0] ? "Allow" : "Forbid");
    }

    QString stringizeChangeMainMenuAccess(const RPG::EventCommand& com)
    {
        return tr("Change Main Menu Access") + ": "
            + tr(com.parameters[0] ? "Allow" : "Forbid");
    }

    QString stringizeConditionalBranch(const RPG::EventCommand& com)
    {
        QString condition;
        switch(com.parameters[0]) {
        case 0: // Switch
            condition = QString("S[%1:%2]").arg(com.parameters[1], 4, 10, QChar('0'))
                                           .arg(Stringizer::switchName(com.parameters[1])) + " "
                + tr(com.parameters[2] ? "ON" : "OFF");
            break;
        case 1: // Variable
            condition = variable(com.parameters[1], true) + " ";
            switch (com.parameters[4]) {
            case 0:
                condition += "=="; break;
            case 1:
                condition += ">="; break;
            case 2:
                condition += "<="; break;
            case 3:
                condition += ">"; break;
            case 4:
                condition += "<"; break;
            case 5:
                condition += "!="; break;
            default:
                condition += "?";
            }
            condition += " ";
            condition += valueOrVariable(com.parameters[2], com.parameters[3]);
            break;
        case 2: // Timer 1
            condition = tr("Timer") + "1 "
                + (com.parameters[2] ? "<=" : ">=") + " "
                + formatTime(com.parameters[1]);
            break;
        case 3: // Gold
            condition = tr("Money") + " "
                + (com.parameters[2] ? "<=" : ">=") + " "
                + QString::number(com.parameters[1]);
            break;
        case 4: // Item
            condition = Stringizer::itemName(com.parameters[1]) + " "
                + tr(com.parameters[2] ? "Not Possessed" : "Possessed");
            break;
        case 5: // Hero
            condition = Stringizer::heroName(com.parameters[1]) + ", ";
            switch (com.parameters[2])
            {
                case 0: // Is actor in party
                    condition += tr("In the Party");
                    break;
                case 1: // Name
                    condition += tr("Name is %1").arg(QString::fromStdString(com.string));
                    break;
                case 2: // Higher or equal level
                    condition += tr("Level at least %1").arg(QString::number(com.parameters[3]));
                    break;
                case 3: // Higher or equal HP
                    condition += tr("HP over %1").arg(QString::number(com.parameters[3]));
                    break;
                case 4: // Is skill learned
                    condition += tr("Can use %1").arg(Stringizer::skillName(com.parameters[3]));
                    break;
                case 5: // Equipped object
                    condition += tr("%1 is Equipped").arg(Stringizer::itemName(com.parameters[3]));
                    break;
                case 6: // Has state
                    condition += tr("with Condition %1").arg(Stringizer::conditionName(com.parameters[3]));
                    break;
                default:
                    condition += tr("Unknown");
            }
            break;
        case 6: // Orientation of char
            condition = characterName(com.parameters[1]) + " "
                + tr("Facing %1").arg(Stringizer::direction(com.parameters[2]));
            break;
        case 7: // Vehicle in use
            condition = tr("Vehicle") + " "
                + tr(com.parameters[1] == 0 ? "Boat" :
                     com.parameters[1] == 1 ? "Ship" :
                     com.parameters[1] == 2 ? "Airship" : "Unknown");
            break;
        case 8: // Key decision initiated this event
            condition = tr("Event Started with Decision Key");
            break;
        case 9: // BGM looped at least once
            condition = tr("BGM has Played Through Once");
        case 10: // Timer 2
            condition = tr("Timer") + "2 "
                + (com.parameters[2] ? "<=" : ">=") + " "
                + formatTime(com.parameters[1]);
            break;
        case 11:
            // RPG Maker 2003 v1.11 features
            // TODO
        default:
            return tr("Unknown");
        }
        return tr("Branch if") + " " + condition;
    }

    QString stringizeLabel(const RPG::EventCommand& com)
    {
        return tr("Label") + ": " + QString::number(com.parameters[0]);
    }

    QString stringizeJumpToLabel(const RPG::EventCommand& com)
    {
        return tr("Jump To Label") + ": " + QString::number(com.parameters[0]);
    }

    QString stringizeCallEvent(const RPG::EventCommand& com)
    {
        QString event;
        switch (com.parameters[0])
        {
        case 0:
            event = Stringizer::commonEventName(com.parameters[1]);
            break;
        case 1:
            event = characterName(com.parameters[1]) + "["
                + QString::number(com.parameters[2]) + "]";
            break;
        case 2:
            event = "V[" + QString::number(com.parameters[1]) + "]"
                + "[V[" + QString::number(com.parameters[2]) + "]]";
        }

        return tr("Call Event") + ": " + event;
    }

    QString stringizeComment(const RPG::EventCommand& com)
    {
        return tr("Comment") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeChangeMonsterHP(const RPG::EventCommand& com)
    {
        Q_UNUSED(com);
        // TODO
        return "ChangeMonsterHP";
    }

    QString stringizeChangeMonsterMP(const RPG::EventCommand& com)
    {
        Q_UNUSED(com);
        // TODO
        return "ChangeMonsterMP";
    }

    QString stringizeChangeMonsterCondition(const RPG::EventCommand& com)
    {
        Q_UNUSED(com);
        // TODO
        return "ChangeMonsterCondition";
    }

    QString stringizeShowHiddenMonster(const RPG::EventCommand& com)
    {
        return tr("Show Hidden Monster") + ": " + QString::number(com.parameters[0]);
    }

    QString stringizeChangeBattleBG(const RPG::EventCommand& com)
    {
        return tr("Change Battle BG") + ": " + QString::fromStdString(com.string);
    }

    QString stringizeShowBattleAnimation_B(const RPG::EventCommand& com)
    {
        Q_UNUSED(com);
        // TODO
        return "ShowBattleAnimation_B";
    }

    QString stringizeConditionalBranch_B(const RPG::EventCommand& com)
    {
        Q_UNUSED(com);
        // TODO
        return "ConditionalBranch_B";
    }

    QString stringizeShowMessage_2(const RPG::EventCommand& com)
    {
        return "    " + QString::fromStdString(com.string);
    }

    QString stringizeShowChoiceOption(const RPG::EventCommand& com)
    {
        return com.string.empty() ? tr("Cancel") : "[" + QString::fromStdString(com.string) + "]";
    }

    QString stringizeComment_2(const RPG::EventCommand& com)
    {
        return "    " + QString::fromStdString(com.string);
    }
}

namespace Stringizer
{
    QString varName(int id)
    {
        if (id < 1 || id > (int)Data::variables.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::variables[id-1].name);
    }

    QString switchName(int id)
    {
        if (id < 1 || id > (int)Data::switches.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::switches[id-1].name);
    }

    QString itemName(int id)
    {
        if (id < 1 || id > (int)Data::items.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::items[id-1].name);
    }

    QString heroName(int id)
    {
        if (id < 1 || id > (int)Data::actors.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::actors[id-1].name);
    }

    QString className(int id)
    {
        if (id < 1 || id > (int)Data::classes.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::classes[id-1].name);
    }

    QString stateName(int id)
    {
        if (id < 1 || id > (int)Data::states.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::states[id-1].name);
    }

    QString skillName(int id)
    {
        if (id < 1 || id > (int)Data::skills.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::skills[id-1].name);
    }

    QString battleCommandName(int id)
    {
        if (id < 1 || id > (int)Data::battlecommands.commands.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::battlecommands.commands[id-1].name);
    }


    QString animationName(int id)
    {
        if (id < 1 || id > (int)Data::animations.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::animations[id-1].name);
    }
    QString conditionName(int id)
    {
        if (id < 1 || id > (int)Data::states.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::states[id-1].name);
    }

    QString eventName(int id)
    {
        if (!mCore->currentMapEvent(id))
            return QString("<%1?>").arg(id);
        return QString::fromStdString(mCore->currentMapEvent(id)->name);
    }

    QString commonEventName(int id)
    {
        if (id < 1 || id > (int)Data::commonevents.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::commonevents[id-1].name);
    }

    QString troopName(int id)
    {
        if (id < 1 || id > (int)Data::troops.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::troops[id-1].name);
    }

    QString terrainName(int id)
    {
        if (id < 1 || id > (int)Data::terrains.size())
            return QString("<%1?>").arg(id);
        return QString::fromStdString(Data::terrains[id-1].name);
    }

    QString mapName(int id)
    {
        if (id < 1 || id > (int)Data::treemap.maps.size())
            return QString("<%1?>").arg(id);
        for (unsigned i = 0; i < Data::treemap.maps.size(); i++)
            if (Data::treemap.maps[i].ID == id)
                return QString::fromStdString(Data::treemap.maps[i].name);
        return QString("<NotFound:%1?>").arg(id);
    }

    QString direction(int id)
    {
        switch (id)
        {
        case 0: return tr("Up");
        case 1: return tr("Right");
        case 2: return tr("Down");
        case 3: return tr("Left");
        case 4: return tr("Up/Right");
        case 5: return tr("Down/Right");
        case 6: return tr("Down/Left");
        case 7: return tr("Up/Left");
        default: return tr("Unknown");
        }
    }

    QString moveCommand(int id)
    {
        using C = RPG::MoveCommand::Code;
        switch (id)
        {
        case C::move_up:                     return tr("Move Up");
        case C::move_right:                  return tr("Move Right");
        case C::move_down:                   return tr("Move Down");
        case C::move_left:                   return tr("Move Left");
        case C::move_upright:                return tr("Move Up/Right");
        case C::move_downright:              return tr("Move Down/Right");
        case C::move_downleft:               return tr("Move Down/Left");
        case C::move_upleft:                 return tr("Move Up/Left");
        case C::move_random:                 return tr("Move Randomly");
        case C::move_towards_hero:           return tr("Move Towards Hero");
        case C::move_away_from_hero:         return tr("Move Away from Hero");
        case C::move_forward:                return tr("Move Forward");
        case C::face_up:                     return tr("Face Up");
        case C::face_right:                  return tr("Face Right");
        case C::face_down:                   return tr("Face Down");
        case C::face_left:                   return tr("Face Left");
        case C::turn_90_degree_right:        return tr("Turn 90° Right");
        case C::turn_90_degree_left:         return tr("Turn 90° Left");
        case C::turn_180_degree:             return tr("Turn 180°");
        case C::turn_90_degree_random:       return tr("Turn 90° Randomly");
        case C::face_random_direction:       return tr("Face Random Direction");
        case C::face_hero:                   return tr("Face Hero");
        case C::face_away_from_hero:         return tr("Turn Away from Hero");
        case C::wait:                        return tr("Wait");
        case C::begin_jump:                  return tr("Begin Jump");
        case C::end_jump:                    return tr("End Jump");
        case C::lock_facing:                 return tr("Lock Facing");
        case C::unlock_facing:               return tr("Unlock Facing");
        case C::increase_movement_speed:     return tr("Increase Movement Speed");
        case C::decrease_movement_speed:     return tr("Decrease Movement Speed");
        case C::increase_movement_frequence: return tr("Increase Movement Frequency");
        case C::decrease_movement_frequence: return tr("Decrease Movement Frequency");
        case C::switch_on:                   return tr("Switch ON");
        case C::switch_off:                  return tr("Switch OFF");
        case C::change_graphic:              return tr("Change Graphic");
        case C::play_sound_effect:           return tr("Play Sound Effect");
        case C::walk_everywhere_on:          return tr("Walk Everywhere ON");
        case C::walk_everywhere_off:         return tr("Walk Everywhere OFF");
        case C::stop_animation:              return tr("Stop Animation");
        case C::start_animation:             return tr("Start Animation");
        case C::increase_transp:             return tr("Increase Transparency");
        case C::decrease_transp:             return tr("Decrease Transparency");
        default:                             return tr("Unknown");
        }
    }

    QString eraseTransitionName(int id)
    {
        static const std::vector<QString> erase_transitions =
            {
                tr("Fade Out"),
                tr("Random Blocks"),
                tr("Random Blocks Up"),
                tr("Random Blocks Down"),
                tr("Blind Close"),
                tr("Vertical Stripes Out"),
                tr("Horizontal Stripes Out"),
                tr("Border to Center Out"),
                tr("Scroll Up Out"),
                tr("Scroll Down Out"),
                tr("Scroll Left Out"),
                tr("Vertical Division"),
                tr("Horizontal Division"),
                tr("Cross Division"),
                tr("Zoom In"),
                tr("Mosaic Out"),
                tr("Wave Out"),
                tr("Instant")
            };
        if (id < 0)
            return tr("Use Default");
        else if (id >= (int)erase_transitions.size())
            return tr("Unknown");
        else
            return erase_transitions[id];
    }

    QString showTransitionName(int id)
    {
        static const std::vector<QString> show_transitions =
            {
                tr("Fade In"),
                tr("Random Blocks"),
                tr("Random Blocks Up"),
                tr("Random Blocks Down"),
                tr("Blind Open"),
                tr("Vertical Stripes In"),
                tr("Horizontal Stripes In"),
                tr("Border to Center In"),
                tr("Center to Border In"),
                tr("Scroll Up In"),
                tr("Scroll Down In"),
                tr("Scroll Left In"),
                tr("Vertical Combine"),
                tr("Horizontal Combine"),
                tr("Cross Combine"),
                tr("Zoom Out"),
                tr("Mosaic In"),
                tr("Wave In"),
                tr("Instant")
            };
        if (id < 0)
            return tr("Use Default");
        else if (id >= (int)show_transitions.size())
            return tr("Unknown");
        else
            return show_transitions[id];
    }

    QString stringize(const RPG::EventCommand& com)
    {
        using C = RPG::EventCommand::Code;
        switch (com.code)
        {
        case C::END:                     return "";
        case C::CallCommonEvent:         return stringizeCallCommonEvent(com);
        case C::ForceFlee:               return stringizeForceFlee(com);
        case C::EnableCombo:             return stringizeEnableCombo(com);
        case C::ChangeClass:             return stringizeChangeClass(com);
        case C::ChangeBattleCommands:    return stringizeChangeBattleCommands(com);
        case C::ShowMessage:             return stringizeShowMessage(com);
        case C::MessageOptions:          return stringizeMessageOptions(com);
        case C::ChangeFaceGraphic:       return stringizeChangeFaceGraphic(com);
        case C::ShowChoice:              return stringizeShowChoice(com);
        case C::InputNumber:             return stringizeInputNumber(com);
        case C::ControlSwitches:         return stringizeControlSwitches(com);
        case C::ControlVars:             return stringizeControlVars(com);
        case C::TimerOperation:          return stringizeTimerOperation(com);
        case C::ChangeGold:              return stringizeChangeGold(com);
        case C::ChangeItems:             return stringizeChangeItems(com);
        case C::ChangePartyMembers:      return stringizeChangePartyMembers(com);
        case C::ChangeExp:               return stringizeChangeExp(com);
        case C::ChangeLevel:             return stringizeChangeLevel(com);
        case C::ChangeParameters:        return stringizeChangeParameters(com);
        case C::ChangeSkills:            return stringizeChangeSkills(com);
        case C::ChangeEquipment:         return stringizeChangeEquipment(com);
        case C::ChangeHP:                return stringizeChangeHP(com);
        case C::ChangeSP:                return stringizeChangeSP(com);
        case C::ChangeCondition:         return stringizeChangeCondition(com);
        case C::FullHeal:                return stringizeFullHeal(com);
        case C::SimulatedAttack:         return stringizeSimulatedAttack(com);
        case C::ChangeHeroName:          return stringizeChangeHeroName(com);
        case C::ChangeHeroTitle:         return stringizeChangeHeroTitle(com);
        case C::ChangeSpriteAssociation: return stringizeChangeSpriteAssociation(com);
        case C::ChangeActorFace:         return stringizeChangeActorFace(com);
        case C::ChangeVehicleGraphic:    return stringizeChangeVehicleGraphic(com);
        case C::ChangeSystemBGM:         return stringizeChangeSystemBGM(com);
        case C::ChangeSystemSFX:         return stringizeChangeSystemSFX(com);
        case C::ChangeSystemGraphics:    return stringizeChangeSystemGraphics(com);
        case C::ChangeScreenTransitions: return stringizeChangeScreenTransitions(com);
        case C::EnemyEncounter:          return stringizeEnemyEncounter(com);
        case C::OpenShop:                return stringizeOpenShop(com);
        case C::ShowInn:                 return stringizeShowInn(com);
        case C::EnterHeroName:           return stringizeEnterHeroName(com);
        case C::Teleport:                return stringizeTeleport(com);
        case C::MemorizeLocation:        return stringizeMemorizeLocation(com);
        case C::RecallToLocation:        return stringizeRecallToLocation(com);
        case C::EnterExitVehicle:        return tr("Enter/Exit Vehicle");
        case C::SetVehicleLocation:      return stringizeSetVehicleLocation(com);
        case C::ChangeEventLocation:     return stringizeChangeEventLocation(com);
        case C::TradeEventLocations:     return stringizeTradeEventLocations(com);
        case C::StoreTerrainID:          return stringizeStoreTerrainID(com);
        case C::StoreEventID:            return stringizeStoreEventID(com);
        case C::EraseScreen:             return stringizeEraseScreen(com);
        case C::ShowScreen:              return stringizeShowScreen(com);
        case C::TintScreen:              return stringizeTintScreen(com);
        case C::FlashScreen:             return stringizeFlashScreen(com);
        case C::ShakeScreen:             return stringizeShakeScreen(com);
        case C::PanScreen:               return stringizePanScreen(com);
        case C::WeatherEffects:          return stringizeWeatherEffects(com);
        case C::ShowPicture:             return stringizeShowPicture(com);
        case C::MovePicture:             return stringizeMovePicture(com);
        case C::ErasePicture:            return stringizeErasePicture(com);
        case C::ShowBattleAnimation:     return stringizeShowBattleAnimation(com);
        case C::SpriteTransparency:      return stringizeSpriteTransparency(com);
        case C::FlashSprite:             return stringizeFlashSprite(com);
        case C::MoveEvent:               return stringizeMoveEvent(com);
        case C::ProceedWithMovement:     return tr("Proceed With Movement");
        case C::HaltAllMovement:         return tr("Halt All Movement");
        case C::Wait:                    return stringizeWait(com);
        case C::PlayBGM:                 return stringizePlayBGM(com);
        case C::FadeOutBGM:              return stringizeFadeOutBGM(com);
        case C::MemorizeBGM:             return tr("Memorize BGM");
        case C::PlayMemorizedBGM:        return tr("Play Memorized BGM");
        case C::PlaySound:               return stringizePlaySound(com);
        case C::PlayMovie:               return stringizePlayMovie(com);
        case C::KeyInputProc:            return stringizeKeyInputProc(com);
        case C::ChangeMapTileset:        return stringizeChangeMapTileset(com);
        case C::ChangePBG:               return stringizeChangePBG(com);
        case C::ChangeEncounterRate:     return stringizeChangeEncounterRate(com);
        case C::TileSubstitution:        return stringizeTileSubstitution(com);
        case C::TeleportTargets:         return stringizeTeleportTargets(com);
        case C::ChangeTeleportAccess:    return stringizeChangeTeleportAccess(com);
        case C::EscapeTarget:            return stringizeEscapeTarget(com);
        case C::ChangeEscapeAccess:      return stringizeChangeEscapeAccess(com);
        case C::OpenSaveMenu:            return "Open Save Menu";
        case C::ChangeSaveAccess:        return stringizeChangeSaveAccess(com);
        case C::OpenMainMenu:            return "Open Main Menu";
        case C::ChangeMainMenuAccess:    return stringizeChangeMainMenuAccess(com);
        case C::ConditionalBranch:       return stringizeConditionalBranch(com);
        case C::Label:                   return stringizeLabel(com);
        case C::JumpToLabel:             return stringizeJumpToLabel(com);
        case C::Loop:                    return tr("Loop");
        case C::BreakLoop:               return tr("Break Loop");
        case C::EndEventProcessing:      return tr("End Event Processing");
        case C::EraseEvent:              return tr("Erase Event");
        case C::CallEvent:               return stringizeCallEvent(com);
        case C::Comment:                 return stringizeComment(com);
        case C::GameOver:                return tr("Game Over");
        case C::ReturntoTitleScreen:     return tr("Return to Title Screen");
        case C::ChangeMonsterHP:         return stringizeChangeMonsterHP(com);
        case C::ChangeMonsterMP:         return stringizeChangeMonsterMP(com);
        case C::ChangeMonsterCondition:  return stringizeChangeMonsterCondition(com);
        case C::ShowHiddenMonster:       return stringizeShowHiddenMonster(com);
        case C::ChangeBattleBG:          return stringizeChangeBattleBG(com);
        case C::ShowBattleAnimation_B:   return stringizeShowBattleAnimation_B(com);
        case C::ConditionalBranch_B:     return stringizeConditionalBranch_B(com);
        case C::TerminateBattle:         return tr("Terminate Battle");
        case C::ShowMessage_2:           return stringizeShowMessage_2(com);
        case C::ShowChoiceOption:        return stringizeShowChoiceOption(com);
        case C::ShowChoiceEnd:           return tr("End");
        case C::VictoryHandler:          return tr("Victory");
        case C::EscapeHandler:           return tr("Escape");
        case C::DefeatHandler:           return tr("Defeat");
        case C::EndBattle:               return tr("End");
        case C::Transaction:             return tr("Transaction");
        case C::NoTransaction:           return tr("No Transaction");
        case C::EndShop:                 return tr("End");
        case C::Stay:                    return tr("Stay");
        case C::NoStay:                  return tr("No Stay");
        case C::EndInn:                  return tr("End");
        case C::ElseBranch:              return tr("Else");
        case C::EndBranch:               return tr("End");
        case C::EndLoop:                 return tr("End Loop");
        case C::Comment_2:               return stringizeComment_2(com);
        case C::ElseBranch_B:            return tr("Else");
        case C::EndBranch_B:             return tr("End");
        default:                         return tr("Unknown Command");
        }
    }
}
