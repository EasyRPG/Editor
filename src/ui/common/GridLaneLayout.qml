// SPDX-FileCopyrightText: EasyRPG Editor Authors
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami

/**
 * A Grid Lane Layout (or Masonry Layout) is similar to a Grid Layout but
 * with the difference that for each column the gaps are filled.
 *
 * Grid Layout:
 * AB
 * -B
 * -B
 * CD
 *
 * Grid Lane Layout (ShortestColumn: Inserts in the column with the lowest Y)
 * AB
 * CB
 * DB
 *
 * Grid Lane Layout (Sequential: Insertion order of the elements)
 * A and C are always in 1st column, B and D in 2nd
 * AB
 * CB
 * -B
 * -D
 *
 * The layout is responsive and will increase/decrease depending on the width
 * of the window.
 *
 */
Item {
    id: root

    property int columns: {
        for (var i = columnMax; i > 0; --i) {
            if (width > Kirigami.Units.gridUnit * columnWidth * i) {
                return Math.min(i, repeater.count);
            }
        }
        return 1;
    }

    /** Max amount of columns to use */
    property int columnMax: 4
    /** Size of a column (value is multiplied with gridUnit) */
    property int columnWidth: 16

    property var model: []
    property Component delegate: Component {
        Loader { sourceComponent: modelData }
    }

    enum PlacementMode {
        /** Component is placed in column with lowest Y */
        ShortestColumn = 0,
        /** Component is placed in order */
        Sequential = 1
    }

    property int placementMode: GridLaneLayout.PlacementMode.ShortestColumn

    property int spacing: Kirigami.Units.largeSpacing

    width: parent ? parent.width : 0
    height: implicitHeight

    implicitHeight: {
        var mx = 0;
        if (heights) {
            for (var i = 0; i < root.columns; i++) {
                if (heights[i] > mx) mx = heights[i];
            }
        }
        return mx;
    }

    property var heights: []
    property int effectiveColumnWidth: Kirigami.Units.gridUnit * columnWidth

    Repeater {
        id: repeater
        model: root.model
        delegate: root.delegate

        onItemAdded: function(index, item) {
            item.width = Qt.binding(function() {
                 return root.effectiveColumnWidth;
            });

            item.heightChanged.connect(root.doRelayout)
            if (item.hasOwnProperty("implicitHeight")) {
                item.implicitHeightChanged.connect(root.doRelayout)
            }

            if (item.hasOwnProperty("item")) {
                item.itemChanged.connect(function() {
                    if (item.item) {
                        item.item.heightChanged.connect(root.doRelayout)
                        root.doRelayout()
                    }
                })
                if (item.item) {
                    item.item.heightChanged.connect(root.doRelayout)
                }
            }

            root.doRelayout();
        }

        onItemRemoved: function(index, item) {
            root.doRelayout()
        }
    }

    Connections {
        target: root
        function onPlacementModeChanged() { root.doRelayout() }
        function onColumnsChanged() { root.doRelayout() }
        function onWidthChanged() { root.doRelayout() }
    }

    // Grid Lane Distribution based on dynamic heights
    function doRelayout() {
        if (!repeater.count) {
            root.heights = [];
            return;
        }

        var colHeights = new Array(root.columns).fill(0);

        var prefW = Kirigami.Units.gridUnit * root.columnWidth;
        var maxW = prefW + (Kirigami.Units.gridUnit * root.columnWidth) / 2;

        var available = Math.max(0, root.width - (root.columns - 1) * root.spacing);
        var fitW = Math.floor(available / root.columns);
        var colW = Math.min(maxW, Math.max(1, fitW));

        root.effectiveColumnWidth = colW;
        var totalGridWidth = root.columns * colW + (root.columns - 1) * root.spacing;
        var offsetX = Math.max(0, (root.width - totalGridWidth) / 2);

        for (var i = 0; i < repeater.count; ++i) {
            var obj = repeater.itemAt(i);
            if (!obj) continue;

            var targetCol = 0;
            if (root.placementMode === 1) {
                targetCol = i % root.columns;
            } else {
                // Find shortest column
                var minH = colHeights[0];
                for (var j = 1; j < root.columns; ++j) {
                    if (colHeights[j] < minH) {
                        targetCol = j;
                        minH = colHeights[j];
                    }
                }
            }

            // Reposition item
            obj.x = offsetX + targetCol * (colW + root.spacing);
            obj.y = colHeights[targetCol];

            // Resolve actual element height
            var h = obj.height;
            if (h === 0 && obj.implicitHeight > 0) h = obj.implicitHeight;
            if (h === 0 && obj.item && obj.item.height > 0) h = obj.item.height;

            colHeights[targetCol] += (h || 100) + root.spacing;
        }

        root.heights = colHeights;
    }
}
