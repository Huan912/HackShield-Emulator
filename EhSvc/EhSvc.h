#pragma once
#include <Windows.h>

#define HS_ERR_OK 0x00000000

namespace EhSvcHijack
{
#if _WIN64
#define VERSION_CALL_CONVENTION __fastcall
#else
#define VERSION_CALL_CONVENTION __stdcall
#endif

	BOOL VERSION_CALL_CONVENTION AhnHS_ServiceDispatch_(unsigned int code, void* params, unsigned int* result)
	{
		*result = HS_ERR_OK;
		return TRUE;
	}

	void VERSION_CALL_CONVENTION AhnHS_SendHsLog_(DWORD dwError, const char* szUserID, const char* szHShieldPath)
	{
		return;
	}


	int VERSION_CALL_CONVENTION AhnHS_VerifyProtectedFunction_()
	{
		return HS_ERR_OK;
	}


	BOOL VERSION_CALL_CONVENTION AhnHS_QueryPerformanceCounter_(LARGE_INTEGER* lpPerformanceCount)
	{
		return QueryPerformanceCounter(lpPerformanceCount);
	}


	BOOL VERSION_CALL_CONVENTION AhnHS_QueryPerformanceFrequency_(LARGE_INTEGER* lpFrequency)
	{
		return QueryPerformanceFrequency(lpFrequency);
	}


	DWORD VERSION_CALL_CONVENTION AhnHS_GetTickCount_()
	{
		return GetTickCount();
	}

	void Initialize()
	{

	}
}

#pragma comment(linker, "/export:_AhnHS_ServiceDispatch@1=AhnHS_ServiceDispatch_,@10")
#pragma comment(linker, "/export:_AhnHS_SendHsLog@2=AhnHS_SendHsLog_,@26")
#pragma comment(linker, "/export:_AhnHS_VerifyProtectedFunction@3=AhnHS_VerifyProtectedFunction_,@27")
#pragma comment(linker, "/export:_AhnHS_QueryPerformanceCounter@4=AhnHS_QueryPerformanceCounter_,@28")
#pragma comment(linker, "/export:_AhnHS_QueryPerformanceFrequency@5=AhnHS_QueryPerformanceFrequency_,@29")
#pragma comment(linker, "/export:_AhnHS_GetTickCount@6=AhnHS_GetTickCount_,@30")