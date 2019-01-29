#include "pch.h"
#include "Proc.h"

typedef struct EnumFunArg
{
	HWND      hWnd;
	DWORD    dwProcessId;
}EnumFunArg, *LPEnumFunArg;
BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{

	EnumFunArg  *pArg = (LPEnumFunArg)lParam;
	DWORD  processId;
	GetWindowThreadProcessId(hwnd, &processId);
	if (processId == pArg->dwProcessId)
	{
		pArg->hWnd = hwnd;
		return FALSE;
	}
	return TRUE;
}
HWND ReturnWnd(DWORD processID)
{
	HWND retWnd = NULL;
	EnumFunArg wi;
	wi.dwProcessId = processID;
	wi.hWnd = NULL;
	EnumWindows(lpEnumFunc, (LPARAM)&wi);
	if (wi.hWnd) {
		retWnd = wi.hWnd;
	}   return retWnd;
}

int FindProcessPid(const WCHAR * pszProcessName)
{
	DWORD id = 0;
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pInfo;
	pInfo.dwSize = sizeof(pInfo);

	Process32First(hSnapShot, &pInfo);
	do
	{
		if (_tcscmp(_tcsdup(pInfo.szExeFile), pszProcessName) == 0)
		{
			id = pInfo.th32ProcessID;
			break;
		}
	} while (Process32Next(hSnapShot, &pInfo) != FALSE);
	return id;
}