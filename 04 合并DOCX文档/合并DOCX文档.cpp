#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream ofile("complete.docx",ios::app);
	if (!ofile)
	{
		cerr << "创建complete.docx失败\n";
		exit(1);
	}
	string file("Part_");
	for (int i = 1; i <= 3; i++)
	{
		char ch = '0' + i;
		string name = file + ch + ".docx";
		ifstream ifile(name.c_str());
		if (!ifile)
		{
			cerr << "Part_部分打开失败\n";
			exit(1);
		}
		char CH = ifile.get();
		while (!ifile.eof())
		{
			ofile << CH;
			CH = ifile.get();
		}
		ifile.close();
	}
	ofile.close();
	system("pause"); return 0;
}