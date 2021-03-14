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
	cout << "*�������Ҷ�***** 1�������ϵ�� *****�������Ҷ�*" << endl;
	cout << "*�������Ҷ�***** 2����ʾ��ϵ�� *****�������Ҷ�*" << endl;
	cout << "*�������Ҷ�***** 3��ɾ����ϵ�� *****�������Ҷ�*" << endl;
	cout << "*�������Ҷ�***** 4��������ϵ�� *****�������Ҷ�*" << endl;
	cout << "*�������Ҷ�***** 5���޸���ϵ�� *****�������Ҷ�*" << endl;
	cout << "*�������Ҷ�***** 6�������ϵ�� *****�������Ҷ�*" << endl;
	cout << "*�������Ҷ�***** 0���˳�ͨѶ¼ *****�������Ҷ�*" << endl;
	cout << "***********************************************" << endl;
}

void cleanperson(addressbooks*abs)
{
	cout << "���꣬ǰ�����ǵ�����" << endl;
	cout << "�����Ҫ�����"<<endl;
	cout << "����밴1"<<endl;
	cout << "������밴������"<<endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		abs->m_size = 0;
		cout << "����ʧ��" << endl;
	}

	system("pause");
	system("cls");
	
}
void addperson(addressbooks * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "�����ӣ�����"<<endl;
		
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		cout << "3---����" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2 || sex == 3)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�㻹��Ҫɶ�Ա�" << endl;
		}
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >>address;
		abs->personarray[abs->m_size].m_address = address;
		cout << "��ϲ��ɹ�����һλ���ף�" << endl;
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
	cout << "��������Ҫɾ���ĸ�������" << endl;
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
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "��û���������" << endl;
	}
	system("pause");
	system("cls");
	
}
void showperson(addressbooks*abs)
{
	
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personarray[i].m_name << "\t";
			if (abs->personarray[i].m_sex == 1)
			{
				cout << "�Ա���" << "\t";
			}
			if (abs->personarray[i].m_sex == 2)
			{
				cout << "�Ա�Ů" << "\t";
			}
			if (abs->personarray[i].m_sex == 3)
			{
				cout << "�Ա�����" << "\t";
			}
			cout << "���䣺" << abs->personarray[i].m_age << "\t";
			cout << "�绰��" << abs->personarray[i].m_phone << "\t";
			cout << "סַ��" << abs->personarray[i].m_address << endl;
		}
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks*abs)
{
	cout << "��������Ҫ���ҵĸ���" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
		if (ret != -1)
		{
			cout << "������" << abs->personarray[ret].m_name << "\t";
			cout << "�Ա�" << abs->personarray[ret].m_sex << "\t";
			cout << "���䣺" << abs->personarray[ret].m_age << "\t";
			cout << "�绰��" << abs->personarray[ret].m_phone << "\t";
			cout << "סַ��" << abs->personarray[ret].m_address << endl;
		}
		else
		{
			cout << "��û���������" << endl;
		}
		system("pause");
		system("cls");
}
void modifyperson(addressbooks*abs)
{
	cout << "����Ҫ���ĵĸ���" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	
	
		if (ret != -1)
		{
			string name;
			cout << "����������" << endl;
			cin >> name;
			abs->personarray[ret].m_name = name;
			int sex = 0;
			cout << "�������Ա�" << endl;
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
					cout << "������" << endl;
				}
			}
			cout <<"����������"<<endl;
			int age = 0;
			cin >> age;
			abs->personarray[ret].m_age = age;
			cout << "������绰����" << endl;
			string phone ;
			cin >> phone;
			abs->personarray[ret].m_phone = phone;
			cout << "�������ַ" << endl;
			string address;
			cin >> address;
			abs->personarray[ret].m_address = address;
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "���޴���" << endl;
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
		case 1: //�����ϵ��
			addperson(&abs);
			break;
		case 2: //��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3: //ɾ����ϵ��
		/*{cout << "���԰�����ʧ����" << endl;
		cout << "��������Ҫɾ���ĸ��ף������Т�ӣ�" << endl;
		string dname;
		cin >> dname;

		if (isexist(&abs, dname) == -1)
		{
			cout << "��û�����������" << endl;
		}
		else
		{
			cout << "���ҵ��㸸������" << endl;
		}
		system("pause");
		system("cls");
		break;
		}*/
			deleteperson (&abs);
			break;
		case 4: //������ϵ��
			findperson (&abs);
		/*{
			int i = 0;
			cout << "����������" << endl;
			string bname;
			cin >> bname;
			isexist(&abs, bname);
			if (isexist(&abs, bname) == -1)
			{
				cout << "��û�����������" << endl;
			}
			if (isexist(&abs,bname) == i )
			{
				cout << personarray[i].name << endl;
				cout << "���ҵ��㸸������" << endl;
			}
			system("pause");
			system("cls");
		}*/
			break;
		case 5: //�޸���ϵ��
			modifyperson (&abs);
			break;
		case 6: //�����ϵ��
			cleanperson (&abs);
			break;
		case 0: //�˳�ͨѶ¼
			cout << "���ɶ���" << endl;
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