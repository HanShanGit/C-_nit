#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

struct menu 
{
	string name;
	double price;
};

int main()
{
	ifstream ifile("charge.txt", ios::in||ios::binary);
	if (!ifile)
	{
		cerr << "´ò¿ªÊ§°Ü\n";
		exit(1);
	}
	int size;
	ifile >> size;
	menu* combination = new menu[size];
	for (int i = 0; i < size; i++)
	{
		string na; double pri;
		ifile >> na; ifile >> pri;
		combination[i].name = na;
		combination[i].price = pri;
	}
	ifile.close();

	for (int i = 0; i < size; i++)
		cout << combination[i].name << " " << combination[i].price << endl;
	delete[]combination;
	system("pause"); return 0;
}//ifile.read((char*)&combination[i], sizeof(combination[i]));