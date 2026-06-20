/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#include "sprite_painted_item.h"
#include <QPainter>

SpritePaintedItem::SpritePaintedItem(QQuickItem *parent) : QQuickPaintedItem(parent) {
	setAcceptedMouseButtons(Qt::LeftButton);
}

QString SpritePaintedItem::filename() const {
	return m_filename;
}

void SpritePaintedItem::setFilename(const QString& filename) {
	if (m_filename == filename) {
		return;
	}
	m_filename = filename;
	m_image = {};
	emit filenameChanged();
	reload();
}

QString SpritePaintedItem::directory() const {
	return m_directory;
}

void SpritePaintedItem::setDirectory(const QString& directory) {
	if (m_directory == directory) {
		return;
	}
	m_directory = directory;
	m_image = {};
	emit directoryChanged();
	reload();
}

ProjectDataGadget* SpritePaintedItem::projectData() const { return m_projectData; }

void SpritePaintedItem::setProjectData(ProjectDataGadget* projectData) {
	m_projectData = projectData;
	m_image = {};
	emit projectDataChanged();
	reload();
}

bool SpritePaintedItem::pickerMode() const {
	return m_pickerMode;
}

void SpritePaintedItem::setPickerMode(bool pickerMode) {
	if (m_pickerMode == pickerMode) {
		return;
	}
	m_pickerMode = pickerMode;
	emit pickerModeChanged();
	update();
}

int SpritePaintedItem::cellIndex() const {
	return m_cellIndex;
}

void SpritePaintedItem::setCellIndex(int cellIndex) {
	if (m_cellIndex == cellIndex) {
		return;
	}
	m_cellIndex = cellIndex;
	emit cellIndexChanged();
	update();
}

int SpritePaintedItem::cellWidth() const {
	return m_cellWidth;
}

void SpritePaintedItem::setCellWidth(int cellWidth) {
	if (m_cellWidth == cellWidth) {
		return;
	}
	m_cellWidth = cellWidth;
	emit cellWidthChanged();
	update();
}

int SpritePaintedItem::cellHeight() const {
	return m_cellHeight;
}

void SpritePaintedItem::setCellHeight(int cellHeight) {
	if (m_cellHeight == cellHeight) {
		return;
	}
	m_cellHeight = cellHeight;
	emit cellHeightChanged();
	update();
}

bool SpritePaintedItem::transparent() const {
	return m_transparent;
}

void SpritePaintedItem::setTransparent(bool transparent) {
	if (m_transparent == transparent) {
		return;
	}
	m_transparent = transparent;
	emit transparentChanged();
	update();
}

int SpritePaintedItem::cellOffsetX() const {
	return m_cellOffsetX;
}

void SpritePaintedItem::setCellOffsetX(int cellOffsetX) {
	if (m_cellOffsetX == cellOffsetX) {
		return;
	}
	m_cellOffsetX = cellOffsetX;
	emit cellOffsetXChanged();
	update();
}

int SpritePaintedItem::cellOffsetY() const {
	return m_cellOffsetY;
}

void SpritePaintedItem::setCellOffsetY(int cellOffsetY) {
	if (m_cellOffsetY == cellOffsetY) {
		return;
	}
	m_cellOffsetY = cellOffsetY;
	emit cellOffsetYChanged();
	update();
}

int SpritePaintedItem::skipCellsX() const {
	return m_skipCellsX;
}

void SpritePaintedItem::setSkipCellsX(int skipCellsX) {
	if (m_skipCellsX == skipCellsX) {
		return;
	}
	m_skipCellsX = skipCellsX;
	emit skipCellsXChanged();
	update();
}

int SpritePaintedItem::skipCellsY() const {
	return m_skipCellsY;
}

void SpritePaintedItem::setSkipCellsY(int skipCellsY) {
	if (m_skipCellsY == skipCellsY) {
		return;
	}
	m_skipCellsY = skipCellsY;
	emit skipCellsYChanged();
	update();
}

int SpritePaintedItem::gridColumns() const {
	return m_gridColumns;
}

void SpritePaintedItem::setGridColumns(int gridColumns) {
	if (m_gridColumns == gridColumns) {
		return;
	}
	m_gridColumns = gridColumns;
	emit gridColumnsChanged();
	update();
}

QRectF SpritePaintedItem::sourceRect() const {
	if (m_cellWidth <= 0 || m_cellHeight <= 0) {
		return m_image.rect();
	}
	const int pitchX = m_cellWidth * (m_skipCellsX + 1);
	const int pitchY = m_cellHeight * (m_skipCellsY + 1);
	const int col = m_cellIndex % m_gridColumns;
	const int row = m_cellIndex / m_gridColumns;
	return QRectF(col * pitchX + m_cellOffsetX, row * pitchY + m_cellOffsetY, m_cellWidth, m_cellHeight);
}

