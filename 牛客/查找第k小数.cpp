//����һ������ĵ�KС������ע��ͬ����С��һ���� ��  2 1 3 4 5 2 ����С��Ϊ3��

#include<iostream>
using namespace std;
#include<algorithm>

int GetK(int a[],int size,int k)
{
	sort(a,a+size);
    unique(a,a+size);//��ȥ���ڵ��ظ���Ԫ�أ������������Ԫ�صĸ���������ı䣬ֻ�ǻ����һЩ��������
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