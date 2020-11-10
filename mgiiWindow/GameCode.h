#pragma once
#include <string>


#if defined(_DEBUG)
#	define GCC_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#	define GCC_NEW new
#endif
