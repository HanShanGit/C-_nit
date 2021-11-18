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
	void check_balance();		//��ʾ���
	void withdraw();			//ȡǮ
	void deposit();				//��Ǯ
	void exit();				//�˳�����
	friend int test_id(ATM*);				//id�Ƿ���Ч
	friend bool test_code(ATM);			//code�Ƿ���ȷ
	double get_money() { return money; }
	ATM(const string na,int i,int co,double mon	):name(na),id(i),code(co),money(mon){ }
	ATM(){ }
};

int main()
{
	ATM a1("��˳", 3210, 1922, 9320);
	ATM a2("ׯ��", 3292, 9832, 2903);
	ATM a3("����", 3829, 8329, 2345);
	ofstream Ofile("ATM_TEST.txt", ios::out);
	if(!Ofile)
	{
		cerr << "����ʧ��\n";
		abort();
	}
	Ofile.write((char*)&a1, sizeof(a1));
	Ofile.write((char*)&a2, sizeof(a2));
	Ofile.write((char*)&a3, sizeof(a3));
	Ofile.close();

	ifstream Ifile("ATM_TEST.txt",ios::binary|ios::in);
	if(!Ifile)
	{
		cerr << "��ʧ��\n";
		exit(1);
	}
	ATM acc[3];
	for (int i = 0; i < 3; i++)
		Ifile.read((char*)&acc[i], sizeof(acc[i]));

	Ifile.close();
	system("pause"); return 0;
}