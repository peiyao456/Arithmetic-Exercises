//输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。

#include<iostream>
using namespace std;
#include <algorithm>
#include<vector>

void GetAndSort(int n)
{
	vector<int> v;
	int tmp = 0;
	int m = n;
	while(m--)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	cout<<v[n-1]<<endl;
    v.pop_back();
	if(v.empty())
	{
		cout<<"-1"<<endl;
		return;
	}
	for(int i = 0; i < n-1; ++i)
	{
		cout<<v[i];
		if(i < n-2)
			cout<<" ";
	}
	cout<<endl;
}
int main()
{
	int n = 0;
	while(cin >> n)
	{
		GetAndSort(n);
	}
	return 0;
}