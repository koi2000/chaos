#pragma once
#include<iostream>
#include<easyx.h>
#include<conio.h>
#include<graphics.h>
int win(int map[30][30])//���˶�ս�ж���Ӯ
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
				if (map[x][y + i] == 1)//��ɫ��
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫ��
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫ��
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫ��
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)
			{
				if (map[x - i][y] == 1)//��ɫ��
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫ��
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫ��
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫ��
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)
			{
				if (map[x - i][y - i] == 1)//��ɫб
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫб
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)
			{
				if (map[x + i][y - i] == 1)//��ɫб
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫб
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
				InputBox(s1, 0, L"�׷�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫxie
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫxie
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫxie
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
				break;
			}
			else if (flag1 < 5)
			{
				flag1 = 0;
			}
			for (int i = 0;i < 5;i++)//��ɫxie
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
				InputBox(s1, 0, L"�ڷ�ʤ����д�»�ʤ���ԣ���û��ʲô��");
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
