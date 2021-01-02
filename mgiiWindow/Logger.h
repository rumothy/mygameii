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
	while (0)\

#if 1

// Errors are bad and potentially fatal. They are presented as a dialog with Abort, Retry, and Ignore. Abort will 
// break into the debugger, retry will continue the game, and ignore will continue the game and ignore every subsequent
// call to this specific error. They are ignored completely in release mode.
#define GCC_ERROR(str) \
	do \
	{ \
		static Logger::ErrorMessenger* pErrorMessenger = GCC_NEW Logger::ErrorMessenger; \
		std::string s((str)); \
		pErrorMessenger->Show(s, false, __FUNCTION__, __FILE__, __LINE__); \
	} \
	while (0)\

// This macro replaces GCC_ASSERT().
//#define GCC_ASSERT(expr) \
//	do \
//	{ \
//		if (!expr)) \
//		{ \ 
//			static Logger::ErrorMessenger* pErrorMessenger = GCC_NEW Logger::ErrorMessenger; \
//			pErrorMessenger->Show(#expr, false, __FUNCTION__, __FILE__, __LINE__); \
//		} \
//	} \
//	while (0) \

#define GCC_ASSERT(expr) \
	do \
	{ \
		if (!(expr)) \
		{ \
			static Logger::ErrorMessenger* pErrorMessenger = GCC_NEW Logger::ErrorMessenger; \
			pErrorMessenger->Show(#expr, false, __FUNCTION__, __FILE__, __LINE__); \
		} \
	} \
	while (0) \

#else // NDEBUG is defined

// These are the release mode definitions for the macros above. They defined in such a way as to be
// ignored completely by the compiler. 
#define GCC_ERROR(str) do { (void)sizeof(str); } while(0)
#define GCC_WARNING(str) do { (void)sizeof(str); } while(0)
#define GCC_INFO(str) do { (void)sizeof(str); } while(0)
#define GCC_LOG(tag, str) do { (void)sizeof(tag); (void)sizeof(str); } while(0)
#define GCC_ASSERT(expr) 
do 
{ 
	(void)sizeof(expr); 
} while(0)

#endif