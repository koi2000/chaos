#include<iostream>
#include<easyx.h>
#include<conio.h>
#include<graphics.h>
#include"win.h"
#include"pc.h"
#define esp 10
using namespace std;
int draw();
int drawpc();
//int drawpp();
int win(int a[20][20], int b,int c);
int i1 = 0;
void showmenu()
{
	cout << "请选择你想要选择的模式" << endl;
	cout << "1.两人对弈" << endl;
	cout << "2.人机对弈" << endl;
	cout << "3.机器对战" << endl;
	cout << "4.退出" << endl;
}
void checkboard()//画棋盘
{
	initgraph(630, 630, EW_DBLCLKS);	// 创建绘图窗口，大小为 630*630 像素
	setbkcolor(RGB(245,204,132));
	cleardevice();
	setlinecolor(BLACK);
	for (int i = 1;i <= 20;i++)
	{
		line(30, 30 * i, 600, 30 * i);
		line(30 * i, 30, 30 * i, 600);
	}
}
int draw()//人人对战下棋
{
	i1 = 0;
	int willbreak=0;
	int map[30][30];
	for (int i = 0;i < 30;i++)
	{
		for (int k = 0;k < 30;k++)
		{
			if (i < 20 && k < 20)
			{
				map[i][k] = 0;
			}
			else
			{
				map[i][k] = 3;
			}
		}
	}
	MOUSEMSG m;
	while (true)
	{
		FlushMouseMsgBuffer();
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
		{
			for (int i = 0;i < 20;i++)
			{
				for (int k = 0;k < 20;k++)
				{
					if (abs(m.x - 30 * i-30) <= esp && abs(m.y - 30 * k-30) <= esp)
					{
						if (i1 % 2 == 1)
						{
							setfillcolor(RGB(255,255,255));
							if (map[i][k] == 0)//防止重复下棋
							{
								i1++;
								solidcircle(30 * i+30, 30 * k+30, 8);
								map[i][k] = 1;//白色为1
								
								}
							willbreak = win(map);
							if (willbreak == 1)
							{
								return 1;
							}
						}
						else
						{
							setfillcolor(RGB(0,0,0));
							if (map[i][k] == 0)//防止重复下棋
							{
								i1++;
								solidcircle(30 * i+30, 30 * k+30, 8);
								map[i][k] = 2;//黑色为2
								
							}
							willbreak = win(map);
							if (willbreak == 1)
							{
								return 1;
							}
						}
					}
				}
			}
		}
		}
	}
}
int drawpc()//人机对战下棋
{
	i1 = 0;
	int willbreakpc = 0;
	int mappc[30][30];
	for (int i = 0;i < 30;i++)
	{
		for (int k = 0;k < 30;k++)
		{
			if (i < 20 && k < 20)
			{
				mappc[i][k] = 0;
			}
			else
			{
				mappc[i][k] = 3;
			}
		}
	}
	int pc[2] = { 0 };
	MOUSEMSG mpc;
	while (true)
	{
		FlushMouseMsgBuffer();
		if (i1 % 2 == 1)
		{
			setfillcolor(RGB(255, 255, 255));
			int cmp=computer(mappc, pc);
			solidcircle(pc[0]*30, pc[1]*30, 8);
			willbreakpc = win(mappc);
			if (willbreakpc == 1)
			{
				return 1;
			}
			if (cmp==1)
			{
				i1++;
			}
		}
		if (i1 % 2 == 0)
		{
			mpc = GetMouseMsg();
			switch (mpc.uMsg)
			{
			case WM_LBUTTONDOWN:
			{
				for (int i = 1;i <= 20;i++)
				{
					for (int k = 1;k <= 20;k++)
					{
						if (abs(mpc.x - 30 * i) <= esp && abs(mpc.y - 30 * k) <= esp)
						{
							setfillcolor(RGB(0, 0, 0));
							if (mappc[i - 1][k - 1] == 0)//防止重复下棋
							{
								mappc[i - 1][k - 1] = 2;//黑色为2
								i1++;
								solidcircle(30 * i, 30 * k, 8);
							}
							willbreakpc = win(mappc);
							if (willbreakpc == 1)
							{
								return 1;
							}
						}
					}
				}
			}
			}
		}
	}
}
int main()
{
	int select;
	int end = 0;
	int end1 = 0;
	while (true)
	{
		end = 0;
		end1 = 0;
		showmenu();//展示模式选择
		cin >> select;
		switch (select)//选择模式
		{
		case 1:
			checkboard();//画出棋盘
			end = draw();//人人对战下棋
			if (end == 1)
			{
				//_getch();	// 按任意键继续
				closegraph();// 关闭绘图窗口
				system("cls");
			}
			break;
		case 2:
			checkboard();
			end1=drawpc();
			if (end1 == 1)
			{
				closegraph();// 关闭绘图窗口
				system("cls");
			}
			break;
		case 3:
			cout << "功能尚未开发" << endl;
			//closegraph();// 关闭绘图窗口
			system("pause");
			system("cls");
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}