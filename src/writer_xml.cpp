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
#include <vector>
#include "writer_xml.h"

XmlWriter::XmlWriter(const char* filename) :
	filename(filename),
	indent(0),
	at_bol(true)
{
	Open();
}

XmlWriter::XmlWriter(const std::string& filename) :
	filename(filename),
	indent(0),
	at_bol(true)
{
	Open();
}

XmlWriter::~XmlWriter() {
	Close();
}

void XmlWriter::Open() {
	stream = fopen(filename.c_str(), "w");
	fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", stream);
}

void XmlWriter::Close() {
	if (stream != NULL)
		fclose(stream);
	stream = NULL;
}

template <>
void XmlWriter::Write<bool>(const bool& val) {
	Indent();
	fputs(val ? "T" : "F", stream);
}

template <>
void XmlWriter::Write<int>(const int& val) {
	Indent();
	fprintf(stream, "%d", val);
}

template <>
void XmlWriter::Write<uint8_t>(const uint8_t& val) {
	WriteInt((int) val);
}

template <>
void XmlWriter::Write<int16_t>(const int16_t& val) {
	WriteInt((int) val);
}

template <>
void XmlWriter::Write<uint32_t>(const uint32_t& val) {
	Indent();
	fprintf(stream, "%u", val);
}

template <>
void XmlWriter::Write<double>(const double& val) {
	Indent();
	fprintf(stream, "%g", val);
}

template <>
void XmlWriter::Write<std::string>(const std::string& val) {
	Indent();
	std::string::const_iterator it;
	for (it = val.begin(); it != val.end(); it++) {
		int c = (int) *it;
		switch (c) {
			case '<':
				fputs("&lt;", stream);
				break;
			case '>':
				fputs("&gt;", stream);
				break;
			case '&':
				fputs("&amp;", stream);
				break;
			case '\n':
				fputc(c, stream);
				at_bol = true;
				Indent();
			case '\r':
			case '\t':
				fputc(c, stream);
				break;
			default:
				if (c >= 0 && c < 32)
					fprintf(stream, "&#x%04x;", 0xE000 + c);
				else
					fputc(c, stream);
				break;
		}
	}
}

template <>
void XmlWriter::Write<std::vector<int> >(const std::vector<int>& val) {
	WriteVector<int>(val);
}

template <>
void XmlWriter::Write<std::vector<bool> >(const std::vector<bool>& val) {
	WriteVector<bool>(val);
}

template <>
void XmlWriter::Write<std::vector<uint8_t> >(const std::vector<uint8_t>& val) {
	WriteVector<uint8_t>(val);
}

template <>
void XmlWriter::Write<std::vector<int16_t> >(const std::vector<int16_t>& val) {
	WriteVector<int16_t>(val);
}

template <>
void XmlWriter::Write<std::vector<uint32_t> >(const std::vector<uint32_t>& val) {
	WriteVector<uint32_t>(val);
}

template <>
void XmlWriter::Write<std::vector<double> >(const std::vector<double>& val) {
	WriteVector<double>(val);
}

void XmlWriter::WriteInt(int val) {
	Write<int>(val);
}

template <class T>
void XmlWriter::WriteVector(const std::vector<T>& val) {
	Indent();
	typename std::vector<T>::const_iterator it;
	bool first = true;
	for (it = val.begin(); it != val.end(); it++) {
		if (!first)
			fputc(' ', stream);
		first = false;
		Write<T>(*it);
	}
}

template <class T>
void XmlWriter::WriteNode(const std::string& name, const T& val) {
	BeginElement(name);
	Write<T>(val);
	EndElement(name);
}

void XmlWriter::BeginElement(const std::string& name) {
	NewLine();
	Indent();
	fprintf(stream, "<%s>", name.c_str());
	indent++;
}

void XmlWriter::BeginElement(const std::string& name, int ID) {
	NewLine();
	Indent();
	fprintf(stream, "<%s id=\"%04d\">", name.c_str(), ID);
	indent++;
}

void XmlWriter::EndElement(const std::string& name) {
	indent--;
	Indent();
	fprintf(stream, "</%s>", name.c_str());
	NewLine();
}

void XmlWriter::NewLine() {
	if (at_bol)
		return;
	fputc('\n', stream);
	at_bol = true;
}

void XmlWriter::Indent() {
	if (!at_bol)
		return;
	for (int i = 0; i < indent; i++)
		fputc(' ', stream);
	at_bol = false;
}

bool XmlWriter::IsOk() const {
	return (stream != NULL && !ferror(stream));
}

template void XmlWriter::WriteNode<int>(const std::string& name, const int& val);
template void XmlWriter::WriteNode<bool>(const std::string& name, const bool& val);
template void XmlWriter::WriteNode<uint8_t>(const std::string& name, const uint8_t& val);
template void XmlWriter::WriteNode<int16_t>(const std::string& name, const int16_t& val);
template void XmlWriter::WriteNode<uint32_t>(const std::string& name, const uint32_t& val);
template void XmlWriter::WriteNode<double>(const std::string& name, const double& val);
template void XmlWriter::WriteNode<std::string>(const std::string& name, const std::string& val);

template void XmlWriter::WriteNode<std::vector<int> >(const std::string& name, const std::vector<int>& val);
template void XmlWriter::WriteNode<std::vector<bool> >(const std::string& name, const std::vector<bool>& val);
template void XmlWriter::WriteNode<std::vector<uint8_t> >(const std::string& name, const std::vector<uint8_t>& val);
template void XmlWriter::WriteNode<std::vector<int16_t> >(const std::string& name, const std::vector<int16_t>& val);
template void XmlWriter::WriteNode<std::vector<uint32_t> >(const std::string& name, const std::vector<uint32_t>& val);
