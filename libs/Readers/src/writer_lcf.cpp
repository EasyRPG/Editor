/*
 * This file is part of EasyRPG.
 *
 * EasyRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

// Headers
#include "writer_lcf.h"

LcfWriter::LcfWriter(const char* filename, std::string encoding) :
	filename(filename),
	encoding(encoding),
	stream(fopen(filename, "wb"))
{
}

LcfWriter::LcfWriter(const std::string& filename, std::string encoding) :
	filename(filename),
	encoding(encoding),
	stream(fopen(filename.c_str(), "wb"))
{
}

LcfWriter::~LcfWriter() {
	Close();
}

void LcfWriter::Close() {
	if (stream != NULL)
		fclose(stream);
	stream = NULL;
}

void LcfWriter::Write(const void *ptr, size_t size, size_t nmemb) {
#ifdef NDEBUG
	fwrite(ptr, size, nmemb, stream);
#else
	assert(fwrite(ptr, size, nmemb, stream) == nmemb);
#endif
}

template <>
void LcfWriter::Write<uint8_t>(uint8_t val) {
	Write(&val, 1, 1);
}

template <>
void LcfWriter::Write<int16_t>(int16_t val) {
	SwapByteOrder(val);
	Write(&val, 2, 1);
}

template <>
void LcfWriter::Write<uint32_t>(uint32_t val) {
	SwapByteOrder(val);
	Write(&val, 4, 1);
}

void LcfWriter::WriteInt(int val) {
	uint32_t value = (uint32_t) val;
	for (int i = 28; i >= 0; i -= 7)
		if (value >= (1U << i) || i == 0)
			Write<uint8_t>((uint8_t)(((value >> i) & 0x7F) | (i > 0 ? 0x80 : 0)));
}

template <>
void LcfWriter::Write<int>(int val) {
	WriteInt(val);
}

template <>
void LcfWriter::Write<bool>(bool val) {
	uint8_t x = val ? 1 : 0;
	Write(x);
}

template <>
void LcfWriter::Write<double>(double val) {
	SwapByteOrder(val);
	Write(&val, 8, 1);
}

template <>
void LcfWriter::Write<bool>(const std::vector<bool>& buffer) {
	std::vector<bool>::const_iterator it;
	for (it = buffer.begin(); it != buffer.end(); it++) {
		uint8_t val = *it ? 1 : 0;
		Write(val);
	}
}

template <>
void LcfWriter::Write<uint8_t>(const std::vector<uint8_t>& buffer) {
	Write(&buffer.front(), 1, buffer.size());
}

template <>
void LcfWriter::Write<int16_t>(const std::vector<int16_t>& buffer) {
	std::vector<int16_t>::const_iterator it;
	for (it = buffer.begin(); it != buffer.end(); it++)
		Write(*it);
}

template <>
void LcfWriter::Write<uint32_t>(const std::vector<uint32_t>& buffer) {
	std::vector<uint32_t>::const_iterator it;
	for (it = buffer.begin(); it != buffer.end(); it++)
		Write(*it);
}

void LcfWriter::Write(const std::string& _str) {
	std::string str = Decode(_str);
	if (!str.empty()) {
		Write(&*str.begin(), 1, str.size());
	}
}

bool LcfWriter::IsOk() const {
	return (stream != NULL && !ferror(stream));
}

std::string LcfWriter::Decode(const std::string& str_to_encode) {
#ifdef _WIN32
	return ReaderUtil::Recode(str_to_encode, "65001", encoding);
#else
	return ReaderUtil::Recode(str_to_encode, "UTF-8", encoding);
#endif
}

#ifdef READER_BIG_ENDIAN
void LcfWriter::SwapByteOrder(uint16_t& us)
{
	us =	(us >> 8) |
			(us << 8);
}

void LcfWriter::SwapByteOrder(uint32_t& ui)
{
	ui =	(ui >> 24) |
			((ui<<8) & 0x00FF0000) |
			((ui>>8) & 0x0000FF00) |
			(ui << 24);
}

void LcfWriter::SwapByteOrder(double& d)
{
	uint32_t *p = reinterpret_cast<uint32_t *>(&d);
	SwapByteOrder(p[0]);
	SwapByteOrder(p[1]);
	uint32_t tmp = p[0];
	p[0] = p[1];
	p[1] = tmp;
}
#else
void LcfWriter::SwapByteOrder(uint16_t& /* us */) {}
void LcfWriter::SwapByteOrder(uint32_t& /* ui */) {}
void LcfWriter::SwapByteOrder(double& /* d */) {}
#endif

void LcfWriter::SwapByteOrder(int16_t& s)
{
	SwapByteOrder((uint16_t&) s);
}
