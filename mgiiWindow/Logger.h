#pragma once
const unsigned char LOGFLAG_WRITE_TO_LOG_FILE = 1 << 0;
const unsigned char LOGFLAG_WRITE_TO_DEBUGGER = 1 << 1;

namespace Logger
{
	class ErrorMessenger
	{
		bool _enabled;
	public:
		ErrorMessenger(void);
		void Show(const std::string& errorMessage, bool isFatal, const char* funcName, const char* sourceFile, unsigned int lineNum);
	};

	void Init(const char* loggingConfigFilename);
	void Destroy(void);

	void Log(const std::string& tag, const std::string& message, const char* funcName, const char* sourceFile, unsigned int lineNum);
	void SetDisplayFlags(const std::string& tag, unsigned char flags);
}

#define GCC_FATAL(str) \
	do \
	{ \
		static Logger::ErrorMessenger* pErrorMessenger = GCC_NEW Logger::ErrorMessenger; \
		std::string s((str)); \
		pErrorMessenger->Show(s, true, __FUNCTION__, __FILE__, __LINE__); \
	} \
	while (0) \