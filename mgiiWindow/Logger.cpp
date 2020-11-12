#include "stdafx.h"
#include "Logger.h"

#include "CriticalSection.h"


using std::string;

#pragma region Constants, Statics, and Globals
class LogMgr;
static LogMgr* s_pLogMgr = NULL;
#pragma endregion

#pragma region LogMgr class
class LogMgr
{
public: 
	enum ErrorDialogResult
	{
		LOGMGR_ERROR_ABORT,
		LOGMGR_ERROR_RETRY,
		LOGMGR_ERROR_IGNORE
	};

	typedef std::map<string, unsigned char> Tags;
	typedef std::list<Logger::ErrorMessenger*> ErrorMessengerList;

	Tags _tags;
	ErrorMessengerList _errorMessengers;

	//thread safety
	CriticalSection _tagCriticalSection;
	CriticalSection _messengerCriticalSection;

public:
	// construction
	LogMgr(void);
	~LogMgr(void);
	void Init(const char* logginConfigFilename);

	// logs
	void SetDisplayFlags(const std::string& tag, unsigned char flags);
};
#pragma endregion


#pragma region LogMgr class definition
LogMgr::LogMgr(void)
{

}

LogMgr::~LogMgr(void)
{

}

void LogMgr::Init(const char* loggingConfigFilename)
{
	if (loggingConfigFilename)
	{
		std::ifstream ifs(loggingConfigFilename, std::ios::in);
		if (ifs.is_open())
		{
			std::string xml_str;
			xml_str.assign(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());

			xml_document<> doc;
			try
			{
				doc.parse<0>((char*)xml_str.c_str());
			}
			catch (...)
			{
				return;
			}

			xml_node<>* pRoot = doc.first_node();

			for (xml_node<>* pNode = pRoot->first_node(); pNode; pNode = pNode->next_sibling())
			{
				unsigned char flags = 0;
				xml_attribute<>* tagAttr = pNode->first_attribute("tag");
				std::string tag = tagAttr->value();

				uint32_t debugger = 0;
				xml_attribute<>* debuggerAttr = pNode->first_attribute("debugger");
				std::string debuggerStr = debuggerAttr->value();
				debugger = static_cast<uint32_t>(std::stoul(debuggerStr));
				if (debugger)
					flags |= LOGFLAG_WRITE_TO_DEBUGGER;

				uint32_t logfile = 0;
				xml_attribute<>* logfileAttr = pNode->first_attribute("file");
				logfile = static_cast<uint32_t>(std::stoul(logfileAttr->value()));
				if (logfile)
					flags |= LOGFLAG_WRITE_TO_LOG_FILE;

				SetDisplayFlags(tag, flags);
			}
		}
	}
}

void LogMgr::SetDisplayFlags(const std::string& tag, unsigned char flags)
{
	_tagCriticalSection.Lock();
	if (flags != 0)
	{
		Tags::iterator findIt = _tags.find(tag);
		if (findIt == _tags.end())
			_tags.insert(std::make_pair(tag, flags));
		else
			findIt->second = flags;
	}
	else
	{
		_tags.erase(tag);
	}
	_tagCriticalSection.Unlock();
}

#pragma endregion

Logger::ErrorMessenger::ErrorMessenger(void)
{

}

void Logger::ErrorMessenger::Show(const std::string& errorMessage, bool isFatal, const char* funcName, const char* sourceFile, unsigned int lineNum)
{

}


#pragma region C Interface
namespace Logger 
{
	void Init(const char* loggingConfigFilename)
	{
		if (!s_pLogMgr)
		{
			s_pLogMgr = GCC_NEW LogMgr;
			s_pLogMgr->Init(loggingConfigFilename);
		}
	}

	void Destroy(void)
	{
		delete s_pLogMgr;
		s_pLogMgr = NULL;
	}

	void Log(const std::string& tag, const std::string& message, const char* funcName, const char* sourceFile, unsigned int lineNum)
	{

	}

	void SetDisplayFlags(const std::string& tag, unsigned char flags)
	{

	}
}
#pragma endregion