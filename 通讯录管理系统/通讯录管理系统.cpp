#include<iostream>
using namespace std;
#include <string>
#define MAX 1000
struct person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_address;
};
struct addressbooks
{
	struct person personarray[MAX];
	int m_size;
};
int isexist(addressbooks*abs, string name);
void cleanperson(addressbooks*abs);
void showperson(addressbooks*abs);
void deleteperson(addressbooks*abs);
void findperson(addressbooks*abs);
void modifyperson(addressbooks*abs);
void addperson(addressbooks * abs);
void showmenu()
{
	cout << "***********************************************" << endl;
	cout << "*凡六是我儿***** 1、添加联系人 *****凡六是我儿*" << endl;
	cout << "*凡六是我儿***** 2、显示联系人 *****凡六是我儿*" << endl;
	cout << "*凡六是我儿***** 3、删除联系人 *****凡六是我儿*" << endl;
	cout << "*凡六是我儿***** 4、查找联系人 *****凡六是我儿*" << endl;
	cout << "*凡六是我儿***** 5、修改联系人 *****凡六是我儿*" << endl;
	cout << "*凡六是我儿***** 6、清空联系人 *****凡六是我儿*" << endl;
	cout << "*凡六是我儿***** 0、退出通讯录 *****凡六是我儿*" << endl;
	cout << "***********************************************" << endl;
}

void cleanperson(addressbooks*abs)
{
	cout << "少年，前方可是地狱啊" << endl;
	cout << "你真的要清空吗？"<<endl;
	cout << "清空请按1"<<endl;
	cout << "不清空请按其他键"<<endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		abs->m_size = 0;
		cout << "爱消失了" << endl;
	}

	system("pause");
	system("cls");
	
}
void addperson(addressbooks * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "狗儿子，满了"<<endl;
		
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		cout << "3---中性" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2 || sex == 3)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "你还想要啥性别啊" << endl;
		}
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
		cout << "请输入联系人地址：" << endl;
		string address;
		cin >>address;
		abs->personarray[abs->m_size].m_address = address;
		cout << "恭喜你成功增加一位父亲！" << endl;
		system("pause");
		system("cls");
	}
	abs->m_size++;

}
int isexist(addressbooks*abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;
		}
		
	}
	return -1;
}
void deleteperson(addressbooks*abs)
{
	cout << "请输入你要删除的父亲姓名" << endl;
	string name;
	cin >> name;
	isexist(abs, name);
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "爱消失了" << endl;
	}
	else
	{
		cout << "你没有这个父亲" << endl;
	}
	system("pause");
	system("cls");
	
}
void showperson(addressbooks*abs)
{
	
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personarray[i].m_name << "\t";
			if (abs->personarray[i].m_sex == 1)
			{
				cout << "性别：男" << "\t";
			}
			if (abs->personarray[i].m_sex == 2)
			{
				cout << "性别：女" << "\t";
			}
			if (abs->personarray[i].m_sex == 3)
			{
				cout << "性别：中性" << "\t";
			}
			cout << "年龄：" << abs->personarray[i].m_age << "\t";
			cout << "电话：" << abs->personarray[i].m_phone << "\t";
			cout << "住址：" << abs->personarray[i].m_address << endl;
		}
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks*abs)
{
	cout << "请输入你要查找的父亲" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
		if (ret != -1)
		{
			cout << "姓名：" << abs->personarray[ret].m_name << "\t";
			cout << "性别：" << abs->personarray[ret].m_sex << "\t";
			cout << "年龄：" << abs->personarray[ret].m_age << "\t";
			cout << "电话：" << abs->personarray[ret].m_phone << "\t";
			cout << "住址：" << abs->personarray[ret].m_address << endl;
		}
		else
		{
			cout << "你没有这个父亲" << endl;
		}
		system("pause");
		system("cls");
}
void modifyperson(addressbooks*abs)
{
	cout << "你想要更改的父亲" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	
	
		if (ret != -1)
		{
			string name;
			cout << "请输入姓名" << endl;
			cin >> name;
			abs->personarray[ret].m_name = name;
			int sex = 0;
			cout << "请输入性别" << endl;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2 || sex == 3)
				{
					abs->personarray[ret].m_sex = sex;
					break;
				}
				else
				{
					cout << "。。。" << endl;
				}
			}
			cout <<"请输入年龄"<<endl;
			int age = 0;
			cin >> age;
			abs->personarray[ret].m_age = age;
			cout << "请输入电话号码" << endl;
			string phone ;
			cin >> phone;
			abs->personarray[ret].m_phone = phone;
			cout << "请输入地址" << endl;
			string address;
			cin >> address;
			abs->personarray[ret].m_address = address;
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
		
		system("pause");
		system("cls");
		
}
int main()
{
	addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		struct person personarray[MAX];
		showmenu();
		
		cin >> select;
		switch (select)
		{
		case 1: //添加联系人
			addperson(&abs);
			break;
		case 2: //显示联系人
			showperson(&abs);
			break;
		case 3: //删除联系人
		/*{cout << "所以爱会消失对吗？" << endl;
		cout << "请输入你要删除的父亲，你个不孝子！" << endl;
		string dname;
		cin >> dname;

		if (isexist(&abs, dname) == -1)
		{
			cout << "你没有这个父亲呦" << endl;
		}
		else
		{
			cout << "你找到你父亲啦！" << endl;
		}
		system("pause");
		system("cls");
		break;
		}*/
			deleteperson (&abs);
			break;
		case 4: //查找联系人
			findperson (&abs);
		/*{
			int i = 0;
			cout << "请输入姓名" << endl;
			string bname;
			cin >> bname;
			isexist(&abs, bname);
			if (isexist(&abs, bname) == -1)
			{
				cout << "你没有这个父亲呦" << endl;
			}
			if (isexist(&abs,bname) == i )
			{
				cout << personarray[i].name << endl;
				cout << "你找到你父亲啦！" << endl;
			}
			system("pause");
			system("cls");
		}*/
			break;
		case 5: //修改联系人
			modifyperson (&abs);
			break;
		case 6: //清空联系人
			cleanperson (&abs);
			break;
		case 0: //退出通讯录
			cout << "滚吧儿子" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}