// mouse_TH.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "gm.h"

#define IS_FAST 1

using namespace std;
extern HANDLE GM_HWND;
extern int NW_GAME;
extern int PID;
extern int ARR_NUM;
extern HWND WIND_HWND;
WCHAR OUT_TEXT[256];
int main()
{
	int timeNw,timePre;
	init();
	GetGame(GM_HWND, NW_GAME,PID, ARR_NUM);
	init2();
	timePre = GetTickCount();
	if (GM_HWND != NULL)
	{
		wsprintf(OUT_TEXT,L"进程pid号:%d\n当前游戏版本:%d", PID, Game::allGm[ARR_NUM].num);
		MessageBox(NULL, OUT_TEXT, L"加载成功", MB_OK);
		Game& nwGame = Game::allGm[ARR_NUM];
		while (1){
			timeNw = GetTickCount();
			int isf = 0;
	#ifdef IS_FAST
			isf = 0;
	#endif
			if (isf || timeNw-timePre>=10){
#ifndef IS_FAST
				system("cls");
#endif
				timePre = timeNw;
				switch (nwGame.MouseControl())
				{
				case NORMAL_FLAG:
					break;
				case PAUSE_FLAG:
					cout << "时停中不能移动da☆ze";
					break;
				case NOT_IN_GAME_FLAG:
					cout << "未发现自机坐标,请进入游戏\n";
					Sleep(100);
					break;
				}
			}
		}
	}
}
