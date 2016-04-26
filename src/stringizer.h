#ifndef STRINGIZER_H
#define STRINGIZER_H

#include <QString>
#include "rpg_eventcommand.h"

namespace Stringizer {
    QString stringize(const RPG::EventCommand& com);

    // Common stringize operations
    QString varName(int id);
    QString switchName(int id);
    QString itemName(int id);
    QString heroName(int id);
    QString className(int id);
    QString stateName(int id);
    QString skillName(int id);
    QString battleCommandName(int id);
    QString animationName(int id);
    QString conditionName(int id);
    QString eventName(int id);
    QString commonEventName(int id);
    QString troopName(int id);
    QString terrainName(int id);
    QString mapName(int id);
    QString direction(int id);
    QString moveCommand(int id);
    QString eraseTransitionName(int id);
    QString showTransitionName(int id);
}
#endif // STRINGIZER_H
