//题目描述：对给定的一个字符串，找出有重复的字符，并给出其位置，
//如：abcaaAB12ab12 输出：a，1；a，4；a，5；a，10，b，2；
//b，11，1，8；1，12， 2，9；2，13。

#include<iostream>
using namespace std;
#include<string>

void GetPos(string s)
{
	bool first = false;
	for(int i = 0; i < s.size()-1; ++i)
	{
		if(s[i] == '#')//对于已经输出过的值，就不需要循环了
			continue;
		first = false;
		for(int j = i + 1; j < s.size(); ++j)
		{
			if(s[j] == s[i])
			{
				if(!first)//对于s[i]，只需要打印一次，所以之后的多次是不需要打印的
				{
					cout<<s[i]<<":"<<i;
					first = true;
				}
				cout<<","<<s[j]<<":"<<j;
				s[j] = '#';//将已经找到的位置的值做标记，之后就不需要遍历了。
			}
		}
		if(first)
			cout<<endl;
	}
}
int main()
{
	string s;
	while(cin>>s)
	{
		GetPos(s);
	}
	system("pause");
	return 0;
}