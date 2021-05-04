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
int NORMAL_MOUSE_SPEED;
int SLOW_MOUSE_SPEED;
void init()
{
	bool i= SystemParametersInfo(SPI_GETMOUSESPEED, 0, &NORMAL_MOUSE_SPEED, SPIF_SENDCHANGE);
	if (!i)
	{
		NORMAL_MOUSE_SPEED = -1;
	}
	SLOW_MOUSE_SPEED =(int)floor(((float)NORMAL_MOUSE_SPEED*0.4f)+0.5f);//四舍五入
	//存储默认鼠标速度
	//						版本号	pt自机		offsX坐标	pt游戏速度			xy最大最小值						窗口名
	Game::allGm[0] = Game(12,		0x004B4514, 0x988,		(float*)0x004B2ED0, 0.065f, 0.125f, 0.635f, 0.93125f, L"th12c.exe");
	Game::allGm[1] = Game(12,		0x004B4514, 0x988,		(float*)0x004B2ED0, 0.065f, 0.125f, 0.635f, 0.93125f, L"th12.exe");
	Game::allGm[2] = Game(13,		0x004C22C4, 0x5C4,		(float*)0x004C0A28, 0.065f, 0.125f, 0.635f, 0.93125f, L"th13c.exe");
	Game::allGm[3] = Game(13,		0x004C22C4, 0x5C4,		(float*)0x004C0A28, 0.065f, 0.125f, 0.635f, 0.93125f, L"th13.exe");
	Game::allGm[4] = Game(15,		0x004E9BB8, 0x624,		(float*)0x004E73E8, 0.065f, 0.125f, 0.635f, 0.93125f, L"th15.exe");
	Game::allGm[5] = Game(16,		0x004A6EF8, 0x61C,		(float*)0x004A5788, 0.065f, 0.125f, 0.635f, 0.93125f, L"th16.exe");
	Game::allGm[6] = Game(14,		0x004DB67C, 0x5EC,		(float*)0x004D8F58, 0.065f, 0.125f, 0.635f, 0.93125f, L"th14.exe");
	Game::allGm[7] = Game(10,		0x00477834, 0x3CC,		(float*)0x00476F78, 0.065f, 0.125f, 0.635f, 0.93125f, L"th10.exe",				100.0f);
	Game::allGm[8] = Game(10,		0x00477834, 0x3CC,		(float*)0x00476F78, 0.065f, 0.125f, 0.635f, 0.93125f, L"th10c.exe",				100.0f);
	Game::allGm[9] = Game(8,		0x017D61AC ,0x0,		(float*)0x017CE8E0, 0.065f, 0.085f, 0.635f, 0.93125f, L"th08.exe",				1.0f, 8.0f,376.0f,16.0f,432.0f);
	Game::allGm[10] = Game(7,		0x004BE408 ,0x0,		(float*)0x00575AC8, 0.065f, 0.085f, 0.635f, 0.93125f, L"th07.exe",				1.0f, 8.0f,376.0f,16.0f,432.0f);
	Game::allGm[11] = Game(6,		0x006CAA68 ,0x0,		(float*)0x006C6EC0, 0.065f, 0.085f,	0.635f, 0.93125f, L"搶曽峠杺嫿.exe",		1.0f, 8.0f,376.0f,16.0f,432.0f);
	Game::allGm[12] = Game(6,		0x006CAA68 ,0x0,		(float*)0x006C6EC0, 0.065f, 0.085f, 0.635f, 0.93125f, L"th06.exe",				1.0f, 8.0f,376.0f,16.0f,432.0f);
	Game::allGm[13] = Game(6,		0x006CAA68 ,0x0,		(float*)0x006C6EC0, 0.065f, 0.085f, 0.635f, 0.93125f, L"東方紅魔郷.exe",		1.0f, 8.0f,376.0f,16.0f,432.0f);
	
	Game::allGm[14] = Game(11,		-1		   ,0x0,		(float*)0x004A7948, 0.065f, 0.125f, 0.635f, 0.93125f, L"th11.exe");
	Game::allGm[18] = Game(128,		0x004B8A80, 0xED8,		(float*)0x004B6F58, 0.215f, 0.125f, 0.785f, 0.93125f, L"th128.exe");
	Game::allGm[19] = Game(125,		0x004B68C8, 0x604,		(float*)0x004B5308, 0.215f, 0.125f, 0.785f, 0.93125f, L"th125.exe");
	Game::allGm[20] = Game(125,		0x004B68C8, 0x604,		(float*)0x004B5308, 0.215f, 0.125f, 0.785f, 0.93125f, L"th125c.exe");
	Game::allGm[21] = Game(143,		0x004E6B88, 0x5EC,		(float*)0x004E40B0, 0.215f, 0.125f, 0.785f, 0.93125f, L"th143.exe");
	Game::allGm[22] = Game(165,		0x004B5654, 0x618,		(float*)0x004B39D0, 0.215f, 0.125f, 0.785f, 0.93125f, L"th165.exe");
	Game::allGm[23] = Game(95,		0x004C3E34, 0x1E30,		(float*)0x004BCED8, 0.215f, 0.125f, 0.785f, 0.94125f, L"th095.exe",			1.0f,-184.0f,184.0f,32.0f,436.0f);
	Game::allGm[24] = Game(9,		0x004A7D94, 0x1B88,		(float*)0x004B36B8, 0.04f,	0.125f,	0.46f, 0.94125f , L"th09.exe",			1.0f,-136.0f,136.0f,32.0f,436.0f);
	Game::allGm[25] = Game(17,		0x004B77D0, 0x61C,		(float*)-1, 0.065f, 0.125f, 0.635f, 0.93125f        , L"th17.exe");
	Game::allGm[26] = Game(18,		0x004CF410, 0x62C,		(float*)-1, 0.065f, 0.125f, 0.635f, 0.93125f        , L"th18.exe");
	
	Game::allGm[15] = Game(-100,	0x00FE2350,0x0,			(float*)-1		   ,0.065f, 0.125f, 0.635f, 0.93125f, L"thsg.exe",				1.0f,10.0f,374.0f,32.0f,433.0f);
	//水晶宫
	Game::allGm[16] = Game(-101,	0x00A8CDF8,0x0,			(float*)-1		   ,0.065f, 0.095f,	0.635f, 0.93125f, L"东方海惠堂.exe",		1.0f,8.0f,376.0f,16.0f,432.0f);
	//海惠堂,需要改窗口配置以获得最佳游戏体验
	Game::allGm[17] = Game(-102,	0x017D2EA0,0x0,			(float*)-1		   ,0.19f,  0.03f,	0.81f, 0.99f, L"QP Shooting.exe",		1.0f,-250.0f,250.0f,-300.0f,300.0f);
	//QP shooting(窗口大小1280*960)
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
	case 9:
	case 95:
	case 10:
	case 12:
	case 125:
	case 128:
	case 13:
	case 14:
	case 143:
	case 15:
	case 16:
	case 17:
	case 18:
	case 165:
		ReadProcessMemory(GM_HWND, (LPCVOID)this->ptPlBasic, &ptPl, sizeof(DWORD), NULL);
		break;
	case -102:
	case -101:
	case -100:
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
	if (this->ptRunSpd == (float*)-1)return 0;
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
	case 9:
	case 95:
	{
		float finalX, finalY;
		finalX = (this->StageXMin + relX * StageXSz) * ratio;
		finalY = (this->StageYMin + relY * StageYSz) * ratio;
		WriteProcessMemory(GM_HWND, (LPVOID)(ptPl + this->ptPloffs), &finalX, sizeof(DWORD), NULL);
		WriteProcessMemory(GM_HWND, (LPVOID)(ptPl + this->ptPloffs+4), &finalY, sizeof(DWORD), NULL);
	}
	break;
	case -100:
	case -101:
	{
		double finalXd, finalYd;
		finalXd = (this->StageXMin + relX * StageXSz) * ratio;
		finalYd = (this->StageYMin + relY * StageYSz) * ratio;
		WriteProcessMemory(GM_HWND, (LPVOID)this->ptPlBasic, &finalXd, sizeof(QWORD), NULL);
		WriteProcessMemory(GM_HWND, (LPVOID)(this->ptPlBasic + 8), &finalYd, sizeof(QWORD), NULL);
	}
	break;
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
	case 125:
	case 128:
	case 13:
	case 14:
	case 143:
	case 15:
	case 16:
	case 17:
	case 18:
	case 165:
	{
		int finalX, finalY;
		finalX = (int)(this->StageXMin + relX * StageXSz) * ratio;
		finalY = (int)(this->StageYMin + relY * StageYSz) * ratio;
		WriteProcessMemory(GM_HWND, (LPVOID)(ptPl + this->ptPloffs), &finalX, sizeof(DWORD), NULL);
		WriteProcessMemory(GM_HWND, (LPVOID)(ptPl + this->ptPloffs + 4), &finalY, sizeof(DWORD), NULL);
	}
		break;
	case -102:
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
