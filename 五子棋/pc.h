#pragma once
#include<iostream>
#include<easyx.h>
#include<conio.h>
#include<graphics.h>
int computer(int mappc[30][30], int pc[2])
{
	int flag = 0;
	for (int i = 0;i < 20;i++)//���Լ����ĸ�������һ��ʱ���Ƚ��Լ�������������
	{
		if (flag == 1)
		{
			break;
		}
		for (int k = 0;k < 20;k++)
		{
			if (mappc[i][k] == 1 && mappc[i][k + 1] == 1 && mappc[i][k + 2] == 1 && mappc[i][k + 3] == 1)//������
			{
				if (k + 4 < 20)
				{
					if (mappc[i][k + 4] == 0)
					{
						mappc[i][k+4] = 1;
						pc[0] = i + 1;
						pc[1] = k + 5;
						flag = 1;
						break;
					}
				}
				else if (k - 1 >= 0)
				{
					if (mappc[i][k-1] == 0)
					{
						mappc[i][k - 1] = 1;
						pc[0] = i + 1;
						pc[1] = k;
						flag = 1;
						break;
					}
				}
			}
			if (mappc[i][k] == 1 && mappc[i+1][k] == 1 && mappc[i+2][k] == 1 && mappc[i+3][k] == 1)//������
			{
				if (i + 4 < 20)
				{
					if (mappc[i+4][k] == 0)
					{
						mappc[i+4][k] = 1;
						pc[0] = i + 5;
						pc[1] = k + 1;
						flag = 1;
						break;
					}
				}
				else if (i - 1 >= 0)
				{
					if (mappc[i-1][k] == 0)
					{
						mappc[i - 1][k] = 1;
						pc[0] = i;
						pc[1] = k + 1;
						flag = 1;
						break;
					}
				}
			}
			if (mappc[i][k] == 1 && mappc[i + 1][k+1] == 1 && mappc[i + 2][k+2] == 1 && mappc[i + 3][k+3] == 1)//б
			{
				if (i + 4 < 20 && k + 4 < 20)
				{
					if (mappc[i + 4][k + 4] == 0)
					{
						mappc[i + 4][k + 4] = 1;
						pc[0] = i + 5;
						pc[1] = k + 5;
						flag = 1;
						break;
					}
				}
				else if (i - 1 >= 0 && k - 1 >= 0)
				{
					if (mappc[i - 1][k - 1] == 0)
					{
						mappc[i - 1][k - 1] = 0;
						pc[0] = i;
						pc[1] = k;
						flag = 1;
						break;
					}
				}
			}
			if (mappc[i][k] == 1 && mappc[i - 1][k + 1] == 1 && mappc[i - 2][k + 2] == 1&&mappc[i-3][k+3]==1)//xie�����ж�
			{
				if (k + 4 < 20 && i - 4 >=0)
				{
					if (mappc[i - 4][k + 4] == 0)
					{
						mappc[i - 4][k + 4] = 1;
						//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
						pc[0] = i - 3;
						pc[1] = k + 5;
						flag = 1;
						break;
					}
				}
				else if (k - 1 >= 0 && i + 1 < 20)
				{
					if (mappc[i + 1][k - 1] == 0)
					{
						mappc[i + 1][k - 1] = 1;
						//solidcircle(30 * (i + 1), 30 * k, 8);
						pc[0] = i+2;
						pc[1] = k;
						flag = 1;
						break;
					}
				}
			}
			if (mappc[i][k] == 1 && mappc[i + 1][k - 1] == 1 && mappc[i + 2][k - 2] == 1&&mappc[i+3][k-3]==1)//xie�������ж�
			{
				if (k - 4 >= 0 && i + 4 < 20)
				{
					if (mappc[i + 4][k - 4] == 0)
					{
						mappc[i + 4][k - 4] = 1;
						//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
						pc[0] = i + 5;
						pc[1] = k - 3;
						flag = 1;
						break;
					}
				}
				else if (k + 1 < 20 && i - 1 >= 0)
				{
					if (mappc[i - 1][k + 1] == 0)
					{
						mappc[i - 1][k + 1] = 1;
						//solidcircle(30 * (i + 1), 30 * k, 8);
						pc[0] = i;
						pc[1] = k + 2;
						flag = 1;
						break;
					}
				}
			}
		}
	}
	if (flag != 1)
	{
		for (int i = 0;i < 20;i++)//�¶Է�������
		{
			if (flag == 1)
			{
				break;
			}
			for (int k = 0;k < 20;k++)
			{
				if (mappc[i][k] == 2 && mappc[i + 1][k] == 2 && mappc[i + 2][k] == 2 && mappc[i + 3][k] == 2)//�������ж�
				{
					
						if (mappc[i + 4][k] == 0)
						{
							mappc[i + 4][k] = 1;
							//solidcircle(30 * (i + 4), 30 * (k + 1), 8);
							pc[0] = i + 5;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					
					else if (i - 1 >= 0)
					{
						if (mappc[i - 1][1] == 0)
						{
							mappc[i - 1][k] = 1;
							//solidcircle(30 * i, 30 * k + 30, 8);
							pc[0] = i;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i - 1][k] == 2 && mappc[i - 2][k] == 2 && mappc[i - 3][k] == 2)//�������ж�
				{
					
						if (mappc[i - 4][k] == 0)
						{
							mappc[i - 4][k] = 1;
							//solidcircle(30 * (i + 4), 30 * (k + 1), 8);
							pc[0] = i - 3;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					
					else if (i + 1 < 20)
					{
						if (mappc[i + 1][1] == 0)
						{
							mappc[i + 1][k] = 1;
							//solidcircle(30 * i, 30 * k + 30, 8);
							pc[0] = i+2;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i][k + 1] == 2 && mappc[i][k + 2] == 2 && mappc[i][k + 3] == 2)//�������ж�
				{
					
						if (mappc[i][k + 4] == 0)
						{
							mappc[i][k + 4] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i + 1;
							pc[1] = k + 5;
							flag = 1;
							break;
						}
					
					else if (k - 1 >= 0)
					{
						if (mappc[i][k - 1] == 0)
						{
							mappc[i][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i + 1;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i][k - 1] == 2 && mappc[i][k - 2] == 2 && mappc[i][k - 3] == 2)//�������ж�
				{
					
						if (mappc[i][k - 4] == 0)
						{
							mappc[i][k - 4] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i + 1;
							pc[1] = k - 3;
							flag = 1;
							break;
						}
					
					else if (k + 1 >= 0)
					{
						if (mappc[i][k + 1] == 0)
						{
							mappc[i][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i + 1;
							pc[1] = k+2;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i + 1][k + 1] == 2 && mappc[i + 2][k + 2] == 2 && mappc[i + 3][k + 3] == 2)//xie�����ж�
				{
					
						if (mappc[i + 4][k + 4] == 0)
						{
							mappc[i + 4][k + 4] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i + 5;
							pc[1] = k + 5;
							flag = 1;
							break;
						}
					
					else if (k - 1 >= 0 && i - 1 <= 0)
					{
						if (mappc[i - 1][k - 1] == 0)
						{
							mappc[i - 1][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i - 1][k - 1] == 2 && mappc[i - 2][k - 2] == 2 && mappc[i - 3][k - 3] == 2)//xie�����ж�
				{
					if (k - 4 > 0 && i -4 > 20)
					{
						if (mappc[i - 4][k - 4] == 0)
						{
							mappc[i - 4][k - 4] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i + 3;
							pc[1] = k + 3;
							flag = 1;
							break;
						}
					}
					else if (k + 1 < 20 && i + 1 < 20)
					{
						if (mappc[i + 1][k + 1] == 0)
						{
							mappc[i + 1][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i+2;
							pc[1] = k+2;
							flag = 1;
							break;
						}
					}
				}
				/*if (mappc[i][k] == 2 && mappc[i - 1][k + 1] == 2 && mappc[i - 2][k + 2] == 2 && mappc[i - 3][k + 3] == 2)//xie�����ж�
				{
					if (k + 4 < 20 && i - 4 >= 0)
					{
						if (mappc[i - 4][k + 4] == 0)
						{
							mappc[i - 4][k + 4] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i - 3;
							pc[1] = k + 5;
							flag = 1;
							break;
						}
					}
					else if (k - 1 >= 0 && i + 1 >= 20)
					{
						if (mappc[i + 1][k - 1] == 0)
						{
							mappc[i + 1][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i + 2;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i + 1][k - 1] == 2 && mappc[i + 2][k - 2] == 2 && mappc[i + 3][k - 3] == 2)//xie�����ж�
				{
					if (k - 4 >= 0 && i + 4 < 20)
					{
						if (mappc[i + 4][k - 4] == 0)
						{
							mappc[i + 4][k - 4] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i + 5;
							pc[1] = k - 3;
							flag = 1;
							break;
						}
					}
					else if (k + 1 <= 20 && i - 1 >= 0)
					{
						if (mappc[i - 1][k + 1] == 0)
						{
							mappc[i - 1][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i;
							pc[1] = k + 2;
							flag = 1;
							break;
						}
					}
				}*/
			}
		}
	}
	if (flag != 1)
	{
		for (int i = 0;i < 20;i++)//�¶Է�������
		{
			if (flag == 1)
			{
				break;
			}
			for (int k = 0;k < 20;k++)
			{
				if (mappc[i][k] == 2 && mappc[i + 1][k] == 2 && mappc[i + 2][k] == 2)//���������ж�
				{
					if (i + 3 < 20)
					{
						if (mappc[i + 3][k] == 0)
						{
							mappc[i + 3][k] = 1;
							//solidcircle(30 * (i + 4), 30 * (k + 1), 8);
							pc[0] = i + 4;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
					else if (i - 1 >= 0)
					{
						if (mappc[i - 1][1] == 0)
						{
							mappc[i - 1][k] = 1;
							//solidcircle(30 * i, 30 * k + 30, 8);
							pc[0] = i;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i - 1][k] == 2 && mappc[i - 2][k] == 2)//���������ж�
				{
					if (i - 3 >= 0)
					{
						if (mappc[i - 3][k] == 0)
						{
							mappc[i - 3][k] = 1;
							//solidcircle(30 * (i + 4), 30 * (k + 1), 8);
							pc[0] = i - 2;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
					else if (i + 1 >= 0)
					{
						if (mappc[i + 1][1] == 0)
						{
							mappc[i + 1][k] = 1;
							//solidcircle(30 * i, 30 * k + 30, 8);
							pc[0] = i + 2;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i][k + 1] == 2 && mappc[i][k + 2] == 2)//���������ж�
				{
					if (k + 3 < 20)
					{
						if (mappc[i][k + 3] == 0)
						{
							mappc[i][k + 3] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
							pc[0] = i + 1;
							pc[1] = k + 4;
							flag = 1;
							break;
						}
					}
					else if (k - 1 >= 0)
					{
						if (mappc[i][k - 1] == 0)
						{
							mappc[i][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i + 1;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
					if (mappc[i][k] == 2 && mappc[i][k - 1] == 2 && mappc[i][k - 2] == 2)//���������ж�
					{
						if (k - 3 >= 0)
						{
							if (mappc[i][k - 3] == 0)
							{
								mappc[i][k - 3] = 1;
								//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
								pc[0] = i + 1;
								pc[1] = k - 2;
								flag = 1;
								break;
							}
						}
						else if (k + 1 >= 0)
						{
							if (mappc[i][k + 1] == 0)
							{
								mappc[i][k + 1] = 1;
								//solidcircle(30 * (i + 1), 30 * k, 8);
								pc[0] = i + 1;
								pc[1] = k + 2;
								flag = 1;
								break;
							}
						}
						if (mappc[i][k] == 2 && mappc[i + 1][k + 1] == 2 && mappc[i + 2][k + 2] == 2)//xie�������ж�
						{
							if (k + 3 < 20 && i + 3 < 20)
							{
								if (mappc[i + 3][k + 3] == 0)
								{
									mappc[i + 3][k + 3] = 1;
									//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
									pc[0] = i + 4;
									pc[1] = k + 4;
									flag = 1;
									break;
								}
							}
							else if (k - 1 >= 0 && i - 1 <= 0)
							{
								if (mappc[i - 1][k - 1] == 0)
								{
									mappc[i - 1][k - 1] = 1;
									//solidcircle(30 * (i + 1), 30 * k, 8);
									pc[0] = i;
									pc[1] = k;
									flag = 1;
									break;
								}
							}
						}
						if (mappc[i][k] == 2 && mappc[i - 1][k - 1] == 2 && mappc[i - 2][k - 2] == 2)//xie�������ж�
						{
							if (k - 3 > 0 && i - 3 > 0)
							{
								if (mappc[i - 3][k - 3] == 0)
								{
									mappc[i - 3][k - 3] = 1;
									//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
									pc[0] = i + 2;
									pc[1] = k + 2;
									flag = 1;
									break;
								}
							}
							else if (k + 1 < 20 && i + 1 < 20)
							{
								if (mappc[i + 1][k + 1] == 0)
								{
									mappc[i + 1][k + 1] = 1;
									//solidcircle(30 * (i + 1), 30 * k, 8);
									pc[0] = i + 2;
									pc[1] = k + 2;
									flag = 1;
									break;
								}
							}
						}
						if (mappc[i][k] == 2 && mappc[i - 1][k + 1] == 2 && mappc[i - 2][k + 2] == 2)//xie�������ж�
						{
							if (k + 3 < 20 && i - 3 >= 0)
							{
								if (mappc[i - 3][k + 3] == 0)
								{
									mappc[i - 3][k + 3] = 1;
									//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
									pc[0] = i - 2;
									pc[1] = k + 4;
									flag = 1;
									break;
								}
							}
							else if (k - 1 >= 0 && i + 1 < 20)
							{
								if (mappc[i + 1][k - 1] == 0)
								{
									mappc[i + 1][k - 1] = 1;
									//solidcircle(30 * (i + 1), 30 * k, 8);
									pc[0] = i + 2;
									pc[1] = k;
									flag = 1;
									break;
								}
							}
						}
						if (mappc[i][k] == 2 && mappc[i + 1][k - 1] == 2 && mappc[i + 2][k - 2] == 2)//xie�������ж�
						{
							if (k - 3 >= 0 && i + 3 < 20)
							{
								if (mappc[i + 3][k - 3] == 0)
								{
									mappc[i + 3][k - 3] = 1;
									//solidcircle(30 * (i + 1), 30 * (k + 4), 8);
									pc[0] = i + 4;
									pc[1] = k - 2;
									flag = 1;
									break;
								}
							}
							else if (k + 1 <= 20 && i - 1 >= 0)
							{
								if (mappc[i - 1][k + 1] == 0)
								{
									mappc[i - 1][k + 1] = 1;
									//solidcircle(30 * (i + 1), 30 * k, 8);
									pc[0] = i;
									pc[1] = k + 2;
									flag = 1;
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	if (flag != 1)
	{
		for (int i = 0;i < 20;i++)
		{
			if (flag == 1)
			{
				break;
			}
			for (int k = 0;k < 20;k++)
			{

				if (mappc[i][k] == 2 && mappc[i + 1][k] == 2)//���Ŷ����ж�
				{
					if (i + 2 < 20)
					{
						if (mappc[i + 2][k] == 0)
						{
							mappc[i + 2][k] = 1;
							//solidcircle(30 * (i + 3), 30 * (k + 1), 8);
							pc[0] = i + 3;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
					else if (i - 1 >= 0)
					{
						if (mappc[i - 1][1] == 0)
						{
							mappc[i - 1][k] = 1;
							//solidcircle(30 * i, 30 * k + 30, 8);
							pc[0] = i;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i - 1][k] == 2)//���Ŷ����ж�
				{
					if (i - 2 >= 0)
					{
						if (mappc[i - 2][k] == 0)
						{
							mappc[i - 2][k] = 1;
							//solidcircle(30 * (i + 3), 30 * (k + 1), 8);
							pc[0] = i - 1;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
					else if (i + 1 < 20)
					{
						if (mappc[i + 1][1] == 0)
						{
							mappc[i + 1][k] = 1;
							//solidcircle(30 * i, 30 * k + 30, 8);
							pc[0] = i+2;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i][k + 1] == 2)//���Ŷ����ж�
				{
					if (k + 2 < 20)
					{
						if (mappc[i][k + 2] == 0)
						{
							mappc[i][k + 2] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 3), 8);
							pc[0] = i + 1;
							pc[1] = k + 3;
							flag = 1;
							break;
						}
					}
					else if (k - 1 >= 0)
					{
						if (mappc[i][k - 1] == 0)
						{
							mappc[i][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i + 1;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
				}
				if (mappc[i][k] == 2 && mappc[i][k - 1] == 2)//���Ŷ����ж�
				{
					if (k - 2 < 20)
					{
						if (mappc[i][k - 2] == 0)
						{
							mappc[i][k - 2] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 3), 8);
							pc[0] = i + 1;
							pc[1] = k - 1;
							flag = 1;
							break;
						}
					}
					else if (k + 1 >= 0)
					{
						if (mappc[i][k + 1] == 0)
						{
							mappc[i][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * k, 8);
							pc[0] = i + 1;
							pc[1] = k+2;
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}
	/*if (flag != 1)
	{
		for (int i = 0;i < 20;i++)
		{
			if (flag == 1)
			{
				break;
			}
			for (int k = 0;k < 20;k++)
			{
				
			}
		}
	}*/
	if (flag != 1)
	{
		for (int i = 0;i < 20;i++)
		{
			if (flag == 1)
			{
				break;
			}
			for (int k = 0;k < 20;k++)
			{
				if (mappc[i][k] == 2)//�еط��к���ʱ������Χ��
				{
					if (mappc[i][k - 1] == 0)//����
					{
						if (k - 1 >= 0)
						{
							mappc[i][k - 1] = 1;
							pc[0] = i + 1;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
					if (mappc[i + 1][k] == 0)//����������
					{
						if (i + 1 < 20)
						{
							mappc[i + 1][k] = 1;
							//solidcircle(30 * (i + 2), k + 1, 8);
							pc[0] = i + 2;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
					if (mappc[i][k + 1] == 0)//����������
					{
						if (k + 1 < 20)
						{
							mappc[i][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 2), 8);
							pc[0] = i + 1;
							pc[1] = k + 2;
							flag = 1;
							break;
						}
					}
					if (mappc[i - 1][k] == 0)//zuomian
					{
						if (i - 1 >= 0)
						{
							mappc[i - 1][k] = 1;
							pc[0] = i;
							pc[1] = k + 1;
							flag = 1;
							break;
						}
					}
					
					if (mappc[i][k] == 0)
					{
						mappc[i][k] = 1;
						pc[0] = i + 1;
						pc[1] = k + 1;
						flag = 1;
						break;
					}
					if (mappc[i + 1][k + 1] == 0)//xie1
					{
						if (k + 1 < 20 && i + 1 < 20)
						{
							mappc[i + 1][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 2), 8);
							pc[0] = i + 2;
							pc[1] = k + 2;
							flag = 1;
							break;
						}
					}
					if (mappc[i - 1][k + 1] == 0)//xie2
					{
						if (k + 1 < 20 && i - 1 >= 0)
						{
							mappc[i - 1][k + 1] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 2), 8);
							pc[0] = i;
							pc[1] = k + 2;
							flag = 1;
							break;
						}
					}
					if (mappc[i - 1][k - 1] == 0)//xie3
					{
						if (k - 1 >= 0 && i - 1 >= 0)
						{
							mappc[i - 1][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 2), 8);
							pc[0] = i;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
					if (mappc[i + 1][k - 1] == 0)//xie4
					{
						if (i + 1 < 20 && k - 1 > +0)
						{
							mappc[i + 1][k - 1] = 1;
							//solidcircle(30 * (i + 1), 30 * (k + 2), 8);
							pc[0] = i + 2;
							pc[1] = k;
							flag = 1;
							break;
						}
					}
					
				}
			}
		}
	}
	if (flag == 1)
	{
		return 1;
	}
}
