//����һ������n(2<=n<=10000)��
//Ҫ��������д�1���������֮��(������1���������)��λΪ1��������
//���û�������-1�� 

#include<iostream>
using namespace std;
#include<vector>

bool IsPrim(int m)
{
	for(int i = 2; i < m/2; i++)
	{
		if(m % i == 0)
			return false;
	}
	return true;
}
void PrintPrim(int m)
{
	vector<int> v;
	for(int i = 3; i < m; i += 2)
	{
		if(IsPrim(i) && i % 10 == 1)
			v.push_back(i);
	}
	if(v.empty())
	{
		cout<<"-1"<<endl;
	}
	for(int i = 0; i < v.size(); ++i)
	{
		cout<<v[i];
		if(i < v.size()-1)
			cout<<" ";
	}
	cout<<endl;
}
int main()
{
	int n = 0;
	while(cin>>n)
	{
		PrintPrim(n);
	}
	return 0;
}