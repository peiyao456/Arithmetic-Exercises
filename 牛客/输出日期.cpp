//给出年分m和一年中的第n天，算出第n天是几月几号
//输出格式要求：yyyy-mm-dd

#include<iostream>
using namespace std;

bool IsLeap(int y)
{
	return ((y % 4 == 0 && y %100 != 0) || (y % 400 == 0));
}
void GetDate(int m,int n)
{
	bool isLeap = IsLeap(m);
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	days[2] += isLeap;
	int i = 0;
	for(i = 1; i < 12; ++i)
	{
		n -= days[i];
		if(n <= days[i + 1])
			break;
	}
	if(n <= 0)
	{
		i = 0;
		n += days[1];
	}
		
	cout<<m << "-";
	printf("%02d",i + 1);
	cout<<"-";
	printf("%02d\n",n);
}
int main()
{
	int m = 0;
	int n = 0;
	while(cin >>m >>n)
		GetDate(m,n);
	return 0;
}