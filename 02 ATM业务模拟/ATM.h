#ifndef ATM_H
#define ATM_H
#include <string>
#include <iostream>
#include <fstream>
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
	friend int test_id(ATM*);			//id�Ƿ���Ч
	friend bool test_code(ATM);			//code�Ƿ���ȷ

	string get_name() { return name; }
	int get_id() { return id; }
	int get_code() { return code; }
	double get_money() { return money; }

	void set_name(string na) { name = na; }
	void set_id(int ID) { id = ID; }
	void set_code(int co) { code = co; }
	void set_money(double mon) { money = mon; }
};
void show_menu();				//��ʾ�˵�
int choose_menu();				//ѡ��˵�ѡ��
int test_id(ATM*);				//id�Ƿ���Ч
bool test_code(ATM);			//code�Ƿ���ȷ
ATM* readAccount();				//��ȡ�û���Ϣ
void handleBusiness(ATM*,int,bool);//�������
void writeAccount(ATM*);			//д���ļ�

//void read_information();			//�õ�txt�ļ�����
//void write_information();			//д��txt�ļ�����
#endif