/*
 *  SPDX-FileCopyrightText: 2017 Marco Martin <mart@kde.org>
 *  SPDX-FileCopyrightText: 2022 ivan tkachenko <me@ratijas.tk>
 *  SPDX-FileCopyrightText: EasyRPG Editor Authors
 *
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

import QtQuick
import QtQuick.Layouts
import QtQuick.Templates as T
import org.kde.kirigami as Kirigami

/*
Vendored Kirigami Form Layout to make small adjustments possible
The Form Layout is not designed by default for dense UIs like our Editor
*/

/*!
  \qmltype FormLayout
  \inqmlmodule org.kde.kirigami.layouts

  \brief The base class for Form layouts conforming to the
  Kirigami Human Interface Guidelines.

  The layout consists of two columns:
  the left column contains only right-aligned
  labels provided by a FormData attached property,
  the right column contains left-aligned child types.

  Child types can be sectioned using an QtQuick.Item
  or Kirigami.Separator with a FormData
  attached property, see FormLayoutAttached::isSection for details.

  Example usage:
  \qml
  import QtQuick.Controls as QQC2
  import org.kde.kirigami as Kirigami

  Kirigami.FormLayout {
     QQC2.TextField {
        Kirigami.FormData.label: "Label:"
     }
     Kirigami.Separator {
         Kirigami.FormData.label: "Section Title"
         Kirigami.FormData.isSection: true
     }
     QQC2.TextField {
        Kirigami.FormData.label: "Label:"
     }
     QQC2.TextField {
     }
  }
  \endqml
  \sa FormData
  \since 2.3
 */
