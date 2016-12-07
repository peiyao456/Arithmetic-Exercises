//在升序的数组中，查找和为给定值的两个数
#include<iostream>
using namespace std;
#include<assert.h>

pair<int,int> FindTwoNumbersWithSum(int a[],int len,int s)
{
	assert(a);
	int head = 0;
	int last = len - 1;
	while(head < last)
	{
		if(a[head] + a[last] == s)
			return pair<int,int>(a[head],a[last]);
		if(a[head] + a[last] > s)
		{
			--last;
		}
		if(a[head] + a[last] < s)
		{
			++head;
		}
	}
}

void Test()
{
	int a[] = {1,2,4,7,11,15};
	pair<int,int> ret = FindTwoNumbersWithSum(a,6,15);
	cout<<ret.first<<" "<<ret.second<<endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}