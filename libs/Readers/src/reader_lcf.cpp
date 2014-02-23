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
#include <cstdarg>
#include "reader_lcf.h"

// Statics

std::string LcfReader::error_str;

LcfReader::LcfReader(const char* filename, std::string encoding) :
	filename(filename),
	encoding(encoding),
	stream(fopen(filename, "rb"))
{
}

LcfReader::LcfReader(const std::string& filename, std::string encoding) :
	filename(filename),
	encoding(encoding),
	stream(fopen(filename.c_str(), "rb"))
{
}

LcfReader::~LcfReader() {
	Close();
}

void LcfReader::Close() {
	if (stream != NULL)
		fclose(stream);
	stream = NULL;
}

size_t LcfReader::Read0(void *ptr, size_t size, size_t nmemb) {
	return fread(ptr, size, nmemb, stream);
}

void LcfReader::Read(void *ptr, size_t size, size_t nmemb) {
#ifdef NDEBUG
	Read0(ptr, size, nmemb);
#else
	assert(Read0(ptr, size, nmemb) == nmemb);
#endif
}

template <>
void LcfReader::Read<bool>(bool& ref) {
	ref = ReadInt() > 0;
}

template <>
void LcfReader::Read<uint8_t>(uint8_t& ref) {
	Read(&ref, 1, 1);
}

template <>
void LcfReader::Read<int16_t>(int16_t& ref) {
	Read(&ref, 2, 1);
	SwapByteOrder(ref);
}

template <>
void LcfReader::Read<uint32_t>(uint32_t& ref) {
	Read(&ref, 4, 1);
	SwapByteOrder(ref);
}

int LcfReader::ReadInt() {
	int value = 0;
	unsigned char temp = 0;

	do {
		value <<= 7;
		if (Read0(&temp, 1, 1) == 0) {
			assert(value == 0);
			return 0;
		}
		value |= temp & 0x7F;
	} while (temp & 0x80);
	return value;
}

template <>
void LcfReader::Read<int>(int& ref) {
	ref = ReadInt();
}

template <>
void LcfReader::Read<double>(double& ref) {
	Read(&ref, 8, 1);
	SwapByteOrder(ref);
}

template <>
void LcfReader::Read<bool>(std::vector<bool> &buffer, size_t size) {
	buffer.clear();

	for (unsigned i = 0; i < size; ++i) {
		uint8_t val;
		Read(&val, 1, 1);
		buffer.push_back(val > 0);
	}
}

template <>
void LcfReader::Read<uint8_t>(std::vector<uint8_t> &buffer, size_t size) {
	buffer.clear();

	for (unsigned int i = 0; i < size; ++i) {
		uint8_t val;
		Read(&val, 1, 1);
		buffer.push_back(val);
	}
}

template <>
void LcfReader::Read<int16_t>(std::vector<int16_t> &buffer, size_t size) {
	buffer.clear();
	size_t items = size / 2;
	for (unsigned int i = 0; i < items; ++i) {
		int16_t val;
		Read(&val, 2, 1);
		SwapByteOrder(val);
		buffer.push_back(val);
	}
}

template <>
void LcfReader::Read<uint32_t>(std::vector<uint32_t> &buffer, size_t size) {
	buffer.clear();
	size_t items = size / 4;
	for (unsigned int i = 0; i < items; ++i) {
		uint32_t val;
		Read(&val, 4, 1);
		SwapByteOrder(val);
		buffer.push_back(val);
	}
}

void LcfReader::ReadString(std::string& ref, size_t size) {
	char* chars = new char[size + 1];
	chars[size] = '\0';
	Read(chars, 1, size);
	ref = Encode(std::string(chars));
	delete[] chars;
}

bool LcfReader::IsOk() const {
	return (stream != NULL && !ferror(stream));
}

bool LcfReader::Eof() const {
	return feof(stream) != 0;
}

void LcfReader::Seek(size_t pos, SeekMode mode) {
	switch (mode) {
	case LcfReader::FromStart:
		fseek(stream, pos, SEEK_SET);
		break;
	case LcfReader::FromCurrent:
		fseek(stream, pos, SEEK_CUR);
		break;
	case LcfReader::FromEnd:
		fseek(stream, pos, SEEK_END);
		break;
	default:
		assert(false && "Invalid SeekMode");
	}
}

uint32_t LcfReader::Tell() {
	return (uint32_t)ftell(stream);
}

bool LcfReader::Ungetch(uint8_t ch) {
	return (ungetc(ch, stream) == ch);
}

#ifdef _DEBUG
void LcfReader::SkipDebug(const struct LcfReader::Chunk& chunk_info, const char* srcfile) {
	// Dump the Chunk Data in Debug Mode
#ifdef _WIN32
	const char* srcfilename = strrchr(srcfile, '\\');
#else
	const char* srcfilename = strrchr(srcfile, '/');
#endif
	if (srcfilename == NULL) {
		srcfilename = srcfile;
	} else {
		srcfilename++;
	}
	fprintf(stderr, "Skipped Chunk %02X (%d byte) in %s at %X (%s)\n",
			chunk_info.ID, chunk_info.length, filename.c_str(), Tell(),
			srcfilename);
	for (uint32_t i = 0; i < chunk_info.length; ++i) {
		uint8_t byte;
		LcfReader::Read(byte);
		fprintf(stderr, "%02X ", byte);
		if ((i+1) % 16 == 0) {
			fprintf(stderr, "\n");
		}
	}
	fprintf(stderr, "\n");
}
#else
void LcfReader::Skip(const struct LcfReader::Chunk& chunk_info) {
	Seek((size_t)chunk_info.length, FromCurrent);
}
#endif

void LcfReader::SetError(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char str[256];
	vsprintf(str, fmt, args);

	error_str = str;
	//Output::ErrorStr((std::string)str);

	va_end(args);
}

const std::string& LcfReader::GetError() {
	return error_str;
}

std::string LcfReader::Encode(const std::string& str_to_encode) {
#ifdef _WIN32
	return ReaderUtil::Recode(str_to_encode, encoding, "65001");
#else
	return ReaderUtil::Recode(str_to_encode, encoding, "UTF-8");
#endif
}

int LcfReader::IntSize(unsigned int x) {
	int result = 0;
	do {
		x >>= 7;
		result++;
	} while (x != 0);
	return result;
}

#ifdef READER_BIG_ENDIAN
void LcfReader::SwapByteOrder(uint16_t& us)
{
	us =	(us >> 8) |
			(us << 8);
}

void LcfReader::SwapByteOrder(uint32_t& ui)
{
	ui =	(ui >> 24) |
			((ui<<8) & 0x00FF0000) |
			((ui>>8) & 0x0000FF00) |
			(ui << 24);
}

void LcfReader::SwapByteOrder(double& d)
{
	uint32_t *p = reinterpret_cast<uint32_t *>(&d);
	SwapByteOrder(p[0]);
	SwapByteOrder(p[1]);
	uint32_t tmp = p[0];
	p[0] = p[1];
	p[1] = tmp;
}
#else
void LcfReader::SwapByteOrder(uint16_t& /* us */) {}
void LcfReader::SwapByteOrder(uint32_t& /* ui */) {}
void LcfReader::SwapByteOrder(double& /* d */) {}
#endif

void LcfReader::SwapByteOrder(int16_t& s)
{
	SwapByteOrder((uint16_t&) s);
}
