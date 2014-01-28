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
#ifdef _WIN32
#  include <cstdio>
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#else
#  include <vector>
#  include <iconv.h>
#  include <boost/type_traits/function_traits.hpp>
#  include <boost/type_traits/remove_pointer.hpp>
#endif

#include <cstdlib>
#include <cstring>
#include <sstream>

#include "inireader.h"
#include "reader_util.h"

namespace ReaderUtil {
}

std::string ReaderUtil::CodepageToIconv(int codepage) {
	if (codepage == 0)
		return "";

	std::ostringstream out;
	out << "CP" << codepage;
	return out.str();
}

std::string ReaderUtil::GetEncoding() {
	INIReader ini("RPG_RT.ini");
	if (ini.ParseError() != -1) {
#if defined(GEKKO) || defined(PSP)
		std::string default_enc = "1252";
#else
		std::string default_enc = "";
#endif
		std::string encoding = ini.Get("EasyRpg", "Encoding", default_enc);

		if (!encoding.empty()) {
#ifdef _WIN32
			int codepage = atoi(encoding.c_str());
			if (codepage > 0) {
				// Looks like a valid codepage
				return encoding.c_str();
			}
#else
			std::string iconv_str = CodepageToIconv(atoi(encoding.c_str()));
			// Check at first if the ini value is a codepage
			if (!iconv_str.empty()) {
				// Looks like a valid codepage
				return iconv_str;
			}
#endif
		}
	}
	return "";
}

#ifndef _WIN32
template<class F>
static std::string RunIconv(const std::string& str_to_encode,
                            const std::string& src_enc,
                            const std::string& dst_enc,
                            F const iconv_func) {
	iconv_t cd = iconv_open(dst_enc.c_str(), src_enc.c_str());
	if (cd == (iconv_t)-1) {
		return "";
	}

	size_t src_left = str_to_encode.size();
	std::vector<char> dst(str_to_encode.size() * 5 + 10);
	size_t dst_left = dst.size();

	typedef typename boost::remove_pointer<
		typename boost::function_traits<
			typename boost::remove_pointer<F>::type
			>::arg2_type
		>::type src_type;
	src_type p = (src_type)str_to_encode.c_str();
	char *q = &dst.front();

	size_t status = iconv_func(cd, &p, &src_left, &q, &dst_left);
	iconv_close(cd);
	if (status == (size_t) -1 || src_left > 0) {
		return "";
	}
	*q++ = '\0';
	return std::string(&dst.front());
}
#endif // not _WIN32

std::string ReaderUtil::Recode(const std::string& str_to_encode) {
#ifdef _WIN32
	return ReaderUtil::Recode(str_to_encode, GetEncoding(), "65001");
#else
	return ReaderUtil::Recode(str_to_encode, GetEncoding(), "UTF-8");
#endif
}

std::string ReaderUtil::Recode(const std::string& str_to_encode,
                               const std::string& src_enc,
                               const std::string& dst_enc) {
#ifdef _WIN32
	size_t strsize = str_to_encode.size();

	wchar_t* widechar = new wchar_t[strsize * 5 + 1];

	// To UTF-16
	// Default codepage is 0, so we dont need a check here
	int res = MultiByteToWideChar(atoi(src_enc.c_str()), 0, str_to_encode.c_str(), strsize, widechar, strsize * 5 + 1);
	if (res == 0) {
		// Invalid codepage
		delete [] widechar;
		return str_to_encode;
	}
	widechar[res] = '\0';

	// Back to UTF-8...
	char* utf8char = new char[strsize * 5 + 1];
	res = WideCharToMultiByte(atoi(dst_enc.c_str()), 0, widechar, res, utf8char, strsize * 5 + 1, NULL, NULL);
	utf8char[res] = '\0';

	// Result in str
	std::string str = std::string(utf8char, res);

	delete [] widechar;
	delete [] utf8char;

	return str;
#else
	return RunIconv(str_to_encode, src_enc, dst_enc, &::iconv);
#endif
}

