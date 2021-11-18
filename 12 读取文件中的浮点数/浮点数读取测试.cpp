#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void print(double*, int);
void print(int*, int);

int main()
{
	ifstream ifile("double.txt");		
	if (!ifile)
	{
		cerr << "��ʧ��\n";
		exit(1);
	}
	double D[7];
	double T[7];
	for (int i = 0; !ifile.eof(); i++)//ifile.eof();���������á�ԭ����̽����--2020.08.20  �������ӣ��ķ񶨲�����ȷ����
	{
		ifile >> D[i];
		T[i] = log(D[i]);
	}
	cout << "r:\t";
	print(D, 7);
	cout << "lnr:\t";
	print(T, 7);
	ifile.close();
}

void print(double* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}