#ifndef IO_HPP
#define IO_HPP


#include "stdafx.h"
#include <string>
#include <vector>

namespace Compression {
	class  IO;
}

class Compression::IO
{
public:
	static bool ReadFile(const std::string &fileName, ByteBuffer_t &out_data);
	static bool WriteFile(const std::string &fileName, const ByteBuffer_t &data);

	static bool ReadFile(const std::wstring &fileName, ByteBuffer_t &out_data);
	static bool WriteFile(const std::wstring &fileName, const ByteBuffer_t &data);
};


#endif /* IO_HPP */


