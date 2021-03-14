#pragma once
#include<iostream>
#include<easyx.h>
#include<conio.h>
#include<graphics.h>
int win(int map[30][30])//人人对战判断输赢
{
	int flag1 = 0;
	int flag2 = 0;
	//int flag3 = 0;
	for (int x = 0;x < 20;x++)
	{
		if (flag2 == 1)
		{
			break;
		}
		for (int y = 0;y < 20;y++)
		{
			for (int i = 0;i < 5;i++)
			{
				if (map[x][y + i] == 1)//白色竖
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//白色竖
			{
				if (map[x][y - i] == 1)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色竖
			{
				if (map[x][y + i] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色竖
			{
				if (map[x][y - i] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)
			{
				if (map[x - i][y] == 1)//白色横
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//白色横
			{
				if (map[x + i][y] == 1)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色横
			{
				if (map[x - i][y] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色横
			{
				if (map[x + i][y] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{

				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)
			{
				if (map[x - i][y - i] == 1)//白色斜
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//白色斜
			{
				if (map[x + i][y + i] == 1)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)
			{
				if (map[x + i][y - i] == 1)//白色斜
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//白色斜
			{
				if (map[x - i][y + i] == 1)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"白方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色xie
			{
				if (map[x - i][y - i] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色xie
			{
				if (map[x + i][y + i] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色xie
			{
				if (map[x + i][y - i] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//黑色xie
			{
				if (map[x - i][y + i] == 2)
				{
					flag1++;
				}
				else
				{
					flag1 = 0;
					break;
				}
			}
			if (flag1 >= 5)
			{
				wchar_t s1[10];
				flag2 = 1;
				InputBox(s1, 0, L"黑方胜利请写下获胜感言（并没有什么用");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
		}
	}
	if (flag2 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
