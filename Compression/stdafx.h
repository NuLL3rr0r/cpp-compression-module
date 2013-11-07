// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <vector>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#define		C_DLLEXPORT		__declspec(dllexport)
#define		C_BOOL			unsigned __int32
#define		C_INT			__int32

typedef		char					Byte_t;
typedef		std::vector<Byte_t>		ByteBuffer_t;


// TODO: reference additional headers your program requires here
