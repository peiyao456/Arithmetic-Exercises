//����20������ÿ��������1-10֮�䣬
//��1-10�е��������������ǳ��ִ�����������
//�������һ��������������������Ȩֵ��С����һ������ 

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