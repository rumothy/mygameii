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

#include "stdafx.h"
#include "GameCode.h"
#include "D3D12mgiiWindow.h"



using namespace std;

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
    int tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpDbgFlag);

    Logger::Init("C:\\dev\\game\\mygameii\\mgiiWindow\\bin\\x64\\Debug\\Logging.xml");

    // TEST: this does not belong here - just testing for now...
    GameCodeApp();
    //
    
    g_pApp->m_Options.Init("C:\\dev\\game\\mygameii\\mgiiWindow\\bin\\x64\\Debug\\PlayerOptions.xml");

    D3D12mgiiWindow sample(1280, 720, L"D3D12 Hello Window");

    Logger::Destroy();
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}

