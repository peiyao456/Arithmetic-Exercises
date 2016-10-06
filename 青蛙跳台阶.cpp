//��Ŀ������һֻ����һ�ο�������һ��̨�ף�Ҳ��������2��̨�ס�����������һ��n����̨���ܹ���
//����������
//��������������֪��f(n) = f(n-1)+f(n-2)�Ϳ��Խ�����������̨�����⣬������쳲��������С�
#include<iostream>
using namespace std;
#include<assert.h>
#include<math.h>
//�ݹ鷽����ȥ������������ǵݹ�
int Fib1(int n)
{
	assert(n > 0);
	int first = 1;
	int second = 1;
	int third = 1;
	while (n > 2)
	{
		third = first + second;
		first = second;
		second = third;
		--n;
	}
	return third;
}

//��������һ�ο������� 1��̨�ף�2��̨�ף�....,n��̨�ס�����������n��̨����Ҫ���ٲ���
//������Fib(n) = Fib(n-1)+Fib(n-2)+...+Fib(n-n) = Fib(0)+Fib(1)+...+Fib(n-1)
//Fib(n-1) = Fib(0)+Fib(1)+Fib(2)+...+Fib(n-2)
//��ʽ���Fib(n)-Fib(n-1) = Fib(n-1)  --->  Fib(n) = 2*Fib(n-1)
//��ʽ����ɷǵݹ飺Fib(n) = 2^(n-1)
int Fib2(int n)
{
	assert(n>0);
	return pow(2,n-1);
}
int main()
{
	cout << Fib1(8) << endl;
	cout << Fib2(8) << endl;
	system("pause");
	return 0;
}