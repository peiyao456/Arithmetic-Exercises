//输入一个字符串，然后对每个字符进行奇校验，最后输出校验后的二进制数(如'3’，输出：10110011)。
#include<iostream>
using namespace std;
#include<string>
#include<math.h>
int Count(unsigned char c)//求一个字符中1的个数
{
	int count = 0;
	while(c)
	{
		count ++;
		c = c & (c - 1);
	}
	return count;
}
void PrintByBinary(unsigned char c)
{
	int tmp = 0;
	for(int i = 0; i < 8; ++i)
	{
		tmp = c / (int)pow((float)2.0,7-i);
		cout<<tmp;
		c = c % (int)pow((float)2.0,7-i);
	}
	cout<<endl;
}
void Odd(string s)
{
	for(int i = 0; i < s.size(); ++i)
	{
		if(Count(s[i]) % 2 == 0)//偶数
			s[i] += 128;
		PrintByBinary(s[i]);
	}
}
int main()
{
	string str;
	while(cin >> str )
	{
		Odd(str);
	}
	return 0;
}