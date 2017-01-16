//N阶楼梯上楼问题：一次可以走两阶或一阶，
//问有多少种上楼方式。（要求采用非递归） 

#include<iostream>
using namespace std;

long long Count(int n)
{
	if(n == 1 || n==2)
		return n;
	long long first = 1;
	long long second = 1;
	long long third = 2;
	while(n >= 2)
	{
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}
int main()
{
	int n = 0;
	while(cin>>n)
	{
		long long ret = Count(n);
		cout<<ret<<endl;
	}
	return 0;
}