#include <iostream>
using namespace std;
void showUS(const int);
void showCH(const int);
string turn(const string);

int main()
{
	cout << "Enter the amount: ";
	int money;	cin >> money;
	showUS(money);
	showCH(money);
	system("pause");
	return 0;
}

void showUS(const int money)
{
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
	cout << "American value:	";
	cout << s << endl;
}

void showCH(const int money)
{
	string s;	
	int TEM = money;
	while (TEM)
	{
		int tem = TEM % 10;
		TEM /= 10;
		char ch = '0' + tem;
		s = ch + s;
	}

	int sizeOfNumber = s.size();
	string number;	
	string temNum_1;	
	string temNum_2;	
	string temNum_3;

	if (sizeOfNumber > 8)
	{
		int tem = sizeOfNumber - 8;

		for (int i = 0; i < tem; i++)
			temNum_1 = temNum_1 + s[i];
		number = turn(temNum_1) + "亿";

		for (int i = tem; i < tem+4; i++)
			temNum_2 = temNum_2 + s[i];
		number += turn(temNum_2) + "万";

		for (int i = tem+4; i < sizeOfNumber; i++)
			temNum_3 = temNum_3 + s[i];
	}

	else if (sizeOfNumber > 4)
	{
		int tem = sizeOfNumber - 4;

		for (int i = 0; i < tem; i++)
			temNum_1 = temNum_1 + s[i];
		number += turn(temNum_1) + "万";

		for (int i = tem; i < sizeOfNumber; i++)
			temNum_3 = temNum_3 + s[i];
	}
	else
		for (int i = 0; i < sizeOfNumber; i++)
			temNum_3 = temNum_3 + s[i];

	number += turn(temNum_3) + "圆整";
	cout << "大写数字: " << number << endl;
}

string turn(const string tem)
{
	int size = tem.size();
	if (size > 4)
	{
		cout << "数据有误,无法运行\n";
		exit(1);
	}
	string number;
	string count[] = { "","拾","佰","仟" };
	string NUMBER[] = { "","壹","贰","叁","肆","伍","陆","柒","捌","玖" };

	if (size == 2)
	{
		for (int i = size - 1, j = 0; i >= 0 ; i--, j++)
		{
			int index = tem[i] - '0';
			if (index==1)
				number = count[j] + number;
			else
				number = NUMBER[index] + count[j] + number;
		}
		return number;
	}

	for (int i = size - 1, j = 0; i >= 0; i--, j++)
	{
		int index = tem[i] - '0';
		if (index)
			number = NUMBER[index] + count[j] + number;
		if (index == 0 && i != size - 1)
			number = "零" + number;
	}

	return number;
}