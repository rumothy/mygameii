//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently.

#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers.
#endif

#include <windows.h>
#include <list>
#include <map>

class GCC_noncopyable
{
private:
	GCC_noncopyable(const GCC_noncopyable& x);
	//GCC_noncopyable& operator=(const GCC_noncopyable& x);
public:
	GCC_noncopyable() {};
};


#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

#include <string>
#include <wrl.h>
#include <shellapi.h>


#if defined(_DEBUG)
#	define GCC_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#	define GCC_NEW new
#endif


#include "rapidxml.hpp"
#include <iostream>
#include <fstream>

#include "Logger.h"

using namespace rapidxml;







// stdafx.cpp == GameCodeStd.cpp
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;