#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		int num1 = rand() % 69+10;
		int num2 = rand() % 20+10;
		cout << num1 << " £«/-/¡Á/¡Â " << num2 << " = " << endl;
	}
	system("pause"); return 0;
}