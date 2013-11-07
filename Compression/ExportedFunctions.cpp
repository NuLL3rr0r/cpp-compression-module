#include "stdafx.h"
#include <string>
#include <cstring>
#include "ExportedFunctions.hpp"
#include "FileCompress.hpp"
#include "Utils.hpp"

#define		NOT_INITIALIZED_ERROR		    L"Not initialized yet!\0"

using namespace Compression;

C_BOOL isFileCompressInitialized = false;
FileCompress fileCompressObject;

extern "C"
{
	C_DLLEXPORT	void Initialize()
	{
		fileCompressObject.Initialize();
		isFileCompressInitialized = true;
	}

    C_DLLEXPORT C_BOOL CompressMultiByte(const char *originalFile, const char *compressedFile)
	{
		if (!isFileCompressInitialized)
			return false;

		return fileCompressObject.Compress(originalFile, compressedFile);
	}

    C_DLLEXPORT C_BOOL CompressMultiByteErr(const char *originalFile, const char *compressedFile, char *out_error)
	{
		if (!isFileCompressInitialized) {
			std::string err(Utils::WStrToStr(NOT_INITIALIZED_ERROR));
			size_t len = strlen(err.c_str());
			out_error = new char[len];
			strcpy_s(out_error, len, err.c_str());
			return false;
		}

		std::string error;
		C_BOOL rc = fileCompressObject.Compress(originalFile, compressedFile, error);

		size_t len = error.length() + 1;
		out_error = new char[len];
		strcpy_s(out_error, len, error.c_str());

		return rc;
	}

    C_DLLEXPORT C_BOOL DecompressMultiByte(const char *compressedFile, const char *uncompressedFile)
	{
		if (!isFileCompressInitialized)
			return false;

		return fileCompressObject.Decompress(compressedFile, uncompressedFile);
	}

    C_DLLEXPORT C_BOOL DecompressMultiByteErr(const char *compressedFile, const char *uncompressedFile, char *out_error)
	{
		if (!isFileCompressInitialized) {
			std::string err(Utils::WStrToStr(NOT_INITIALIZED_ERROR));
			size_t len = strlen(err.c_str());
			out_error = new char[len];
			strcpy_s(out_error, len, err.c_str());
			return false;
		}

		std::string error;
		C_BOOL rc = fileCompressObject.Decompress(compressedFile, uncompressedFile, error);

		size_t len = error.length() + 1;
		out_error = new char[len];
		strcpy_s(out_error, len, error.c_str());

		return rc;
	}

    C_DLLEXPORT C_BOOL CompressWideChar(const wchar_t *originalFile, const wchar_t *compressedFile)
	{
		if (!isFileCompressInitialized)
			return false;

		return fileCompressObject.Compress(originalFile, compressedFile);
	}

    C_DLLEXPORT C_BOOL CompressWideCharErr(const wchar_t *originalFile, const wchar_t *compressedFile, wchar_t *out_error)
	{
		if (!isFileCompressInitialized) {
			size_t len = wcslen(NOT_INITIALIZED_ERROR);
			out_error = new wchar_t[len];
			wcscpy_s(out_error, len, NOT_INITIALIZED_ERROR);
			return false;
		}

		std::wstring error;
		C_BOOL rc = fileCompressObject.Compress(originalFile, compressedFile, error);

		size_t len = error.length() + 1;
		out_error = new wchar_t[len];
		wcscpy_s(out_error, len, error.c_str());

		return rc;
	}

    C_DLLEXPORT C_BOOL DecompressWideChar(const wchar_t *compressedFile, const wchar_t *uncompressedFile)
	{
		if (!isFileCompressInitialized)
			return false;

		return fileCompressObject.Decompress(compressedFile, uncompressedFile);
	}

    C_DLLEXPORT C_BOOL DecompressWideCharErr(const wchar_t *compressedFile, const wchar_t *uncompressedFile, wchar_t *out_error)
	{
		if (!isFileCompressInitialized) {
			size_t len = wcslen(NOT_INITIALIZED_ERROR);
			out_error = new wchar_t[len];
			wcscpy_s(out_error, len, NOT_INITIALIZED_ERROR);
			return false;
		}

		std::wstring error;
		C_BOOL rc = fileCompressObject.Decompress(compressedFile, uncompressedFile, error);

		size_t len = error.length() + 1;
		out_error = new wchar_t[len];
		wcscpy_s(out_error, len, error.c_str());

		return rc;
	}
}

