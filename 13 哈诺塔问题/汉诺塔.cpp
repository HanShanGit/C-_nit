#include <iostream> //��A��C
using namespace std;
int n;
void ready() { cout << "�����뺺ŵ���߶�:"; cin >> n; cout << "Ĭ�ϴ�A�ƶ���C" << endl; }

void move_recursion(int n, char des, char now, char temp) {
	if (n == 1) { cout << 1 << "->" << des << endl; return; }
	move_recursion(n - 1, temp, now, des);
	cout << n << "->" << des << endl;
	move_recursion(n - 1, des, temp, now);

}
void move_iterate(int n, char des, char now, char temp) {
	char inorder[2][4] = { '0',temp,des,now,'0',des,now,temp };
	int i, j, k;
	char* np = new char[n + 1];
	for (int i = 0; i < n + 1; i++)np[i] = 'A';

	for (i = 1; i < (1 << n); i++) {
		for (j = i, k = 1; j % 2 == 0; k++, j /= 2);
		cout << k << " " << np[k] << "->";
		np[k] = inorder[(1 + n + k) % 2][np[k] - 'A' + 1];
		cout << np[k] << endl;
	}
}
int main() {
	while (1) { ready(); move_iterate(n, 'C', 'A', 'B'); }
}

/*#include <iostream>
using namespace std;
int step = 0;
void Hanoi(int n, char A, char B, char C)
{
	step++;
	if (n == 1)
		printf("Move sheet %d from %c to %c\n", n, A, C);
	else
	{
		Hanoi(n - 1, A, C, B);
		printf("Move sheet %d from %c to %c\n", n, A, C);
		Hanoi(n - 1, B, A, C);
	}
}

int main(int argc, char* argv[])
{
	int n;
	printf("���������������� ");
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');

	printf("�ܹ��ƶ����� %d\n", step);

	getchar();
	system("pause");
	return 0;
}*/



/*const int discCount=11;//�������
void move(int n, char A, char B,char C);//��������
int main()
{ 
	move(discCount,'A','B','C');
	return 0;
}
void move(int n, char A, char B,char C)//�Զ��庯��
{
	if(n==0)//����Ϊ0��ʱ�򷵻�
	{
		return;
	}
	else
	{
		move(n-1,A,C,B);//�ȴ�A��B
		cout<<A<<"-->"<<C<<endl;//�ٴ�A��C
		move(n-1,B,A,C);//����B��C
		return;
	}

}
*/