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

#ifndef _EASYRPG_READER_UTIL_H_
#define _EASYRPG_READER_UTIL_H_

// Headers
#include <string>

/**
 * ReaderUtil namespace.
 */
namespace ReaderUtil {
	/**
	 * Returns the iconv name of a windows codepage.
	 *
	 * @param codepage codepage to lookup.
	 * @return name used by iconv or NULL if not found.
	 */
	std::string CodepageToIconv(int codepage);
	
	/**
	 * Returns the encoding set in the ini file.
	 *
	 * @return Windows: codepage, other: iconv name,
	 *         empty string if not found.
	 */
	std::string GetEncoding();

	/**
	 * Converts a string to unicode.
	 * src encoding is read from the ini file.
	 *
	 * @param str_to_encode string to encode
	 * @return the recoded string.
	 */
	std::string Recode(const std::string& str_to_encode);

	/**
	 * Converts a string between encodings.
	 *
	 * @param str_to_encode the string to convert.
	 * @param src_enc the source encoding.
	 * @param dst_enc the destination encoding.
	 * @return the recoded string.
	 */
	std::string Recode(const std::string& str_to_encode,
					   const std::string& src_enc,
					   const std::string& dst_enc);
}

#endif
