#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
//扑克牌顺子
bool IsContinuous(vector<int> v)
{
	if (v.size() < 1)
		return false;
	//排序
	sort(v.begin(),v.end());
	//统计出v中0的个数
	int count = 0;
	int index = 0;
	while (v[index] == 0)
	{
		++count;
		++index;
	}
	//计算数据之间的间隔
	int small = index;
	int big = index + 1;
	int diff = 0;
	while (big < v.size())
	{
		if (v[small] == v[big])//有对子出现
			return false;
		//计算间隔
		diff += (v[big] - v[small] - 1);
		small = big;
		++big;
	}
	if (diff == count || diff == 0)
		return true;
	return false;
}
int main()
{
	int arr[5] = { 1,2,3,0,0 };
	vector<int> v(arr,arr+5);
	cout << IsContinuous(v) << endl;
	system("pause");
	return 0;
}
