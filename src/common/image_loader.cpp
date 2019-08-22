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

#include "image_loader.h"
#include <cstring>
#include <QFile>
#include <zlib.h>

QPixmap ImageLoader::Load(const QString& path) {
	QFile file(path);

	if (!file.open(QFile::ReadOnly)) {
		return QPixmap();
	}

	char header[4];
	file.read(header, 4);

	if (memcmp(header, "XYZ1", 4)) {
		file.close();

		constexpr char png_header[4] = { '\x89', 'P', 'N', 'G' };
		// Not a XYZ file, check if BMP and PNG as these are the formats supported by Player
		if (!memcmp(header, "BM", 2) || !memcmp(header, png_header, 4)) {
			return QPixmap(path);
		}
		return QPixmap();
	}

	// XYZ file processing
	file.seek(0);
	auto size = file.size();

	if (size <= 8 || size > 1024*1024*1024) {
		return QPixmap();
	}

	std::vector<char> data;
	data.resize(size);
	file.read(data.data(), size);
	file.close();

	unsigned short w;
	memcpy(&w, &data[4], 2);
	unsigned short h;
	memcpy(&h, &data[6], 2);

	uLongf src_size = (uLongf)(size - 8);
	Bytef* src_buffer = (Bytef*)&data[8];
	uLongf dst_size = 768 + (w * h);
	std::vector<Bytef> dst_buffer(dst_size);

	int status = uncompress(&dst_buffer.front(), &dst_size, src_buffer, src_size);

	if (status != Z_OK) {
		return QPixmap();
	}
	const uint8_t (*palette)[3] = (const uint8_t(*)[3]) &dst_buffer.front();

	std::vector<char> pixels;
	pixels.resize(w * h * 4);

	uint8_t* dst = (uint8_t*) pixels.data();
	const uint8_t* src = (const uint8_t*) &dst_buffer[768];
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			uint8_t pix = *src++;
			const uint8_t* color = palette[pix];
			*dst++ = color[2];
			*dst++ = color[1];
			*dst++ = color[0];
			*dst++ = 255;
		}
	}

	QImage img((uchar*)pixels.data(), w, h, QImage::Format_ARGB32);

	QPixmap pixmap(w, h);
	pixmap.convertFromImage(img);

	return pixmap;
}
