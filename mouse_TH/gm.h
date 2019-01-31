
void GetGame(HANDLE &gmHwnd, int &Gmnum,int& pid,int& arr_num);
void init();
void init2();
class Game
{
public:
	static Game allGm[40];
	float ratio;//int-float比例
	int MouseControl();
	bool isPause();
	DWORD isInGm();
	int num;//第几作,15=gzz
	DWORD ptPlBasic;
	DWORD ptPloffs;
	float* ptRunSpd;
	float xmax, ymax, xmin, ymin,ysz,xsz;
	float StageXMin,StageXMax;
	float StageYMin,StageYMax;
	float StageXSz, StageYSz;
	const WCHAR *wdName;
	Game(int in_num,DWORD in_ptPl,DWORD in_offs,float* in_ptRSpd,float in_xmin,float in_ymin,float in_xmax,float in_ymax,const WCHAR* in_wdName,
		 float inPtPosRatio = 128,float inSXMN=-184, float inSXMX=184, float inSYMN=32, float inSYMX=432)
	:num(in_num), ratio(inPtPosRatio),ptPlBasic(in_ptPl),ptPloffs(in_offs),ptRunSpd(in_ptRSpd),xmax(in_xmax),ymax(in_ymax),xmin(in_xmin),ymin(in_ymin),wdName(in_wdName),
	StageXMin(inSXMN),StageXMax(inSXMX),StageYMin(inSYMN),StageYMax(inSYMX) {
		StageXSz = StageXMax - StageXMin;
		StageYSz = StageYMax - StageYMin;
		ysz = ymax - ymin;
		xsz = xmax - xmin;
	};
	Game() { num = -1; };
};

