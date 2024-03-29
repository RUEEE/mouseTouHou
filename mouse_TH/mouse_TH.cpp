// mouse_TH.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "gm.h"
#pragma GCC optimize(2)
using namespace std;
extern HANDLE GM_HWND;
extern int NW_GAME;
extern int PID;
extern int ARR_NUM;
extern HWND WIND_HWND;
WCHAR OUT_TEXT[512];
extern int NORMAL_MOUSE_SPEED;
extern int SLOW_MOUSE_SPEED;
void setMouseSpeed()
{
	int k;
	if (GetAsyncKeyState(VK_LSHIFT))
	{
		k = SystemParametersInfo(SPI_SETMOUSESPEED, 0, (void*)SLOW_MOUSE_SPEED, SPIF_SENDCHANGE);
	}
	else
	{
		k = SystemParametersInfo(SPI_SETMOUSESPEED, 0, (void*)NORMAL_MOUSE_SPEED, SPIF_SENDCHANGE);
	}

}

int main()
{
	init();
	if (NORMAL_MOUSE_SPEED == -1)
	{
		MessageBox(NULL, OUT_TEXT, L"获取鼠标速度失败", MB_OK);
		return 0;
	}
	GetGame(GM_HWND, NW_GAME,PID, ARR_NUM);
	init2();
	if (GM_HWND != NULL)
	{
		wsprintf(OUT_TEXT,L"进程pid号:%d\n当前游戏版本:%d\n默认鼠标速度:%d\n请不要在按shift的时候关闭程序\n如有意外请使用「控制面板」\n对数位板等无效请注意", PID, Game::allGm[ARR_NUM].num,NORMAL_MOUSE_SPEED);
		MessageBox(NULL, OUT_TEXT, L"加载成功", MB_OK);
		Game& nwGame = Game::allGm[ARR_NUM];
		ios::sync_with_stdio(0);
		while (1){
			setMouseSpeed();
			switch (nwGame.MouseControl())
			{
			case PAUSE_FLAG:
				system("cls");
				break;
			case NOT_IN_GAME_FLAG:
				system("cls");
				cout << "未发现自机坐标,请进入游戏\n";
				Sleep(16);
				break;
			default:
			case NORMAL_FLAG:
				break;
			}
		}
	}
}
