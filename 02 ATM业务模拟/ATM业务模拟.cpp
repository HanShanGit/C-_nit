//#include <iostream>
//#include <fstream>
#include "ATM.h"
//using namespace std;

void ATM::check_balance()
{
	cout << "账户余额为" ;
	string s;
	int TEM = money, count = 0;
	while (TEM)
	{
		int tem = TEM % 10;
		TEM /= 10;
		char ch = '0' + tem;
		s = ch + s;
		count++;
		if (TEM && count % 3 == 0)
			s = ',' + s;
	}
	cout << s << endl;
	cout << endl;
}

void ATM::withdraw()
{
	cout << "Enter an amount to withdraw: ";
	int x; cin >> x;
	while (x < 0 || x>money)
	{
		cout << "Wrong instruction, try again: ";
		cin >> x;
	}
	money -= x;
	cout << endl << endl;
}

void ATM::deposit()
{
	cout << "Enter an amount to deposit: ";
	int x; cin >> x;
	while (x < 0)
	{
		cout << "Wrong instruction, try again: ";
		cin >> x;
	}
	money += x;
	cout << endl << endl;
}

void ATM::exit()
{
	cout << "正在退出...\n";
}

void show_menu()
{
	cout << "Main menu\n";
	cout << "1: Check balance\n2: Withdraw\n3: Deposit\n4: exit\n";
}

int choose_menu()
{
	cout << "Enter a choice: ";
	int m;	cin >> m;
	while (m < 0 || m>4)
	{
		cout << "Wrong instruction, try again: ";
		cin >> m;
	}
	return m;
}

int test_id(ATM* acc)
{
	cout << "Enter an id: ";
	int id;		cin >> id;
	for (int i = 0; i < 10; i++)
	{
		if (acc[i].id == id)
		{
			return i;
		}
	}
	cout << "Wrong instruction, try again.\n";
	test_id(acc);
}

bool test_code(ATM tem)
{
	cout << "Enter the code: ";
	int code; cin >> code;
	int count = 1;
	while (tem.code != code)
	{
		count++;
		cout << "Wrong instruction, try again: "; cin >> code;
		if (count == 3)
		{
			cout << "错误次数过多，正在退出...\n";
			return false;
		}
	}
	return true;
}

ATM* readAccount()
{
	ifstream File("Account.txt", ios::binary | ios::in);
	if (!File)
	{
		cerr << "系统故障\n";
		exit(1);
	}

	ATM* acc = new ATM[10];
	char tem[100];
	File.getline(tem, 100, '\n');
	for (int i = 0; i < 10; i++)
	{
		string na;		File >> na; 	acc[i].set_name(na);
		int di;			File >> di;		acc[i].set_id(di);
		int co;			File >> co;		acc[i].set_code(co);
		double mon;		File >> mon;	acc[i].set_money(mon);
	}
	File.close();
	return acc;
}

void handleBusiness(ATM*acc,int index,bool go_on)
{
	while (go_on)
	{
		show_menu();
		int num = choose_menu();
		switch (num - 1)
		{
		case 0:acc[index].check_balance(); break;
		case 1:acc[index].withdraw(); break;
		case 2:acc[index].deposit(); break;
		case 3:acc[index].exit(); break;
		}

		if (num == 4)
			go_on = false;
	}
}

void writeAccount(ATM* acc)
{
	ofstream ofile("Copy_Account.txt", ios::out);
	if (!ofile)
	{
		cerr << "创建失败\n";
		exit(1);
	}
	ofile << "人名\t账户\t密码\t余额\n";
	for (int i = 0; i < 10; i++)
	{
		string na = acc[i].get_name();			ofile << na << "\t";
		int di = acc[i].get_id();				ofile << di << "\t";
		int co = acc[i].get_code();				ofile << co << "\t";
		double mon = acc[i].get_money();		ofile << mon << "\n";
	}
	ofile.close();
}