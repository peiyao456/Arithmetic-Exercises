//����һ������N�����1~N��N��������ʮ���Ʊ�ʾ��ʽ��
// 1���ֵĴ�������������12����1~12��12�������а���1������
//�У�1��10��11��12��1�ܹ�������5 �Ρ�
#include<iostream>
using namespace std;
#include<cassert>
//1~N��ʮ���Ʊ�ʾ�г��ֵĴ���
int Power(int n)
{
    int result = 1;
    for(int i = 0; i < n; ++i)
    {
       result *= 10;
    }
    return result;
}
int numberOf1(const char* str)
{
    if(*str < '0'|| *str > '9' || *str == '\0' || str == NULL)//�ַ�������ȷ������˵����������
       return 0;
    int length = strlen(str);
    int first = *str - '0';
    if(first == 0 && length == 1)//�����������
       return 0;
    if(first > 0 && length == 1)//����N�Ǹ�λ�������
       return 1;
    //������������� 24531  ���ַ�Ϊ������ 1~4531 ��4532 ~ 24531
    //1,2�������~ 24531�еĸ���
    //3�������1~ 4531�еĸ���
    //1.����~19999�г��ֵĴ���
    int CountFirstDigit = 0;
    if(first > 1)
       CountFirstDigit = Power(length-1);
    if(first == 1)
       CountFirstDigit = atoi(str+1)+1;
    //2.�������λ�г��ֵĴ���
    int CountOtherDigits = first * (length -1) * Power(length - 2);
    //3.����1~4531�г��ֵĸ���
    int CountRest = numberOf1(str + 1);
    return CountFirstDigit+ CountOtherDigits + CountRest;
}
int GetCount(int n)
{
    if(n <= 0)
       return 0;
    char str[15];
    _itoa(n,str,10);//�����������תΪ�ַ�����Ϊ�˷����д����
    return numberOf1(str);
}
int main()
{
    int n = 0;
    cin>>n;
    cout<<GetCount(n)<<endl;
    system("pause");
    return 0;
}
