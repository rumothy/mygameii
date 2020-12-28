#include "stdafx.h"
#include "Initialization.h"

GameOptions::GameOptions()
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
			xml_attribute<>* rendererAttr = pNode->first_attribute("renderer");
			std::string attribute = rendererAttr->value();
		}

	}

}