void SpritePaintedItem::paint(QPainter* painter) {
	if (m_image.isNull()) {
		return;
	}

	if (m_transparent) {
		painter->setOpacity(0.5);
	}

	if (m_pickerMode) {
		if (m_cellWidth <= 0 || m_cellHeight <= 0) {
			const QSize targetSize(qMax(1, int(width())), qMax(1, int(height())));
			const QPixmap scaled = m_image.scaled(targetSize, Qt::KeepAspectRatio, Qt::FastTransformation);
			painter->drawPixmap(QRectF(0, 0, scaled.width(), scaled.height()), scaled, scaled.rect());
		} else {
			// Picker mode: draw only the non-skipped cells sequentially
			const int pitchX = m_cellWidth * (m_skipCellsX + 1);
			const int pitchY = m_cellHeight * (m_skipCellsY + 1);
			const int cols = qMax(1, m_image.width() / pitchX);
			const int rows = qMax(1, m_image.height() / pitchY);
			const int packedWidth = cols * m_cellWidth;
			const int packedHeight = rows * m_cellHeight;

			const QSize targetSize(qMax(1, int(width())), qMax(1, int(height())));
			const QSize scaledSize = QSize(packedWidth, packedHeight).scaled(targetSize, Qt::KeepAspectRatio);

			const qreal scaleX = static_cast<qreal>(scaledSize.width()) / packedWidth;
			const qreal scaleY = static_cast<qreal>(scaledSize.height()) / packedHeight;

			for (int row = 0; row < rows; ++row) {
				for (int col = 0; col < cols; ++col) {
					const QRectF srcRect(col * pitchX + m_cellOffsetX, row * pitchY + m_cellOffsetY, m_cellWidth, m_cellHeight);
					const QRectF destRect(col * m_cellWidth * scaleX, row * m_cellHeight * scaleY, m_cellWidth * scaleX, m_cellHeight * scaleY);
					painter->drawPixmap(destRect, m_image, srcRect);
				}
			}

			// Draw selection rectangle
			const int selCol = m_cellIndex % m_gridColumns;
			const int selRow = m_cellIndex / m_gridColumns;
			const QRectF selRect(
				selCol * m_cellWidth * scaleX,
				selRow * m_cellHeight * scaleY,
				m_cellWidth * scaleX,
				m_cellHeight * scaleY
			);

			if (m_transparent) {
				painter->setOpacity(1.0);
			}

			QPen selPen(Qt::white);
			selPen.setWidth(2);
			selPen.setCosmetic(true);

			painter->setPen(selPen);
			painter->setBrush(Qt::NoBrush);
			painter->drawRect(selRect);
		}
	} else {
		// Viewer mode: Draw the selected cell from the original image
		// Scaled to fill the widget
		const QRectF src = sourceRect();
		painter->drawPixmap(QRectF(0, 0, width(), height()), m_image, src);
	}

	if (m_transparent && !m_pickerMode) {
		painter->setOpacity(1.0);
	}
}

void SpritePaintedItem::mousePressEvent(QMouseEvent* event) {
	if (m_image.isNull()) {
		return;
	}

	if (!m_pickerMode) {
		return;
	}

	if (m_cellWidth <= 0 || m_cellHeight <= 0) {
		return;
	}

	const int pitchX = m_cellWidth * (m_skipCellsX + 1);
	const int pitchY = m_cellHeight * (m_skipCellsY + 1);
	const int cols = qMax(1, m_image.width() / pitchX);
	const int rows = qMax(1, m_image.height() / pitchY);
	const int packedWidth = cols * m_cellWidth;
	const int packedHeight = rows * m_cellHeight;

	const QSize targetSize(qMax(1, int(width())), qMax(1, int(height())));
	const QSize scaledSize = QSize(packedWidth, packedHeight).scaled(targetSize, Qt::KeepAspectRatio);

	const qreal scaleX = static_cast<qreal>(scaledSize.width()) / packedWidth;
	const qreal scaleY = static_cast<qreal>(scaledSize.height()) / packedHeight;

	const int col = static_cast<int>(event->pos().x() / (m_cellWidth * scaleX));
	const int row = static_cast<int>(event->pos().y() / (m_cellHeight * scaleY));

	if (col >= 0 && col < cols && row >= 0 && row < rows) {
		const int index = row * m_gridColumns + col;
		setCellIndex(index);
	}
}

void SpritePaintedItem::reload() {
	if (!projectData()) {
		return;
	}

	if (m_image.isNull()) {
		m_image = projectData()->loadImage(m_directory, m_filename);
	}

	if (!m_image.isNull()) {
		if (pickerMode()) {
			if (m_cellWidth > 0 && m_cellHeight > 0) {
				const int pitchX = m_cellWidth * (m_skipCellsX + 1);
				const int pitchY = m_cellHeight * (m_skipCellsY + 1);
				const int cols = qMax(1, m_image.width() / pitchX);
				const int rows = qMax(1, m_image.height() / pitchY);
				setImplicitSize(cols * m_cellWidth, rows * m_cellHeight);
			} else {
				setImplicitSize(m_image.width(), m_image.height());
			}
		} else {
			if (m_cellWidth > 0 && m_cellHeight > 0) {
				setImplicitSize(m_cellWidth, m_cellHeight);
			} else {
				setImplicitSize(m_image.width(), m_image.height());
			}
		}
	} else {
		setImplicitSize(m_cellWidth, m_cellHeight);
	}

	update();
}
