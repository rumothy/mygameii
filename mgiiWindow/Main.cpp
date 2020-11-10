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

#include "GameCode.h"
#include "stdafx.h"
#include "D3D12mgiiWindow.h"
#include "rapidxml.hpp"

#include <iostream>
#include <fstream>
#include "Logger.h"

using namespace rapidxml;
using namespace std;

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    int tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpDbgFlag);

    
    //char* xml = new char[256];
    //cout << xml << "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>"; 
    //xml_document<> doc;
    ////       <  a  >  <  /  a  >
    //// dec: 60 97 62 60 47 97 62
    //// hex: 3c 61 3e 3c 2f 61 3e
    //char* text = "<a></a>";
    //doc.parse<0>(text);

    Logger::Init("logging.xml");

    std::ifstream ifs("C:\\dev\\game\\mygameii\\mgiiWindow\\bin\\x64\\Debug\\file.xml", std::ios::in);
    if (!ifs.is_open()) {
        return false;
    }

    std::string xml_str;
    xml_str.assign(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());

    xml_document<> doc;
    try {
        doc.parse<0>((char*)xml_str.c_str());
    }
    catch (...) {
        return false;
    }

    xml_node<>* cfg = doc.first_node("a");
    std::string str = cfg->value();

    D3D12mgiiWindow sample(1280, 720, L"D3D12 Hello Window");
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}

