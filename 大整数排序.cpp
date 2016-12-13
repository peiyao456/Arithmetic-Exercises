//对N个长度最长可达到1000的数进行排序。

#include<iostream>
using namespace std;
#include<string>
#include <algorithm>
#include<vector>

bool Compare(const string& a,const string& b)
{
	if(a.size() < b.size())
		return true;
	else if(a.size() == b.size())
		return a < b;
	else
		return false;
}
int main()
{
	int n = 1;
	while(cin >> n)
	{
		vector<string> v;
		string tmp;
		int m = n;
		while(m--)
		{
			cin>>tmp;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end(),Compare);
		for(int i = 0; i < n; ++i)
		{
			cout<<v[i]<<endl;
		}
	}
	return 0;
}