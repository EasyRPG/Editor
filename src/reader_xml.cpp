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
#include <sstream>
#include <cstdarg>
#include <cstdio>
#include "reader_lcf.h"
#include "reader_xml.h"

// Expat callbacks
#if defined(READER_SUPPORT_XML)
extern "C" {
static void StartElementHandler(void* closure, const XML_Char* name, const XML_Char** atts) {
	((XmlReader*) closure)->StartElement(name, atts);
}

static void EndElementHandler(void* closure, const XML_Char* name) {
	((XmlReader*) closure)->EndElement(name);
}

static void CharacterDataHandler(void* closure, const XML_Char* s, int len) {
	((XmlReader*) closure)->CharacterData(s, len);
}
}
#endif

XmlReader::XmlReader(const std::string& filename) :
	filename(filename),
	stream(NULL),
	parser(NULL)
{
	Open();
}

XmlReader::~XmlReader() {
	Close();
}

void XmlReader::Open() {
#if defined(READER_SUPPORT_XML)
	stream = fopen(filename.c_str(), "r");
	parser = XML_ParserCreate("UTF-8");

	XML_SetUserData(parser, (void*) this);
	XML_SetElementHandler(parser, StartElementHandler, EndElementHandler);
	XML_SetCharacterDataHandler(parser, CharacterDataHandler);

	handlers.push_back(NULL);
#endif
}

void XmlReader::Close() {
#if defined(READER_SUPPORT_XML)
	if (stream != NULL)
		fclose(stream);
	stream = NULL;

	if (parser != NULL)
		XML_ParserFree(parser);
	parser = NULL;
#endif
}

bool XmlReader::IsOk() const {
	return (stream != NULL && !ferror(stream) && parser != NULL);
}

void XmlReader::Error(const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	fputc('\n', stderr);
	va_end(ap);
}

void XmlReader::Parse() {
#if defined(READER_SUPPORT_XML)
	static const int bufsize = 4096;
	while (IsOk() && !feof(stream)) {
		void* buffer = XML_GetBuffer(parser, bufsize);
		int len = fread(buffer, 1, bufsize, stream);
		int result = XML_ParseBuffer(parser, len, len <= 0);
		if (result == 0)
			Error("%s", XML_ErrorString(XML_GetErrorCode(parser)));
	}
#endif
}

/**
 * Change the handler
 */
void XmlReader::SetHandler(XmlHandler* handler) {
	handlers.back() = handler;
}

/**
 * Start Element
 */
void XmlReader::StartElement(const char* name, const char** atts) {
	XmlHandler* handler = handlers.back();
	handlers.push_back(handler);
	handlers.back()->StartElement(*this, name, atts);
	buffer.clear();
}

/**
 * Character Data
 */
void XmlReader::CharacterData(const char* s, int len) {
	buffer.append(s, len);
}

/**
 * End Element
 */
void XmlReader::EndElement(const char* name) {
	XmlHandler* handler = handlers.back();
	handler->CharacterData(*this, buffer);
	handlers.pop_back();
	if (handler != handlers.back())
		delete handler;
	handlers.back()->EndElement(*this, name);
}

// Primitive type readers

template <>
void XmlReader::Read<bool>(bool& val, const std::string& data) {
	std::istringstream s(data);
	std::string str;
	s >> str;
	val = str == "T";
}

template <>
void XmlReader::Read<int>(int& val, const std::string& data) {
	std::istringstream s(data);
	s >> val;
}

template <>
void XmlReader::Read<uint8_t>(uint8_t& val, const std::string& data) {
	std::istringstream s(data);
	int x;
	s >> x;
	val = x;
}

template <>
void XmlReader::Read<int16_t>(int16_t& val, const std::string& data) {
	std::istringstream s(data);
	s >> val;
}

template <>
void XmlReader::Read<uint32_t>(uint32_t& val, const std::string& data) {
	std::istringstream s(data);
	s >> val;
}

template <>
void XmlReader::Read<double>(double& val, const std::string& data) {
	std::istringstream s(data);
	s >> val;
}

template <>
void XmlReader::Read<std::string>(std::string& val, const std::string& data) {
	static const std::string prefix("\xee\x80");

	if (data.find(prefix) == std::string::npos) {
		val = data;
		return;
	}

	// XML doesn't allow most C0 control codes, so they're re-mapped
	// to the private-use area at U+E000. The following code restores
	// re-mapped codes to their original value.

	val.clear();

	for (size_t pos = 0; ; ) {
		size_t next = data.find(prefix, pos);
		if (next > pos)
			val.append(data, pos, next - pos);
		if (next == std::string::npos)
			return;
		pos = next + 2;
		val.append(1, data[pos] - '\x80');
		pos++;
	}
}

template <class T>
void XmlReader::ReadVector(std::vector<T>& val, const std::string& data) {
	val.clear();
	std::istringstream s(data);
	for (;;) {
		std::string str;
		s >> str;
		if (!s.fail()) {
			T x;
			XmlReader::Read<T>(x, str);
			val.push_back(x);
		}
		if (!s.good())
			break;
	}
}

template <>
void XmlReader::Read<std::vector<int> >(std::vector<int>& val, const std::string& data) {
	ReadVector<int>(val, data);
}

template <>
void XmlReader::Read<std::vector<bool> >(std::vector<bool>& val, const std::string& data) {
	ReadVector<bool>(val, data);
}

template <>
void XmlReader::Read<std::vector<uint8_t> >(std::vector<uint8_t>& val, const std::string& data) {
	ReadVector<uint8_t>(val, data);
}

template <>
void XmlReader::Read<std::vector<int16_t> >(std::vector<int16_t>& val, const std::string& data) {
	ReadVector<int16_t>(val, data);
}

template <>
void XmlReader::Read<std::vector<uint32_t> >(std::vector<uint32_t>& val, const std::string& data) {
	ReadVector<uint32_t>(val, data);
}

template <>
void XmlReader::Read<std::vector<double> >(std::vector<double>& val, const std::string& data) {
	ReadVector<double>(val, data);
}

