#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	ifstream inword("TRY.docx");
	if (!inword)
	{
		cerr << "打开失败.\n";
		exit(1);
	}
	string tem;
	inword >> tem;
	cout << tem << endl;
	inword.close();
	system("pause");
}

//向word写入文件
/*ofstream oword("TEST.DOCX");
	if (!oword)
	{
		cerr << "创建失败\n";
		exit(1);
	}
	string message("How long you ...");
	oword << message;*/