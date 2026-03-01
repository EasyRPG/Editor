/*
 *  SPDX-FileCopyrightText: 2015 Marco Martin <mart@kde.org>
 *
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

import QtQuick
import org.kde.kirigami as Kirigami

Kirigami.BasicThemeDefinition {
    readonly property color ezAccent: "#4DE600"
    readonly property color ezDanger: "#FF4E4E"
    readonly property color ezNeutral: "#D1C64E"
    readonly property color ezBaseBg: "#26272B"
    readonly property color ezElevatedBg: "#444450"
    readonly property color ezInputBg: "#222428"
    readonly property color ezHoverBg: "#3A3D41"
    readonly property color ezAltBg: "#2C2E33"
    readonly property color ezText: "#E0E0E0"

    textColor: ezText
    disabledTextColor: Qt.darker(ezText, 1.8)

    highlightColor: ezAccent
    highlightedTextColor: Qt.lighter(ezText, 1.5)
    backgroundColor: ezBaseBg
    alternateBackgroundColor: ezAltBg
    activeTextColor: "#000000"
    activeBackgroundColor: ezAccent
    linkColor: ezAccent
    linkBackgroundColor: "transparent"
    visitedLinkColor: Qt.darker(ezAccent, 1.3)
    visitedLinkBackgroundColor: Qt.darker(ezAccent, 1.3)
    hoverColor: ezHoverBg
    focusColor: ezAccent
    negativeTextColor: ezDanger
    negativeBackgroundColor: ezDanger
    neutralTextColor: ezNeutral
    neutralBackgroundColor: ezNeutral
    positiveTextColor: ezAccent
    positiveBackgroundColor: ezAccent

    buttonTextColor: ezText
    buttonBackgroundColor: ezElevatedBg
    buttonAlternateBackgroundColor: Qt.darker(ezElevatedBg, 1.3)
    buttonHoverColor: ezHoverBg
    buttonFocusColor: ezAccent

    viewTextColor: ezText
    viewBackgroundColor: ezBaseBg
    viewAlternateBackgroundColor: ezAltBg
    viewHoverColor: ezHoverBg
    viewFocusColor: ezAccent

    selectionTextColor: "#000000"
    selectionBackgroundColor: ezAccent
    selectionAlternateBackgroundColor: "#1B5200"
    selectionHoverColor: ezAccent
    selectionFocusColor: ezAccent

    tooltipTextColor: "#FFFFFF"
    tooltipBackgroundColor: ezInputBg
    tooltipAlternateBackgroundColor: ezElevatedBg
    tooltipHoverColor: ezHoverBg
    tooltipFocusColor: ezAccent

    complementaryTextColor: "#FFFFFF"
    complementaryBackgroundColor: ezInputBg
    complementaryAlternateBackgroundColor: ezElevatedBg
    complementaryHoverColor: ezHoverBg
    complementaryFocusColor: ezAccent

    headerTextColor: "#FFFFFF"
    headerBackgroundColor: ezElevatedBg
    headerAlternateBackgroundColor: ezAltBg
    headerHoverColor: ezHoverBg
    headerFocusColor: ezAccent

    defaultFont: fontMetrics.font

    property list<QtObject> children: [
        TextMetrics {
            id: fontMetrics
        },
        SystemPalette {
            id: palette
            colorGroup: SystemPalette.Active
        },
        SystemPalette {
            id: disabledPalette
            colorGroup: SystemPalette.Disabled
        }
    ]

    function __propagateColorSet(object, context) {}

    function __propagateTextColor(object, color) {}
    function __propagateBackgroundColor(object, color) {}
    function __propagatePrimaryColor(object, color) {}
    function __propagateAccentColor(object, color) {}
}
