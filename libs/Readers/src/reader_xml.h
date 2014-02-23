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

#ifndef EASYRPG_READER_XML_H
#define EASYRPG_READER_XML_H

// Headers
#include <string>
#include <vector>
#include <cstdio>
#if defined(READER_SUPPORT_XML)
#  include <expat.h>
#endif
#include "reader_types.h"
#include "reader_options.h"
#include "reader_util.h"

/**
 * XmlHandler abstract base class (forward reference).
 */
class XmlHandler;

/**
 * XmlReader class template.
 */
class XmlReader {

public:
	/**
	 * Constructs a new File Reader.
	 *
	 * @param filename file to open.
	 */
	XmlReader(const std::string& filename);

	/**
	 * Destructor. Closes the opened file.
	 */
	~XmlReader();

	/*
	 * Opens the file.
	 */
	void Open();

	/**
	 * Closes the opened file.
	 */
	void Close();

	/**
	 * Checks if the file is readable and if no error occured.
	 *
	 * @return true if the stream is okay.
	 */
	bool IsOk() const;

	/**
	 * Reports a parsing error.
	 */
	void Error(const char* fmt, ...);

	/**
	 * Parses the XML file.
	 */
	void Parse();

	/**
	 * Changes the handler.
	 */
	void SetHandler(XmlHandler* handler);

	/**
	 * Parses a primitive type.
	 */
	template <class T>
	static void Read(T& ref, const std::string& data);

	/**
	 * Parses a vector of primitive type.
	 */
	template <class T>
	static void ReadVector(std::vector<T>& ref, const std::string& data);

	/*
	 * Callbacks
	 */
	void StartElement(const char* name, const char** atts);
	void CharacterData(const char* s, int len);
	void EndElement(const char* name);

protected:
	/** Name of the file that is associated with the stream. */
	std::string filename;
	/** File-stream managed by this Reader. */
	FILE* stream;
	/** Expat XML parser object. */
#if defined(READER_SUPPORT_XML)
	XML_Parser parser;
#else
	void* parser;
#endif
	/** Nesting depth. */
	int nesting;
	/** Handler stack. */
	std::vector<XmlHandler*> handlers;
	/** Text buffer. */
	std::string buffer;

};

/**
 * XmlHandler abstract base class.
 */
class XmlHandler {

public:
	virtual void StartElement(XmlReader& /* reader */, const char* /* name */, const char** /* atts */) {}
	virtual void CharacterData(XmlReader& /* reader */, const std::string& /* data */) {}
	virtual void EndElement(XmlReader& /* reader */, const char* /* name */) {}
	XmlHandler() {}
	virtual ~XmlHandler() {}

};

#endif
