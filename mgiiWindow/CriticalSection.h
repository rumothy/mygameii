#pragma once
#include <Windows.h>

class CriticalSection : public GCC_noncopyable
{
public:
	CriticalSection()
	{
		InitializeCriticalSection(&_cs);
	}

	~CriticalSection()
	{
		DeleteCriticalSection(&_cs);
	}

	void Lock()
	{
		EnterCriticalSection(&_cs);
	}

	void Unlock()
	{
		LeaveCriticalSection(&_cs);
	}

protected:
	mutable CRITICAL_SECTION _cs;
};