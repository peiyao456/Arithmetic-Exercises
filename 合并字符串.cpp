//给定两个字符串S1和S2，合并成一个新的字符串S。 
//合并规则为，S1的第一个字符为S的第一个字符，将S2的最后一个字符作为S的第二个字符；
//将S1的第二个字符作为S的第三个字符，
//将S2的倒数第二个字符作为S的第四个字符，以此类推。

#include<iostream>
using namespace std;
#include<string>
string MergeString(string s1,string s2)
{
	if(s1.size() != s2.size())
		return string();
	string s;
	for(int i = 0; i < s1.size(); ++i)
	{
		s.push_back(s1[i]);
		s.push_back(s2[s1.size()-i - 1]);
	}
	return s;
}
int main()
{
	string s1,s2,ret;
	while(cin>>s1>>s2)
	{
		ret = MergeString(s1,s2);
		cout<<ret<<endl;
	}
	return 0;
} 