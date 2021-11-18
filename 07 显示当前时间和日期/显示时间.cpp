/*#include <stdlib.h>
using namespace std;

void main()
{
   system("time");
}*/

/*#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	int totalSeconds = time(0);
	int currentSecond = totalSeconds % 60;
	int totalMinutes = totalSeconds / 60;

	//字母错误，影响整个程序！！
	int currentMinute = totalMinutes % 60;
	int totalHours = totalMinutes / 60;
	int currentHour = totalHours % 24;
	cout << "Current time is " << currentHour << " : " << currentMinute << " : " << currentSecond << " GMT " << endl;
	system("pause");
}*/

/**/#include <windows.h>
#include <stdio.h> 
using namespace std;

int main()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", 
		sys.wYear, sys.wMonth, sys.wDay, 
		sys.wHour, sys.wMinute, sys.wSecond, 
		sys.wMilliseconds, sys.wDayOfWeek);
	system("pause"); return 0;
}
//6228482469601671378