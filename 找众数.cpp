//输入20个数，每个数都在1-10之间，
//求1-10中的众数（众数就是出现次数最多的数，
//如果存在一样多次数的众数，则输出权值较小的那一个）。 

#include<iostream>
using namespace std;
#include<map>

int GetNum(int a[],int n)
{
	map<int,int> countMap;
	for(int i = 0; i < n; ++i)
	{
		countMap[a[i]]++;
	}
	map<int,int>::iterator max = countMap.begin();
	map<int,int>::iterator countIt = countMap.begin();
	while(countIt != countMap.end())
	{
		if(countIt->second > max->second)
			max = countIt;
		++countIt;
	}
	return max->first;
}
int main()
{
	int a[20];
	while(cin >> a[0])
	{
		for(int i = 1; i < 20; ++i)
		{
			cin>>a[i];
		}
		int ret = GetNum(a,20);
		cout<<ret<<endl;
	}
	return 0;
}