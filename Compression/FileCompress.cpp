#include "stdafx.h"
#include <fstream>
#include <ios>
#include <stdexcept>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include "FileCompress.hpp"
#include "IO.hpp"
#include "Utils.hpp"

#define     UNKNOWN_ERROR				    L"Compression::FileCompress, Unknown error!"
#define     NOT_INITIALIZED_ERROR		    L"Compression::FileCompress, Not initialized yet!"
#define     UNKNOWN_IO_ERROR				L"Compression::FileCompress, Unknown IO error!"

using namespace std;
using namespace boost;
using namespace Compression;

FileCompress::FileCompress()
	: m_isInitialized(false)
{
}

FileCompress::~FileCompress()
{
}

void FileCompress::Initialize()
{
	m_isInitialized = true;
}

bool FileCompress::Compress(const std::string &originalFile, const std::string &compressedFile) const
{
	return Compress(Utils::StrToWStr(originalFile), Utils::StrToWStr(compressedFile));
}

bool FileCompress::Compress(const std::string &originalFile, const std::string &compressedFile, std::string &out_error) const
{
	wstring err;
	bool rc = Compress(Utils::StrToWStr(originalFile), Utils::StrToWStr(compressedFile), err);
	out_error.assign(Utils::WStrToStr(err));
	return rc;
}

bool FileCompress::Decompress(const std::string &compressedFile, const std::string &uncompressedFile) const
{
	return Decompress(Utils::StrToWStr(compressedFile), Utils::StrToWStr(uncompressedFile));
}

bool FileCompress::Decompress(const std::string &compressedFile, const std::string &uncompressedFile, std::string &out_error) const
{
	wstring err;
	bool rc = Decompress(Utils::StrToWStr(compressedFile), Utils::StrToWStr(uncompressedFile), err);
	out_error.assign(Utils::WStrToStr(err));
	return rc;
}

bool FileCompress::Compress(const std::wstring &originalFile, const std::wstring &compressedFile) const
{
	wstring err;
	return Compress(originalFile, compressedFile, err);
}

bool FileCompress::Compress(const std::wstring &originalFile, const std::wstring &compressedFile, std::wstring &out_error) const
{
	if (!m_isInitialized) {
		out_error = NOT_INITIALIZED_ERROR;
		return false;
	}

	try {
		out_error.clear();

		size_t bufferSize;
		ByteBuffer_t buffer;

		if (IO::ReadFile(originalFile, bufferSize, buffer)) {
			ofstream file(compressedFile, ios::binary | ios::trunc);
			iostreams::filtering_streambuf<iostreams::output> output;
			output.push(iostreams::zlib_compressor());
			output.push(file);
			iostreams::write(output, buffer, bufferSize);

			return true;
		} else {
	        out_error.assign(UNKNOWN_IO_ERROR);
		}
	}

	catch (std::exception &ex) {
        out_error.assign(Utils::StrToWStr(ex.what()));
    }

    catch (...) {
        out_error.assign(UNKNOWN_ERROR);
    }

	return false;
}

bool FileCompress::Decompress(const std::wstring &compressedFile, const std::wstring &uncompressedFile) const
{
	wstring err;
	return Decompress(compressedFile, uncompressedFile, err);
}

bool FileCompress::Decompress(const std::wstring &compressedFile, const std::wstring &uncompressedFile, std::wstring &out_error) const
{
	if (!m_isInitialized) {
		out_error = NOT_INITIALIZED_ERROR;
		return false;
	}

	try {
		out_error.clear();

		size_t bufferSize;
		ByteBuffer_t buffer;

		if (IO::ReadFile(compressedFile, bufferSize, buffer)) {
			ofstream file(uncompressedFile, ios::binary | ios::trunc);
			iostreams::filtering_streambuf<iostreams::output> output;
			output.push(iostreams::zlib_decompressor());
			output.push(file);
			iostreams::write(output, buffer, bufferSize);
			delete buffer;

			return true;
		} else {
	        out_error.assign(UNKNOWN_IO_ERROR);
		}
	}

	catch (std::exception &ex) {
        out_error.assign(Utils::StrToWStr(ex.what()));
    }

    catch (...) {
        out_error.assign(UNKNOWN_ERROR);
    }

	return false;
}

