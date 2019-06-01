#include<windows.h>
#include<bits/stdc++.h>
#include<cstring>
#define Wide 600
#define High 480
#define ll long long
#define EditMenu1 1
#define EditMenu2 2
#define StaticMenu1 3
#define StaticMenu2 4
#define EditMenu3 5
#define EditMenu4 6
#define EditMenu5 7
#define EditMenu6 8
#define StaticMenu3 9
#define EditMenu7 10
#define StaticMenu4 11
#define ButtonMenu1 12

using namespace std;

void Fprint(int a);
void PaintTheText();
int GetNum(char *number);
bool InRect(RECT a,POINT b);
int getred(COLORREF a);
int getgreen(COLORREF a);
int getblue(COLORREF a);
void DisPlay(HWND hwnd);
void map_init(HWND hwnd);
void textdraw_out(TCHAR *BmpName,TCHAR *OutName,HDC ShowInDc,int wx,int wy,int l,int r,int u,int d);
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

HDC wmp,DDc;
HBITMAP DBitMap;
HINSTANCE EditHins1,EditHins2,EditHins3,EditHins4,EditHins5,EditHins6,EditHins7;
HINSTANCE StaticHins1,StaticHins2,StaticHins3,StaticHins4;
HINSTANCE ButtonHins1;
HWND Edit1,Edit2,Edit3,Edit4,Edit5,Edit6,Edit7;
HWND Static1,Static2,Static3,Static4;
HWND Button1;
HBRUSH black;

