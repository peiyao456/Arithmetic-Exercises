//题目描述：一只青蛙一次可以跳上一级台阶，也可以跳上2级台阶。求青蛙跳上一个n级的台阶总共有
//多少种跳法
//经过分析：我们知道f(n) = f(n-1)+f(n-2)就可以解决这个青蛙跳台阶问题，类似于斐波那契数列。
#include<iostream>
using namespace std;
#include<assert.h>
#include<math.h>
//递归方法略去，这里仅给出非递归
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

//假设青蛙一次可以跳上 1级台阶，2级台阶，....,n级台阶。求青蛙跳上n级台阶需要多少步。
//分析：Fib(n) = Fib(n-1)+Fib(n-2)+...+Fib(n-n) = Fib(0)+Fib(1)+...+Fib(n-1)
//Fib(n-1) = Fib(0)+Fib(1)+Fib(2)+...+Fib(n-2)
//两式做差：Fib(n)-Fib(n-1) = Fib(n-1)  --->  Fib(n) = 2*Fib(n-1)
//上式整理成非递归：Fib(n) = 2^(n-1)
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