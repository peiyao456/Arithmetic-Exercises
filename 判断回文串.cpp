//����һ�����Ȳ�����1000���ַ������ж����ǲ��ǻ���(˳�����������ͬ)�ġ� 

#include<iostream>
using namespace std;
#include<string>
#include <algorithm>

bool palindrome(string str)
{
	if(str.empty())
		return true;
	string tmp = str;
	reverse(str.begin(),str.end());//��str��������
	return tmp == str;
}
int main()
{
	string str;
	while(cin>>str)
	{
		if(palindrome(str))
		{
			cout<<"Yes!"<<endl;
		}
		else
			cout<<"No!"<<endl;
	}
	return 0;
}