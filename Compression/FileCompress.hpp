#ifndef FILECOMPRESS_HPP
#define FILECOMPRESS_HPP


#include <string>

namespace Compression {
    class FileCompress;
}

class Compression::FileCompress
{
private:
	bool m_isInitialized;

public:
	FileCompress();
	~FileCompress();

public:
	void Initialize();

	bool Compress(const std::string &originalFile, const std::string &compressedFile) const;
	bool Compress(const std::string &originalFile, const std::string &compressedFile, std::string &out_error) const;
	bool Decompress(const std::string &compressedFile, const std::string &uncompressedFile) const;
	bool Decompress(const std::string &compressedFile, const std::string &uncompressedFile, std::string &out_error) const;

	bool Compress(const std::wstring &originalFile, const std::wstring &compressedFile) const;
	bool Compress(const std::wstring &originalFile, const std::wstring &compressedFile, std::wstring &out_error) const;
	bool Decompress(const std::wstring &compressedFile, const std::wstring &uncompressedFile) const;
	bool Decompress(const std::wstring &compressedFile, const std::wstring &uncompressedFile, std::wstring &out_error) const;
};


#endif /* FILECOMPRESS_HPP */


