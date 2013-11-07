#include "stdafx.h"
#include <fstream>
#include <ios>
#include "IO.hpp"
#include "Utils.hpp"

using namespace std;
using namespace Compression;

bool IO::ReadFile(const std::string &fileName, ByteBuffer_t &out_data)
{
	return ReadFile(Utils::StrToWStr(fileName), out_data);
}

bool IO::WriteFile(const std::string &fileName, const ByteBuffer_t &data)
{
	return WriteFile(Utils::StrToWStr(fileName), data);
}

bool IO::ReadFile(const std::wstring &fileName, ByteBuffer_t &out_data)
{
	out_data.clear();

	std::ifstream file(fileName, ios::binary | ios::ate);
    if (file.is_open()) {
        size_t size = static_cast<size_t>(file.tellg());
		Byte_t *buffer = new Byte_t[size];
		file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

		out_data.assign(buffer, buffer + size);
		delete buffer;

		return true;
    }

	return false;
}

bool IO::WriteFile(const std::wstring &fileName, const ByteBuffer_t &data)
{
    std::ofstream file(fileName, std::ios::binary | std::ios::trunc);
    if (file.is_open()) {
		file.write(&data[0], data.size());
        file.close();

		return true;
    }

	return false;
}

