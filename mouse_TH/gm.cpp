#pragma once
#include "pch.h"
#include "gm.h"
#include "Proc.h"

HANDLE GM_HWND;
int NW_GAME;
int PID;
int ARR_NUM;
HWND WIND_HWND;
Game Game::allGm[40];

void init()
{
	//						版本号	pt自机		offsX坐标	pt游戏速度		xy最大最小值						窗口名
	Game::allGm[0] = Game(-12,		0x004B4514, 0x988,		(float*)0x004B2ED0, 0.065f, 0.125f, 0.635f, 0.93125f, L"th12c.exe");
	Game::allGm[1] = Game(12,		0x004B4514, 0x988,		(float*)0x004B2ED0, 0.065f, 0.125f, 0.635f, 0.93125f, L"th12.exe");

	Game::allGm[2] = Game(-13,		0x004C22C4, 0x5C4,		(float*)0x004C0A28, 0.065f, 0.125f, 0.635f, 0.93125f, L"th13c.exe");
	Game::allGm[3] = Game(13,		0x004C22C4, 0x5C4,		(float*)0x004C0A28, 0.065f, 0.125f, 0.635f, 0.93125f, L"th13.exe");

	Game::allGm[4] = Game(15,		0x004E9BB8, 0x624,		(float*)0x004E73E8, 0.065f, 0.125f, 0.635f, 0.93125f,L"th15.exe");

	Game::allGm[5] = Game(16,		0x004A6EF8, 0x61C,		(float*)0x004A5788, 0.065f, 0.125f, 0.635f, 0.93125f, L"th16.exe");

	Game::allGm[6] = Game(14,		0x004DB67C, 0x5EC,		(float*)0x004D8F58, 0.065f, 0.125f, 0.635f, 0.93125f, L"th14.exe");

	Game::allGm[7] = Game(10,		0x00477834, 0x3CC,		(float*)0x00476F78, 0.065f, 0.125f, 0.635f, 0.93125f, L"th10.exe",100.0f);
	Game::allGm[8] = Game(10,		0x00477834, 0x3CC,		(float*)0x00476F78, 0.065f, 0.125f, 0.635f, 0.93125f, L"th10c.exe",100.0f);

	Game::allGm[9] = Game(8,		0x017D61AC ,0x0,		(float*)0x017CE8E0, 0.065f, 0.085f, 0.635f, 0.93125f, L"th08.exe",				 1.0f, 8.0f,376.0f,16.0f,432.0f);

	Game::allGm[10] = Game(7,		0x004BE408 ,0x0,		(float*)0x00575AC8, 0.065f, 0.085f, 0.635f, 0.93125f, L"th07.exe",				1.0f, 8.0f,376.0f,16.0f,432.0f);

	Game::allGm[11] = Game(6,		0x006CAA68 ,0x0,		(float*)0x006C6EC0, 0.065f, 0.085f,	0.635f, 0.93125f, L"搶曽峠杺嫿.exe",		1.0f, 8.0f,376.0f,16.0f,432.0f);
	Game::allGm[12] = Game(6,		0x006CAA68 ,0x0,		(float*)0x006C6EC0, 0.065f, 0.085f, 0.635f, 0.93125f, L"th06.exe",				1.0f, 8.0f,376.0f,16.0f,432.0f);
	Game::allGm[13] = Game(6,		0x006CAA68 ,0x0,		(float*)0x006C6EC0, 0.065f, 0.085f, 0.635f, 0.93125f, L"東方紅魔郷.exe",		1.0f, 8.0f,376.0f,16.0f,432.0f);
	
	Game::allGm[14] = Game(11,		-1			 ,0x0,		(float*)0x004A7948, 0.065f, 0.125f, 0.635f, 0.93125f, L"th11.exe");
}

void GetGame(HANDLE &gmHwnd, int &GmNum,int& pid,int &ArrNum)
{
	for (int i = 0; i < 40; i++)
	{
		if (Game::allGm[i].num == -1)continue;
		pid=FindProcessPid(Game::allGm[i].wdName);
		if (pid == NULL)continue;
		GmNum = Game::allGm[i].num;
		ArrNum = i;
		break;
	}
	if ((gmHwnd=OpenProcess(PROCESS_ALL_ACCESS, false, pid)) == NULL)
	{
		MessageBox(NULL, L"获取进程句柄失败,请确认有无打开游戏", L"Error", MB_OK);
	}
	WIND_HWND = ReturnWnd(pid);
}
BYTE th11Chg1[12] = { 0xE9,0xD6,0xA6,0x05,0x00,0x90,0x90,0x90,0x90,0x90,0x90,0x90 };
BYTE th11Chg2[28] = { 0x8B,0x35,0x34,0xAE,0x48,0x00,0xA1,0x38,0xAE,0x48,0x00,0x89,0xB5,0x88,0x08,0x00,0x00,0x89,0x85,0x8C,0x08,0x00,0x00,0xE9,0x15,0x59,0xFA,0xFF };

