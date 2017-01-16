//给出一个长度不超过1000的字符串，判断它是不是回文(顺读，逆读均相同)的。 

#include<iostream>
using namespace std;
#include<string>
#include <algorithm>

bool palindrome(string str)
{
	if(str.empty())
		return true;
	string tmp = str;
	reverse(str.begin(),str.end());//将str进行逆序
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