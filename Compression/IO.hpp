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
	static bool ReadFile(const std::string &fileName, std::size_t &out_dataSize, ByteBuffer_t &out_data);
	static bool ReadFile(const std::wstring &fileName, std::size_t &out_dataSize, ByteBuffer_t &out_data);
};


#endif /* IO_HPP */


