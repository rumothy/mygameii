#include "stdafx.h"
#include "GameCode.h"

#include "Logger.h"

using std::string;

Logger::ErrorMessenger::ErrorMessenger(void)
{

}

void Logger::ErrorMessenger::Show(const std::string& errorMessage, bool isFatal, const char* funcName, const char* sourceFile, unsigned int lineNum)
{

}


#pragma region C Interface
namespace Logger 
{
	void Init(const char* loggingConfigFileName)
	{
	}

	void Destroy(void)
	{

	}

	void Log(const std::string& tag, const std::string& message, const char* funcName, const char* sourceFile, unsigned int lineNum)
	{

	}

	void SetDisplayFlags(const std::string& tag, unsigned char flags)
	{

	}
}
#pragma endregion