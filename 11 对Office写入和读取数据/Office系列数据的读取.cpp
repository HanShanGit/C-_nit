#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	ifstream inword("TRY.docx");
	if (!inword)
	{
		cerr << "��ʧ��.\n";
		exit(1);
	}
	string tem;
	inword >> tem;
	cout << tem << endl;
	inword.close();
	system("pause");
}

//��wordд���ļ�
/*ofstream oword("TEST.DOCX");
	if (!oword)
	{
		cerr << "����ʧ��\n";
		exit(1);
	}
	string message("How long you ...");
	oword << message;*/