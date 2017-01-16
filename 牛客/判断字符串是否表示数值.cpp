#include<iostream>
using namespace std;

void ScanString(char*& str)
{
	while(*str != '\0' && *str >= '0' && *str <= '9')
	{
		++str;//ֱ���ҵ�һ���������ֻ��߽��������ַ�
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
		return false;//��ָ������ֻ������������
	ScanString(str);

	return *str == '\0';//���*str����\0��˵����ָ�����ֻ����������ַ�������������
}
bool IsNumeric(char* str)
{
	if(str == NULL)
		return false;
	if(*str == '+' || *str == '-')
		++str;
	if(*str == '\0')  //�ַ�����ֻ������������
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
				flag = IsExponential(str);//��� �Ƿ��Ǳ�׼�Ŀ�ѧ������
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