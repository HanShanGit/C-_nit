#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	string name = "wuli.txt";
	ifstream ifile(name.c_str());
	if (!ifile)
	{
		cerr << "��ʧ��\n";
		exit(1);
	}

}