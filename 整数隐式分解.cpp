#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int total = 0;
void Factorization(int n)
{
	if (n == 1)
		total++;
	else
		for (int i = 2; i <= n; ++i)
			if (n % i == 0)
				Factorization(n/i);
}
int main()
{
	int n = 0;
	while (scanf(" %d", &n) != EOF)
	{
		total = 0;
		Factorization(n);
		printf("%d\n", total);
	}
	system("pause");
	return 0;
}