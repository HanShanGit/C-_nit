#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream i_PI("PI_right_50.txt");
	ifstream o_PI("PI_my_50.txt");
	if (!i_PI || !o_PI)
	{
		cerr << "打开失败\n";
		exit(1);
	}
	cout << "出错字符位置\t正确字符\t输入字符\n";
	int count = 0;
	for (int i = 1; !o_PI.eof(); i++)
	{
		char ich = i_PI.get();
		char och = o_PI.get();
		if (ich != och)
		{
			count++;
			cout << i << "\t\t" << ich << "\t\t" << och << endl;
		}
	}
	cout << "总共错了" << count << "个\n";
	i_PI.close();
	o_PI.close();
	system("pause"); return 0;
}