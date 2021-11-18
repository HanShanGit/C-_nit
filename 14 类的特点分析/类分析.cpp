#include <iostream>
using namespace std;

class Test
{
//private:
	int data1  ;
	int data2 = 33;
	void show_1() { cout << data1 << endl; }
public:
	void show_2() { cout << data2 << endl; }
	Test(int Da1 = 1, int Da2 = 11): data1(Da1),data2(Da2) { /*data1 = Da1, data2 = Da2;*/ }

};

void main()
{
	int x = 2, y = 22;
	//Test try_1;
	//try_1.show_2();
	//cout << try_1.data1 << endl;
	Test t(x, y);	Test t1;
	t.show_2();		t1.show_2();
	system("pause");
}