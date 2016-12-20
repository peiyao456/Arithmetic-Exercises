//查找一个数组的第K小的数，注意同样大小算一样大。 如  2 1 3 4 5 2 第三小数为3。

#include<iostream>
using namespace std;
#include<algorithm>

int GetK(int a[],int size,int k)
{
	sort(a,a+size);
    unique(a,a+size);//除去相邻的重复的元素，但是区间里的元素的个数并不会改变，只是会产生一些残余数据
	return a[k-1];
}
int main()
{
	int n = 0;
	int k = 0;
	while(cin>>n)
	{
        int a[n];
		for(int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		cin>>k;
		int ret = GetK(a,n,k);
		cout<<ret<<endl;
	}
	return 0;
}