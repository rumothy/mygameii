#pragma once
#include "Initialization.h"

class GameCodeApp
{

public:
	GameCodeApp();

	virtual bool InitInstance(HINSTANCE hInstance, LPWSTR lpCmdLine, HWND hWnd = NULL, 
		int screenWidth = SCREEN_WIDTH, int screenHeight = SCREEN_HEIGHT);
	struct GameOptions m_Options;

};


extern GameCodeApp* g_pApp;