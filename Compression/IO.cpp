#include "stdafx.h"
#include <fstream>
#include <ios>
#include "IO.hpp"
#include "Utils.hpp"

using namespace std;
using namespace Compression;

bool IO::ReadFile(const std::string &fileName, std::size_t &out_dataSize, ByteBuffer_t &out_data)
{
	return ReadFile(Utils::StrToWStr(fileName), out_dataSize, out_data);
}

bool IO::ReadFile(const std::wstring &fileName, std::size_t &out_dataSize, ByteBuffer_t &out_data)
{
	out_data = NULL;

	std::ifstream file(fileName, ios::binary | ios::ate);
    if (file.is_open()) {
        size_t size = static_cast<size_t>(file.tellg());
		Byte_t *buffer = new Byte_t[size];
		file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

		out_dataSize = size;
		out_data = buffer;

		return true;
    }

	return false;
}

