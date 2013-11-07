#ifndef UTILS_HPP
#define UTILS_HPP


#include <string>

namespace Compression {
	class Utils;
}

class Compression::Utils
{
public:
	static std::wstring StrToWStr(const std::string &str);
	static std::string WStrToStr(const std::wstring &wstr);
};


#endif /* UTILS_HPP */


