#include "stdafx.h"
#include "GameCode.h"

GameCodeApp *g_pApp = NULL;

GameCodeApp::GameCodeApp()
{
	g_pApp = this;
}

bool GameCodeApp::InitInstance(HINSTANCE hInstance, LPWSTR lpCmdLine, HWND hWnd, int screenWidth, int screenHeight)
{
	// Check for existing instance of the same window
	//
#ifndef _DEBUG
	// Note - it can be really useful to debug network code to have
	// more thatn one instance of the game up at one time - so 
	// fell free to dcomment these lines in or out as  you wish!
	if (!IsOnlyInstance(VGetGameTitle()))
		return false;
#endif
	// We don't need a mouse cursor by default, let the game turn it on
	SetCursor(NULL);
	return TRUE;
}