void init2()
{
	switch (NW_GAME)
	{
	case 11:
	{
		DWORD oldProtect, oldProtect2;
		VirtualProtect((LPVOID)0x0043073A, 0x20, PAGE_EXECUTE_READWRITE, &oldProtect);
		WriteProcessMemory(GM_HWND, (LPVOID)0x0043073A, th11Chg1, sizeof(th11Chg1), NULL);
		VirtualProtect((LPVOID)0x0043073A, 0x20, oldProtect, &oldProtect2);

		VirtualProtect((LPVOID)0x0048AE15, 0x20, PAGE_EXECUTE_READWRITE, &oldProtect);
		WriteProcessMemory(GM_HWND, (LPVOID)0x0048AE15, th11Chg2, sizeof(th11Chg2), NULL);
	}
	break;
	default:
		break;
	}
}

DWORD Game::isInGm()
{
	DWORD ptPl=NULL;
	switch (this->num)
	{
	case 10:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
		ReadProcessMemory(GM_HWND, (LPCVOID)this->ptPlBasic, &ptPl, sizeof(DWORD), NULL);
		break;
	case 11:
	case 8:
	case 7:
	case 6:
		ptPl = -1;
		break;
	default:
		ReadProcessMemory(GM_HWND, (LPCVOID)this->ptPlBasic, &ptPl, sizeof(DWORD), NULL);
		break;
	}
	return ptPl;
}

bool Game::isPause()
{
	float spd;
	ReadProcessMemory(GM_HWND, (LPCVOID)this->ptRunSpd, &spd, sizeof(DWORD), NULL);
	if (spd == 0.0f)
		return 1;
	return 0;
}

int Game::MouseControl()
{
	DWORD ptPl = this->isInGm();
	if (ptPl == NULL)
		return NOT_IN_GAME_FLAG;
	if (this->isPause())
		return PAUSE_FLAG;
	RECT windRect;
	POINT mousePos;
	GetCursorPos(&mousePos);//获取鼠标坐标
	GetWindowRect(WIND_HWND, &windRect);//获取窗口坐标 
	float relX,relY;
	relX = (float)(mousePos.x - windRect.left) / (float)(windRect.right - windRect.left);
	relY = (float)(mousePos.y - windRect.top) / (float)(windRect.bottom - windRect.top);
	if (relX < this->xmin)relX = this->xmin;
	if (relX > this->xmax)relX = this->xmax;
	if (relY < this->ymin)relY = this->ymin;
	if (relY > this->ymax)relY = this->ymax;
	relX = (relX - this->xmin) / xsz;
	relY = (relY - this->ymin) / ysz;

	switch (this->num)
	{
	case 11:
	{
		int finalX, finalY;
		finalX = (int)(this->StageXMin + relX * StageXSz) * ratio;
		finalY = (int)(this->StageYMin + relY * StageYSz) * ratio;
		WriteProcessMemory(GM_HWND, (LPVOID)0x0048AE34, &finalX, sizeof(DWORD), NULL);
		WriteProcessMemory(GM_HWND, (LPVOID)0x0048AE38, &finalY, sizeof(DWORD), NULL);
	}
		break;
	case 10:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	{
		int finalX, finalY;
		finalX = (int)(this->StageXMin + relX * StageXSz) * ratio;
		finalY = (int)(this->StageYMin + relY * StageYSz) * ratio;
		WriteProcessMemory(GM_HWND, (LPVOID)(ptPl + this->ptPloffs), &finalX, sizeof(DWORD), NULL);
		WriteProcessMemory(GM_HWND, (LPVOID)(ptPl + this->ptPloffs + 4), &finalY, sizeof(DWORD), NULL);
	}

		break;
	case 8:
	case 7:
	case 6:
	{
		float fFx, fFy;
		fFx = (this->StageXMin + relX * StageXSz);
		fFy = (this->StageYMin + relY * StageYSz);
		WriteProcessMemory(GM_HWND, (LPVOID)this->ptPlBasic, &fFx, sizeof(DWORD), NULL);
		WriteProcessMemory(GM_HWND, (LPVOID)(this->ptPlBasic + 4), &fFy, sizeof(DWORD), NULL);
	}
		break;
	default:
		break;
	}

	return NORMAL_FLAG;
}
