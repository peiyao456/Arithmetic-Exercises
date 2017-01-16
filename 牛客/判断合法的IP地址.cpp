//输入一个ip地址串，判断是否合法。 

#include<iostream>
using namespace std;
#include<string>

int StrToInt (string s,int begin,int end)
{
	int num = 0;
	for(int i = begin; i < end; ++i)
	{
		num = num * 10 + (s[i] - '0');
	}
	return num;
}

bool VaildNum(int num)
{
	if(num >= 0 && num <= 255)
		return true;
	else
		return false;
}
bool IsVaild(string s)
{
	if(s.size() > 15)
		return false;

	int index1=s.find('.',0);
	int index2=s.find('.',index1+1);//从index + 1位置开始查找 ‘.'字符，并返回‘.'字符下标
	int index3=s.find('.',index2+1);
	
	int num1 = StrToInt(s,0,index1);
	int num2 = StrToInt(s,index1+1,index2);
	int num3 = StrToInt(s,index2+1,index3);
	int num4 = StrToInt(s,index3+1,s.size());

	if(VaildNum(num1) && VaildNum(num2) && VaildNum(num3) && VaildNum(num4)) 
		return true;
	else
		return false;
}
int main()
{
	int n = 0;
	cin>>n;
	bool ret = 0;
	while(n)
	{
		string str;
		cin>>str;
		ret = IsVaild(str);
		if(ret)
			cout<<"Yes!"<<endl;
		else
			cout<<"No!"<<endl;
		--n;
	}
	return 0;
}