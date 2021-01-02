#pragma once

class Point
{
public: 
	long x, y;
	
	// construction
	Point(void) { x = y = 0; }
	Point(const long newX, const long newY) { x = newX; y = newY; }
};

struct GameOptions
{
	GameOptions();
	~GameOptions();
	void Init(const char* xmlFilePath);

	xml_document<>* m_pDoc;

	std::string m_Renderer;
	Point m_ScreenSize;
};
