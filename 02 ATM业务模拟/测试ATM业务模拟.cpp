//#include <iostream>
//#include <fstream>
#include "ATM.h"
//using namespace std;

int main()
{
	ATM* acc = readAccount();			//��ȡ��Ϣ
	int index=test_id(acc);				//�ж��˻���Ϣ
	bool go_on = test_code(acc[index]);	//�õ��˻�λ��
	if (go_on == false)	exit(1);		//��������������˳�����
	handleBusiness(acc, index, go_on);	//�������
	writeAccount(acc);					//д���ļ��޸ĺ���Ϣ
	delete[]acc;
	system("pause"); return 0;
}
/*
	ofstream ofile("Account.txt", ios::out);
	for (int i = 0; i < 10; i++)
		ofile.write((char*)&acc[i], sizeof(acc[i]));
	ofile.close();
	*/