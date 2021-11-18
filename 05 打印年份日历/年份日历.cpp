#include <iostream>
#include <iomanip>
using namespace std;

void showTitle(int month,int year)
{
	cout << "\n\t\t";
	switch (month)
	{
	case 1: cout <<"January" << " " << year << endl; break;
	case 2: cout << "February" << " " << year << endl; break;
	case 3: cout << "March" << " " << year << endl; break;
	case 4: cout << "April" << " " << year << endl; break;
	case 5: cout << "May" << " " << year << endl; break;
	case 6: cout << "June" << " " << year << endl; break;
	case 7: cout << "July" << " " << year << endl; break;
	case 8: cout << "August" << " " << year << endl; break;
	case 9: cout << "September" << " " << year << endl; break;
	case 10: cout << "October" << " " << year << endl; break;
	case 11: cout << "Nobember" << " " << year << endl; break;
	case 12: cout << "December" << " " << year << endl; break;
	}
	cout << "---------------------------------------------------\n";
	cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
}

void showBody(int year,int month,int& num)
{
	for (int i = 0; i < (num % 7); i++)
		cout << "\t";
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		for (int i = 1; i <= 31; i++)
		{
			cout << i << "\t";
			num++;
			if (num % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
	else if (month == 2)
	{
		int day = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 29 : 28);
		for (int i = 1; i <= day; i++)
		{
			cout << i << "\t";
			num++;
			if (num % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= 30; i++)
		{
			cout << i << "\t";
			num++;
			if (num % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	cout << "输入年份和这一年的第一天是星期几: ";
	int year, num;
	cin >> year >> num;
	int month = 1;
	while (month <= 12)
	{
		showTitle(month,year);
		showBody(year,month,num);
		month++;
	}
	system("pause"); return 0;
}