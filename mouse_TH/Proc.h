#pragma once
BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam);
HWND ReturnWnd(DWORD processID);
int FindProcessPid(const WCHAR * pszProcessName);