Item {
    id: root

    /*!
      \brief This property tells whether the form layout is in wide mode.

      If true, the layout will be optimized for a wide screen, such as
      a desktop machine (the labels will be on a left column,
      the fields on a right column beside it), if false (such as on a phone)
      everything is laid out in a single column.

      By default this property automatically adjusts the layout
      if there is enough screen space.

      Set this to \c true for a convergent design,
      set this to \c false for a mobile-only design.
     */
    property bool wideMode: false // EasyRPG Modification: Force mobile layout (Labels always above controls)

    /*!
      If for some implementation reason multiple FormLayouts have to appear
      on the same page, they can have each other in twinFormLayouts,
      so they will vertically align with each other perfectly

      \since 5.53
     */
    property list<Item> twinFormLayouts  // should be list<FormLayout> but we can't have a recursive declaration

    onTwinFormLayoutsChanged: {
        for (const twinFormLayout of twinFormLayouts) {
            if (!(root in twinFormLayout.children[0].reverseTwins)) {
                twinFormLayout.children[0].reverseTwins.push(root)
                Qt.callLater(() => twinFormLayout.children[0].reverseTwinsChanged());
            }
        }
    }

    property Kirigami.ScrollablePage scrollablePage: findAncestor(root, (item) => item instanceof Kirigami.ScrollablePage) as Kirigami.ScrollablePage

    function findAncestor(item: Item, predicate: /*function Item => bool*/ var): Item {
        let target = item.parent
        while (target && !predicate(target)) {
            target = target.parent
        }
        return target
    }

    function ensureVisible(item: Item): void {
        if (item && root.scrollablePage) {
            const itemPosition = scrollablePage.flickable.contentItem.mapFromItem(item, 0, 0)
            root.scrollablePage.ensureVisible(item, itemPosition.x - item.x, itemPosition.y - item.y)
        }
    }

    Connections {
        target: root.Window
        enabled: root.scrollablePage
        function onActiveFocusItemChanged(): void {
            if (root.Window.activeFocusItem && root.findAncestor(root.Window.activeFocusItem, (item) => item === root)) {
                root.ensureVisible(root.Window.activeFocusItem)
            }
        }
    }

    Component.onDestruction: {
        for (const twinFormLayout of twinFormLayouts) {
            const child = twinFormLayout.children[0];
            child.reverseTwins = child.reverseTwins.filter(value => value !== root);
        }
    }

    implicitWidth: lay.wideImplicitWidth
    implicitHeight: lay.implicitHeight
    Layout.preferredHeight: lay.implicitHeight
    Layout.fillWidth: true
    Accessible.role: Accessible.Form

    GridLayout {
        id: lay
        property int wideImplicitWidth
        columns: root.wideMode ? 2 : 1
        rowSpacing: Kirigami.Units.smallSpacing
        columnSpacing: Kirigami.Units.largeSpacing

        width: root.width // EasyRPG Modification: Use full width
        anchors.horizontalCenter: root.horizontalCenter

        property var reverseTwins: []
        property var knownItems: []
        property var buddies: []
        property int knownItemsImplicitWidth: {
            let hint = 0;
            for (const item of knownItems) {
                if (typeof item.Layout === "undefined") {
                    // Items may have been dynamically destroyed. Even
                    // printing such zombie wrappers results in a
                    // meaningless "TypeError: Type error". Normally they
                    // should be cleaned up from the array, but it would
                    // trigger a binding loop if done here.
                    //
                    // This is, so far, the only way to detect them.
                    continue;
                }
                const actualWidth = item.Layout.preferredWidth > 0
                    ? item.Layout.preferredWidth
                    : item.implicitWidth;

                hint = Math.max(hint, item.Layout.minimumWidth, Math.min(actualWidth, item.Layout.maximumWidth));
            }
            return hint;
        }
        property int buddiesImplicitWidth: {
            let hint = 0;

            for (const buddy of buddies) {
                if (buddy.visible && buddy.item !== null && !buddy.item.Kirigami.FormData.isSection) {
                    hint = Math.max(hint, buddy.implicitWidth);
                }
            }
            return hint;
        }
        readonly property var actualTwinFormLayouts: {
            // We need to copy that array by value
            const list = lay.reverseTwins.slice();
            for (const parentLay of root.twinFormLayouts) {
                if (!parentLay || !parentLay.hasOwnProperty("children")) {
                    continue;
                }
                list.push(parentLay);
                for (const childLay of parentLay.children[0].reverseTwins) {
                    if (childLay && !(childLay in list)) {
                        list.push(childLay);
                    }
                }
            }
            return list;
        }

        Timer {
            id: hintCompression
            interval: 0
            onTriggered: {
                if (root.wideMode) {
                    lay.wideImplicitWidth = lay.implicitWidth;
                }
            }
        }
        onImplicitWidthChanged: hintCompression.restart();
        //This invisible row is used to sync alignment between multiple layouts

        Item {
            id: leadingPlaceholder
            Layout.preferredWidth: {
                let hint = lay.buddiesImplicitWidth;
                for (const item of lay.actualTwinFormLayouts) {
                    if (item && item.hasOwnProperty("children")) {
                        hint = Math.max(hint, item.children[0].buddiesImplicitWidth);
                    }
                }
                return hint;
            }
            Layout.preferredHeight: 2
        }
        Item {
            id: trailingPlaceholder
            Layout.preferredWidth: {
                let hint = Math.min(root.width, lay.knownItemsImplicitWidth);
                for (const item of lay.actualTwinFormLayouts) {
                    if (item.hasOwnProperty("children")) {
                        hint = Math.max(hint, item.children[0].knownItemsImplicitWidth);
                    }
                }
                return hint;
            }
            Layout.preferredHeight: 2
        }
    }

    Item {
        id: temp

        /*!
         * The following two functions are used in the label buddy items.
         *
         * They're in this mostly unused item to keep them private to the FormLayout
         * without creating another QObject.
         *
         * Normally, such complex things in bindings are kinda bad for performance
         * but this is a fairly static property. If for some reason an application
         * decides to obsessively change its alignment, V8's JIT hotspot optimisations
         * will kick in.
         */

        /*!
         * @param {Item} item
         * @returns {Qt::Alignment}
         */
        function effectiveLayout(item: Item): /*Qt.Alignment*/ int {
            if (!item) {
                return 0;
            }
            const verticalAlignment =
                item.Kirigami.FormData.labelAlignment !== 0
                ? item.Kirigami.FormData.labelAlignment
                : Qt.AlignTop;

            if (item.Kirigami.FormData.isSection) {
                return Qt.AlignHCenter;
            }
            if (root.wideMode) {
                return Qt.AlignRight | verticalAlignment;
            }
            return Qt.AlignLeft | Qt.AlignBottom;
        }

        /*!
         * @param {Item} item
         * @returns vertical alignment of the item passed as an argument.
         */
        function effectiveTextLayout(item: Item): /*Qt.Alignment*/ int {
            if (!item) {
                return 0;
            }
            if (root.wideMode && !item.Kirigami.FormData.isSection) {
                return item.Kirigami.FormData.labelAlignment !== 0 ? item.Kirigami.FormData.labelAlignment : Text.AlignVCenter;
            }
            return Text.AlignBottom;
        }
    }

    function relayout() {
        const __items = root.children;
        // exclude the layout and temp
        let row = 0;
        for (let i = 2; i < __items.length; ++i) {
            const item = __items[i];

            if (!(item instanceof Repeater)) {
                item.Layout.row = row;
                item.Layout.column = 1;
                row += root.wideMode && !item.Kirigami.FormData.isSection ? 1 : 2;
            }

            // skip items that are already there
            if (lay.knownItems.indexOf(item) !== -1 || item instanceof Repeater) {
                continue;
            }
            lay.knownItems.push(item);

            const itemContainer = itemComponent.createObject(lay, { item });
            const buddy = buddyComponent.createObject(lay, { item, index: i - 2 });

            lay.buddies.push(buddy);
        }

        leadingPlaceholder.Layout.row = row
        leadingPlaceholder.Layout.column = 0
        trailingPlaceholder.Layout.row = Qt.binding(() => row + (root.wideMode ? 0 : 1))
        trailingPlaceholder.Layout.column = Qt.binding(() => root.wideMode ? 1 : 0)

        lay.knownItemsChanged();
        lay.buddiesChanged();
        hintCompression.restart();
    }

    onChildrenChanged: relayout()
    Component.onCompleted: {
        relayout()
        hintCompression.triggered()
    }
    onWideModeChanged: relayout()

    Component {
        id: itemComponent
        Item {
            id: container

            property Item item

            Layout.row: item?.Layout?.row + (root.wideMode && !item.Kirigami.FormData.isSection ? 0 : 1)
            Layout.column: root.wideMode && !item?.Kirigami.FormData.isSection ? 1 : 0

            enabled: item?.enabled ?? false
            visible: item?.visible ?? false

            // NOTE: work around a  GridLayout quirk which doesn't lay out items with null size hints causing things to be laid out incorrectly in some cases
            implicitWidth: item !== null ? Math.max(item.implicitWidth, 1) : 0
            implicitHeight: item !== null ? Math.max(item.implicitHeight, 1) : 0
            Layout.preferredWidth: item !== null ? Math.max(1, item.Layout.preferredWidth > 0 ? item.Layout.preferredWidth : Math.ceil(item.implicitWidth)) : 0
            Layout.preferredHeight: item !== null ? Math.max(1, item.Layout.preferredHeight > 0 ? item.Layout.preferredHeight : Math.ceil(item.implicitHeight)) : 0

            Layout.minimumWidth: item?.Layout.minimumWidth ?? 0
            Layout.minimumHeight: item?.Layout.minimumHeight ?? 0

            Layout.maximumWidth: item?.Layout.maximumWidth ?? 0
            Layout.maximumHeight: item?.Layout.maximumHeight ?? 0

            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            Layout.fillWidth: item !== null && (item instanceof TextInput || item.Layout.fillWidth || item.Kirigami.FormData.isSection)
            Layout.columnSpan: item?.Kirigami.FormData.isSection ? lay.columns : 1
            onItemChanged: {
                if (!item) {
                    container.destroy();
                }
            }
            onXChanged: if (item !== null) { item.x = x + lay.x; }
            // Assume lay.y is always 0
            onYChanged: if (item !== null) { item.y = y + lay.y; }
            onWidthChanged: if (item !== null) { item.width = width; }
            Component.onCompleted: item.x = x + lay.x;
            Connections {
                target: lay
                function onXChanged(): void {
                    if (container.item !== null) {
                        container.item.x = container.x + lay.x;
                    }
                }
            }
        }
    }
    Component {
        id: buddyComponent
        Kirigami.Heading {
            id: labelItem

            property Item item
            property int index

            Layout.row: item?.Layout?.row
            Layout.column: 0

            enabled: {
                const buddy = item?.Kirigami.FormData.buddyFor;
                if (buddy) {
                    return buddy.enabled;
                } else {
                    return item?.enabled ?? false;
                }
            }
            visible: (item?.visible && (root.wideMode || text.length > 0)) ?? false
            Kirigami.MnemonicData.enabled: {
                const buddy = item?.Kirigami.FormData.buddyFor as Item;
                if (buddy && buddy.enabled && buddy.visible && buddy.activeFocusOnTab) {
                    // Only set mnemonic if the buddy doesn't already have one.
                    const buddyMnemonic = buddy.Kirigami.MnemonicData;
                    return !buddyMnemonic.label || !buddyMnemonic.enabled;
                } else {
                    return false;
                }
            }
            Kirigami.MnemonicData.controlType: Kirigami.MnemonicData.FormLabel
            Kirigami.MnemonicData.label: { // EasyRPG Modification: Append a ":" at the end of labels
                const rawLabel = item?.Kirigami.FormData.label ?? "";
                if (rawLabel.length > 0) {
                    if (rawLabel.endsWith(":")) {
                        throw new Error("Label must not end with a ':'!");
                    } else if (!(item?.Kirigami.FormData.isSection ?? false)) {
                        return rawLabel + ":";
                    }
                }
                return rawLabel;
            }
            text: Kirigami.MnemonicData.richTextLabel
            Accessible.name: Kirigami.MnemonicData.plainTextLabel
            type: item?.Kirigami.FormData.isSection ? Kirigami.Heading.Type.Primary : Kirigami.Heading.Type.Normal

            level: item?.Kirigami.FormData.isSection ? 3 : 5

            Layout.columnSpan: item?.Kirigami.FormData.isSection ? lay.columns : 1
            Layout.preferredHeight: {
                if (!item) {
                    return 0;
                }
                if (item.Kirigami.FormData.label.length > 0) {
                    // Add extra whitespace before textual section headers, which
                    // looks better than separator lines
                    if (item.Kirigami.FormData.isSection && labelItem.index !== 0) {
                        return implicitHeight + Kirigami.Units.largeSpacing * 2;
                    }
                    else if (root.wideMode && !(item.Kirigami.FormData.buddyFor instanceof TextEdit)) {
                        return Math.max(implicitHeight, item.Kirigami.FormData.buddyFor?.height ?? implicitHeight)
                    }
                    return implicitHeight;
                }
                return Kirigami.Units.smallSpacing;
            }

            Layout.alignment: temp.effectiveLayout(item)
            verticalAlignment: temp.effectiveTextLayout(item)

            Layout.fillWidth: !root.wideMode
            wrapMode: Text.Wrap

            Layout.topMargin: {
                if (!item) {
                    return 0;
                }
                if (item.Kirigami.FormData.buddyFor && root.wideMode && item.Kirigami.FormData.buddyFor.parent !== root) {
                    return item.Kirigami.FormData.buddyFor.y;
                }
                if (item?.Kirigami.FormData.isSection && text.length > 0) {
                    return Kirigami.Units.largeSpacing * 2;
                }
                if (index === 0 || root.wideMode) {
                    return 0;
                }
                // EasyRPG Modification: Reduce vertical gap in mobile mode
                return Kirigami.Units.smallSpacing;
            }
            onItemChanged: {
                if (item.Accessible.hasOwnProperty("labelledBy")) {
                    item.Accessible.labelledBy = this
                }

                if (!item) {
                    destroy();
                }
            }
            Shortcut {
                sequence: labelItem.Kirigami.MnemonicData.sequence
                onActivated: {
                    const buddy = labelItem.item.Kirigami.FormData.buddyFor;

                    const buttonBuddy = buddy as T.AbstractButton;
                    // animateClick is only in Qt 6.8,
                    // it also takes into account focus policy.
                    if (buttonBuddy && buttonBuddy.animateClick) {
                        buttonBuddy.animateClick();
                    } else {
                        buddy.forceActiveFocus(Qt.ShortcutFocusReason);
                    }
                }
            }
        }
    }
}
