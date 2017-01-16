#include<iostream>
using namespace std;

void ScanString(char*& str)
{
	while(*str != '\0' && *str >= '0' && *str <= '9')
	{
		++str;//直到找到一个不是数字或者结束符的字符
	}
}

bool IsExponential(char*& str)
{
	if(*str != 'e' && *str != 'E')
		return false;
	++str;
	if(*str == '+' || *str == '-')
		++str;
	if(*str == '\0')
		return false;//在指数部分只出现了正负号
	ScanString(str);

	return *str == '\0';//如果*str不是\0，说明，指数部分还有其他的字符，并不是数字
}
bool IsNumeric(char* str)
{
	if(str == NULL)
		return false;
	if(*str == '+' || *str == '-')
		++str;
	if(*str == '\0')  //字符串中只出现了正负号
		return false;
	if(*str != '\0' &&(( *str >= '0' && *str  <= '9') ||( *str  == 'e'|| *str  == 'E')))
	{
		ScanString(str);
	}
	else
		return false;


	bool flag = true;

	if(*str != '\0')
	{
		if(*str == '.')
		{
			++str;
			ScanString(str);
			if(*str == 'e'|| *str =='E')
				flag = IsExponential(str);//检查 是否是标准的科学计数法
		}
		else if(*str == 'e' || *str == 'E')
			flag = IsExponential(str);
		else
			flag = false;
	}

}
int main()
{
	cout<<IsNumeric("1e34")<<endl;//1
	cout<<IsNumeric("1e")<<endl;//0
	cout<<IsNumeric("12e3.4")<<endl;//0
	cout<<IsNumeric(".e3")<<endl;//0
	system("pause");
	return 0;
}