DWORD WINAPI Main(LPVOID lParam){
	HWND hwnd=*(HWND*)lParam;
	/*Write down your code here*/
	

    
	while(1);
	exit(0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc;
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); 
	if(!RegisterClassEx(&wc)) {MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);return 0;}
	hwnd=CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","TXT_ARTIST",WS_VISIBLE|WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,Wide,High,NULL,NULL,hInstance,NULL);
	if(hwnd==NULL){MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);return 0;}
	map_init(hwnd);
	HANDLE hThread=CreateThread(NULL,0,Main,&hwnd,0,NULL);
	while(msg.message!=WM_QUIT){
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){TranslateMessage(&msg);DispatchMessage(&msg);}
		else DisPlay(hwnd);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam){
	switch(Message){
		case WM_DESTROY:{PostQuitMessage(0);break;}
		case WM_LBUTTONDOWN:{
			RECT wrect;
			POINT cPos;
			GetWindowRect(hwnd,&wrect);
			GetCursorPos(&cPos);
			cPos.x-=wrect.left;
			cPos.y-=wrect.top;
			RECT Buttona={70*2+50*5,365,70*2+50*5+190,365+25};
			if(InRect(Buttona,cPos));
				PaintTheText();
		}
		default:return DefWindowProc(hwnd,Message,wParam,lParam);
	}
	return 0;
}
void map_init(HWND hwnd)
{	
	wmp=GetDC(hwnd);
	DDc=CreateCompatibleDC(wmp);
	DBitMap=CreateCompatibleBitmap(wmp,Wide,High-115);
	SelectObject(DDc,DBitMap);
	black=CreateSolidBrush(RGB(0,0,0));
	SelectObject(DDc,black);
	Edit1=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70 /*X坐标*/, 390/*Y坐标*/, Wide-70/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu1,
        EditHins1,
        NULL
        );
	Edit2=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70 /*X坐标*/, 415/*Y坐标*/, Wide-70/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu2,
        EditHins2,
        NULL
        );
	Edit3=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70 /*X坐标*/, 365/*Y坐标*/, 50/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu3,
        EditHins3,
        NULL
        );
	Edit4=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70+50 /*X坐标*/, 365/*Y坐标*/, 50/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu4,
        EditHins4,
        NULL
        );
	Edit5=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70+50*2 /*X坐标*/, 365/*Y坐标*/, 50/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu5,
        EditHins5,
        NULL
        );
	Edit6=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70+50*3 /*X坐标*/, 365/*Y坐标*/, 50/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu6,
        EditHins6,
        NULL
        );
	Edit7=CreateWindow(
        TEXT("edit"),
        "",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_LEFT,
        70*2+50*4 /*X坐标*/, 365/*Y坐标*/, 50/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)EditMenu7,
        EditHins7,
        NULL
        );
	Static1=CreateWindow(
        TEXT("static"),
        "图片路径",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_CENTER,
        0 /*X坐标*/, 390/*Y坐标*/, 70/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)StaticMenu1,
        StaticHins1,
        NULL
        );
	Static2=CreateWindow(
        TEXT("static"),
        "输出路径",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_CENTER,
        0 /*X坐标*/, 415/*Y坐标*/, 70/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)StaticMenu2,
        StaticHins2,
        NULL
        );
	Static3=CreateWindow(
        TEXT("static"),
        "左右上下",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_CENTER,
        0 /*X坐标*/, 365/*Y坐标*/, 70/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)StaticMenu3,
        StaticHins3,
        NULL
        );
	Static4=CreateWindow(
        TEXT("static"),
        "单位长度",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_CENTER,
        70+50*4 /*X坐标*/, 365/*Y坐标*/, 70/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)StaticMenu4,
        StaticHins4,
        NULL
        );
	Button1=CreateWindow(
        TEXT("static"),
        "生成TXT绘图！",
        WS_CHILD| WS_VISIBLE| WS_BORDER|ES_CENTER,
        70*2+50*5 /*X坐标*/, 365/*Y坐标*/, 190/*宽度*/,25/*高度*/, hwnd/*父窗口句柄*/,
        (HMENU)ButtonMenu1,
        ButtonHins1,
        NULL
        );
}
void DisPlay(HWND hwnd)
{
	BitBlt(wmp,0,0,Wide,High-115,DDc,0,0,SRCCOPY);
}
void textdraw_out(TCHAR *BmpName,TCHAR *OutName,HDC ShowInDc,int wx,int wy,int l,int r,int u,int d,int sqrnum)
{
	TCHAR ch[100];
	HBITMAP	bmp=(HBITMAP)LoadImage(GetModuleHandle(0),BmpName,
	IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	HDC MpDc=CreateCompatibleDC(DDc);
	Rectangle(ShowInDc,-1,-1,640,480);
	SelectObject(MpDc,bmp);
	BitBlt(ShowInDc,wx,wy,r-l,d-u,MpDc,l,u,SRCCOPY);
	freopen(OutName,"w",stdout);
	for(int i=u/sqrnum;i<=d/sqrnum;i++)
	{
		for(int j=l/sqrnum;j<=r/sqrnum;j++)
		{
			int nowcr=8,mxn=0;
			for(int x=j*sqrnum;x<(j+1)*sqrnum;x++)
			for(int y=i*sqrnum;y<(i+1)*sqrnum;y++)
			{
				int crsum[10],redv,greenv,bluev,darkv;
				for(int i=0;i<10;i++)crsum[i]=0; 
				COLORREF cr=GetPixel(MpDc,x,y);
				redv=getred(cr);
				greenv=getgreen(cr);
				bluev=getblue(cr);
				darkv=(redv+greenv+bluev)/90;
				crsum[darkv]++;
				if(crsum[darkv]>mxn)mxn=crsum[darkv],nowcr=darkv;
			}
			Fprint(nowcr);
		}
		puts("");
	}
	freopen("CON","w",stdout);
	DeleteObject(bmp);
	DeleteDC(MpDc);
}
int getred(COLORREF a){
	int gb=a>>8;
	gb=gb<<8;
	return a-gb;
}
int getgreen(COLORREF a){
	int gb=a>>8,b=a>>16;
	b=b<<8;
	return gb-b;
}
int getblue(COLORREF a){
	int b=a>>16,aph=a>>24;
	aph=aph<<8;
	return b-aph;
}
void Fprint(int a)
{
	if(a==0)printf("繁");
	if(a==1)printf("聚");
	if(a==2)printf("靖");
	if(a==3)printf("国");
	if(a==4)printf("四");
	if(a==5)printf("久");
	if(a==6)printf("十");
	if(a==7)printf("？");
	if(a==8)printf("。");
}
bool InRect(RECT a,POINT b)
{
	if(b.x>=a.left&&b.x<=a.right&&b.y>=a.top&&b.y<=a.bottom)return true;
	return false;
}
void PaintTheText()
{
	TCHAR Map[256],Text[256],L[100];
	char R[100],U[100],D[100],Ln[100];
	SendMessage(Edit1,WM_GETTEXT,256,(LPARAM)Map);
	SendMessage(Edit2,WM_GETTEXT,256,(LPARAM)Text);
	SendMessage(Edit3,WM_GETTEXT,256,(LPARAM)L);
	SendMessage(Edit4,WM_GETTEXT,256,(LPARAM)R);
	SendMessage(Edit5,WM_GETTEXT,256,(LPARAM)U);
	SendMessage(Edit6,WM_GETTEXT,256,(LPARAM)D);
	SendMessage(Edit7,WM_GETTEXT,256,(LPARAM)Ln);
	textdraw_out(Map,Text,DDc,0,0,GetNum(L),GetNum(R),GetNum(U),GetNum(D),GetNum(Ln));
}
int GetNum(char *number)
{
	int ans=0,i=0;
	while(number[i]>='0'&&number[i]<='9')
	{
		ans=ans*10+(number[i]-'0');
		i++;
	}
	return ans;
}
