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

DWORD Game::isInGm()
{
	DWORD ptPl=NULL;
	switch (this->num)
	{
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
		ReadProcessMemory(GM_HWND, (LPCVOID)this->ptPlBasic, &ptPl, sizeof(DWORD), NULL);
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
	int ptXPos=(ptPl+this->ptPloffs);
	int ptYPos=(ptPl+this->ptPloffs+4);
	GetCursorPos(&mousePos);//获取鼠标坐标
	GetWindowRect(WIND_HWND, &windRect);//获取窗口坐标 
	float relX,relY;
	int finalX, finalY;
	relX = (float)(mousePos.x - windRect.left) / (float)(windRect.right - windRect.left);
	relY = (float)(mousePos.y - windRect.top) / (float)(windRect.bottom - windRect.top);
	if (relX < this->xmin)relX = this->xmin;
	if (relX > this->xmax)relX = this->xmax;
	if (relY < this->ymin)relY = this->ymin;
	if (relY > this->ymax)relY = this->ymax;
	relX = (relX - this->xmin) / xsz;
	relY = (relY - this->ymin) / ysz;
	finalX = (int)(this->StageXMin + relX * StageXSz) * ratio;
	finalY = (int)(this->StageYMin + relY * StageYSz) * ratio;
	WriteProcessMemory(GM_HWND, (LPVOID)ptXPos, &finalX, sizeof(DWORD), NULL);
	WriteProcessMemory(GM_HWND, (LPVOID)ptYPos, &finalY, sizeof(DWORD), NULL);
	return NORMAL_FLAG;
}
