

/*
* #include <iostream>
#include <fstream>
using namespace std;

double hx(double x) { return 2.038 + 1.74 * x; }

int main()
{
	double x[5], y[5];
	ifstream ifile("min.txt", ios::in);
	for (int i = 0; i < 5; i++)
	{
		ifile >> x[i];
	}
	for (int j = 0; j < 5; j++)
		ifile >> y[j];

	double sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0;
	double xy = 0, x2y = 0, sumy = 0;
	double Q = 0;
	for (int i = 0; i < 5; i++)
	{
		sumx += x[i];	sumx2 += pow(x[i], 2);	sumx3 += pow(x[i], 3); sumx4 += pow(x[i], 4);	sumy += y[i];
		xy += x[i] * y[i];	x2y += x[i] * x[i] * y[i];
		Q += pow((hx(x[i]) - y[i]), 2);
	}

	ifile.close();
	ofstream ofile("resunlt.txt", ios::out);
	ofile << "x: " << sumx << "\n";
	ofile << "sumy: " << sumy << "\n";
	ofile << "x2: " << sumx2 << '\n';
	ofile << "x3: " << sumx3 << '\n';
	ofile << "x4: " << sumx4 << '\n';
	ofile << "xy: " << xy << '\n';
	ofile << "x2y: " << x2y << "\n";
	ofile << "Q: " << Q << "\n";

	ofile.close();
	return 0;
}
*/

/*struct Student
{
	int ID;
	string name;
};
int main()
{
	ifstream ifile("struct.txt");
	if (!ifile)
	{
		cerr << "��ʧ��\n";
		exit(1);
	}
	//Student Stu[5];
	int count = 0;
	for (int i = 0; !ifile.eof(); i++)
	{
		int id;
		ifile >> id;
		//Stu[i].ID = id;
		string na;
		ifile >> na;
		count++;
		//Stu[i].name = na;
	}
	cout << "The result is : " << count << endl;
	ifile.close();
	//for (int i = 0; i < 5; i++)
		//cout << Stu[i].ID << " " << Stu[i].name << endl;
	system("pause"); return 0;
}*/


/*#include <iostream>
#include <string>
using namespace std;

void TEST(string& s)
{
	s = s + "_______";
}

int main()
{
	string word("Fantastic");
	cout << word << endl;
	cout << "--------\n";
	TEST(word);
	cout << word << endl;
	system("pause"); return 0;
}
*/

//��C++������� 257-7.15 �����״̬
/*//2020-07-27
#include <iostream>
using namespace std;

int main()
{
	//��Ϊtrue���ر�Ϊfalse
	const int N = 100;
	bool box[N] = { false };
	//���ú���״̬
	for (int i = 1; i <= N; i++)
		for (int j = i; j < N; )
		{
			box[j - 1] = !box[j - 1];
			j = j + i;
		}
	cout << "�򿪺��ӵ����: \n";
	for (int i = 0; i < N; i++)
		if (box[i])
		{
			cout << i + 1 << ' ';
			if ((i + 1) % 5 == 0)
				cout << endl;
		}
	cout << endl;
	system("pause");
	return 0;
}*/

//��ʵ���˸е�������ô�����������
//{}����s[]{}()if (index<=<=
//index <=

//����������̵ļ���Ĥ������ǲ��ҹ�ά����̫Ʋ��һЩ�ɡ�
//��C++������ơ�256-7.12 �����������ʱ�� (Can't)
/*
//2020-07-27
#include <iostream>
#include <ctime>
using namespace std;

int linearSearch(const int list[], int key, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (key == list[i])
			return i;
	}
	return -1;
}

void main()
{
	const int N = 100000;
	int list[N];
	srand(time(0));
	for (int i = 0; i < N; i++)
		list[i] = rand() % 20;
	linearSearch(list, 5, N);
	long startTime = time(0);
	//perform the task;
	long endTime = time(0);
	long executionTime = endTime - startTime;
	cout << "����ʱ�䣺";
	cout << executionTime << endl;
	system("pause");
}*/
