#pragma once


struct GameOptions
{
	GameOptions();
	~GameOptions() {};
	void Init(const char* xmlFilePath);

	xml_document<>* m_pDoc;
};