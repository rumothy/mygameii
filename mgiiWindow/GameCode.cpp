#include "stdafx.h"
#include "GameCode.h"

GameCodeApp *g_pApp = NULL;

GameCodeApp::GameCodeApp()
{
	g_pApp = this;
}

bool GameCodeApp::InitInstance(HINSTANCE hInstance, LPWSTR lpCmdLine, HWND hWnd, int screenWidth, int screenHeight)
{
	return TRUE;
}