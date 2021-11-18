#include <iostream>	
#include <string>
using namespace std;

void main()
{
	int money = 1230010;
	//int tem = static_cast<int>(money) % 10;
	//int count = 0, TEM = static_cast<int>(money) / 10;
	string s;
	int TEM = money, count = 0;
	while (TEM)
	{
		int tem = TEM % 10;
		TEM /= 10;
		char ch = '0' + tem;
		s = ch + s;
		count++;
		if (TEM && count % 3 == 0)
			s = ',' + s;
	}
	cout << s << endl;
	system("pause");
}