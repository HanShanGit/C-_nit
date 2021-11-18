//#include <iostream>
//#include <fstream>
#include "ATM.h"
//using namespace std;

int main()
{
	ATM* acc = readAccount();			//读取信息
	int index=test_id(acc);				//判断账户信息
	bool go_on = test_code(acc[index]);	//得到账户位置
	if (go_on == false)	exit(1);		//密码出错三次则退出程序
	handleBusiness(acc, index, go_on);	//具体操作
	writeAccount(acc);					//写入文件修改后信息
	delete[]acc;
	system("pause"); return 0;
}
/*
	ofstream ofile("Account.txt", ios::out);
	for (int i = 0; i < 10; i++)
		ofile.write((char*)&acc[i], sizeof(acc[i]));
	ofile.close();
	*/