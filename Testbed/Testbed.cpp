// Testbed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Compression/FileCompress.hpp"

void PrintUsage(const std::wstring &execName);

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 4) {
		std::wstring execName(L"testbed.exe");
		if (argc > 0) {
            if (argv[0] != NULL) {
                std::wstring fullPath(argv[0]);
				execName = fullPath.substr(fullPath.rfind(L"\\") + 1);
            }
        }
		PrintUsage(execName);
		std::cout << "Press Enter to continue...";
		std::cin.ignore();
		return EXIT_FAILURE;
	}

	using namespace Compression;

	std::wstring originalFile(argv[1]);
	std::wstring compressedFile(argv[2]);
	std::wstring uncompressedFile(argv[3]);

	FileCompress fileCompress;
	fileCompress.Initialize();
	std::wstring err;

	if (fileCompress.Compress(originalFile, compressedFile, err)) {
		if (fileCompress.Decompress(compressedFile, uncompressedFile, err)) {
			std::wcout << std::endl;
			std::wcout << err;
			std::wcout << std::endl;
			std::wcout << L"Done!";
			std::wcout << std::endl;
			std::wcout << L"Press Enter to continue...";
			std::cin.ignore();
		} else {
			std::wcout << std::endl;
			std::wcout << err;
			std::wcout << std::endl;
			std::wcout << L"Press Enter to continue...";
			std::cin.ignore();
			return EXIT_FAILURE;
		}
	} else {
		std::wcout << std::endl;
		std::wcout << err;
		std::wcout << std::endl;
		std::wcout << L"Press Enter to continue...";
		std::cin.ignore();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void PrintUsage(const std::wstring &execName)
{
	std::wcout << std::endl << std::endl;
	std::wcout << execName << L" <Original File> <Compressed File> <Uncompressed File>" << std::endl;
	std::wcout << std::endl << std::endl;
}

