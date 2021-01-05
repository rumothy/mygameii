#include "stdafx.h"
#include "Initialization.h"

GameOptions::GameOptions()
{
	m_Renderer = "Direct3D 9";
	m_pDoc = NULL;
	m_ScreenSize = Point(1024, 768);
}

GameOptions::~GameOptions()
{

}

void GameOptions::Init(const char* xmlFileName)
{
	std::ifstream ifs(xmlFileName);
	if (ifs.is_open())
	{
		std::string xml_str;
		xml_str.assign(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
		xml_document<> doc;
		doc.parse<0>((char*)xml_str.c_str());

		xml_node<>* pRoot = doc.first_node();

		
		if (!pRoot)
			return;

		xml_node<>* pNode = NULL;
		pNode = pRoot->first_node("Graphics");

		if (pNode)
		{
			xml_attribute<char>* rendererAttr = pNode->first_attribute("renderer");
			std::string attribute = rendererAttr->value();
			if (attribute != "Direct3D 9" && attribute != "Direct3D 11")
			{
				GCC_ASSERT(0 && "Bad Renderer setting in Graphics options.");
			}
			else
			{
				m_Renderer = attribute;
			}

			if (pNode->first_attribute("width"))
			{
				xml_attribute<char>* widthAttr = pNode->first_attribute("width");
				std::string widthStr = widthAttr->value();
				m_ScreenSize.x = atoi(widthStr.c_str());
			}

			if (pNode->first_attribute("height"))
			{

			}

			if (pNode->first_attribute("runfullspeed"))
			{

			}
		}

	}

}

bool IsOnlyInstance(LPCTSTR gameTitle)
{
	// Find the window. If active, set and return false
	// Only one game instance may have this mutex at a time...

	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);

	// Does anyone else think 'ERROR_SUCCESS' is a bit of an oxymoron?
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd)
		{
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}

	return true;
}