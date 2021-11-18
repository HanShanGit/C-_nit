#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class ATM
{
protected:
	string name;
	int id;
	int code;
	double money;
public:
	void check_balance();		//显示余额
	void withdraw();			//取钱
	void deposit();				//存钱
	void exit();				//退出程序
	friend int test_id(ATM*);				//id是否有效
	friend bool test_code(ATM);			//code是否正确
	double get_money() { return money; }
	ATM(const string na,int i,int co,double mon	):name(na),id(i),code(co),money(mon){ }
	ATM(){ }
};

int main()
{
	ATM a1("李顺", 3210, 1922, 9320);
	ATM a2("庄户", 3292, 9832, 2903);
	ATM a3("纪设", 3829, 8329, 2345);
	ofstream Ofile("ATM_TEST.txt", ios::out);
	if(!Ofile)
	{
		cerr << "创建失败\n";
		abort();
	}
	Ofile.write((char*)&a1, sizeof(a1));
	Ofile.write((char*)&a2, sizeof(a2));
	Ofile.write((char*)&a3, sizeof(a3));
	Ofile.close();

	ifstream Ifile("ATM_TEST.txt",ios::binary|ios::in);
	if(!Ifile)
	{
		cerr << "打开失败\n";
		exit(1);
	}
	ATM acc[3];
	for (int i = 0; i < 3; i++)
		Ifile.read((char*)&acc[i], sizeof(acc[i]));

	Ifile.close();
	system("pause"); return 0;
}