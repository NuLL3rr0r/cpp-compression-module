#ifndef EXPORTEDFUNCTIONS_HPP
#define EXPORTEDFUNCTIONS_HPP


#include "stdafx.h"
#include "FileCompress.hpp"

extern "C"
{
	C_DLLEXPORT	void Initialize();

    C_DLLEXPORT C_BOOL CompressMultiByte(const char *originalFile, const char *compressedFile);
    C_DLLEXPORT C_BOOL CompressMultiByteErr(const char *originalFile, const char *compressedFile, char *out_error);
    C_DLLEXPORT C_BOOL DecompressMultiByte(const char *compressedFile, const char *uncompressedFile);
    C_DLLEXPORT C_BOOL DecompressMultiByteErr(const char *compressedFile, const char *uncompressedFile, char *out_error);

    C_DLLEXPORT C_BOOL CompressWideChar(const wchar_t *originalFile, const wchar_t *compressedFile);
    C_DLLEXPORT C_BOOL CompressWideCharErr(const wchar_t *originalFile, const wchar_t *compressedFile, wchar_t *out_error);
    C_DLLEXPORT C_BOOL DecompressWideChar(const wchar_t *compressedFile, const wchar_t *uncompressedFile);
    C_DLLEXPORT C_BOOL DecompressWideCharErr(const wchar_t *compressedFile, const wchar_t *uncompressedFile, wchar_t *out_error);
}


#endif /* EXPORTEDFUNCTIONS_HPP */


