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
	void check_balance();		//显示余额
	void withdraw();			//取钱
	void deposit();				//存钱
	void exit();				//退出程序
	friend int test_id(ATM*);			//id是否有效
	friend bool test_code(ATM);			//code是否正确

	string get_name() { return name; }
	int get_id() { return id; }
	int get_code() { return code; }
	double get_money() { return money; }

	void set_name(string na) { name = na; }
	void set_id(int ID) { id = ID; }
	void set_code(int co) { code = co; }
	void set_money(double mon) { money = mon; }
};
void show_menu();				//显示菜单
int choose_menu();				//选择菜单选项
int test_id(ATM*);				//id是否有效
bool test_code(ATM);			//code是否正确
ATM* readAccount();				//读取用户信息
void handleBusiness(ATM*,int,bool);//具体操作
void writeAccount(ATM*);			//写入文件

//void read_information();			//得到txt文件内容
//void write_information();			//写入txt文件内容
#endif