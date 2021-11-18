#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void guess(const string);
void guessNext(char, const string, int, string&, int&);

int main()
{
	string word[] = { "ambious","winner","lover","consious","grand","humble","immense",
		"imperial","bucker","compress","consolidate","contest","ethnic","exile",};
	srand(time(0));
	char answer = 'y';
	while (answer == 'y')
	{
		int index = rand() % 8;
		guess(word[index]);
		cout << "Do you want to guess for another word ? Enter y or n > ";
		cin >> answer;
	}
	system("pause"); return 0;
}

//将需要函数声明写在主函数之前，实现在主函数之后
void guess(const string word)
{
	int lenth = word.length();
	string tem;
	for (int i = 0; i < lenth; i++)
		tem += '*';

	cout << "(Guess) Enter a letter in word ";
	cout << tem << " > ";
	char ch; cin >> ch;
	bool goOn = true;
	int count = 0;
	while (goOn)
	{
		goOn = false;
		guessNext(ch, word, lenth, tem, count);
		for (int i = 0; i < lenth; i++)
			if (tem[i] == '*')
				goOn = true;
		//刷新流存储空间
		cin.clear();
		if (goOn)
		{
			cout << "(Guess) Enter a letter in word " << tem << " > ";
			cin >> ch;
		}
	}
	cout << "The word is " << word << ". You missed " << count << " time\n\n\n";
}

void guessNext(char ch, const string word, int lenth, string& tem, int& count)
{
	bool next = true;
	for (int i = 0; i < lenth; i++)
		if (tem[i] == ch)
			next = false;

	bool exit = false;
	if (next)
	{
		for (int i = 0; i < lenth; i++)
			if (word[i] == ch)
			{
				tem[i] = ch;
				exit = true;
			}
	}
	else
	{
		cout << "\t" << ch << " is already in the word\n";
		return;
	}

	if (!exit)
	{
		cout << "\t" << ch << " is not in the word\n";
		count++;
	}
}
