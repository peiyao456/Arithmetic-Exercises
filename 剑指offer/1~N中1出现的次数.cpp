//输入一个整数N，求出1~N这N个整数的十进制表示形式中
// 1出现的次数。比如输入12，从1~12这12个整数中包含1的数字
//有：1，10，11，12，1总共出现了5 次。
#include<iostream>
using namespace std;
#include<cassert>
//1~N的十进制表示中出现的次数
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
    if(*str < '0'|| *str > '9' || *str == '\0' || str == NULL)//字符串不正确，进而说明数据有误
       return 0;
    int length = strlen(str);
    int first = *str - '0';
    if(first == 0 && length == 1)//处理这种情况
       return 0;
    if(first > 0 && length == 1)//处理N是个位数的情况
       return 1;
    //假如给定的数是 24531  数字分为两部分 1~4531 和4532 ~ 24531
    //1,2计算的是~ 24531中的个数
    //3计算的是1~ 4531中的个数
    //1.计算~19999中出现的次数
    int CountFirstDigit = 0;
    if(first > 1)
       CountFirstDigit = Power(length-1);
    if(first == 1)
       CountFirstDigit = atoi(str+1)+1;
    //2.计算后面位中出现的次数
    int CountOtherDigits = first * (length -1) * Power(length - 2);
    //3.计算1~4531中出现的个数
    int CountRest = numberOf1(str + 1);
    return CountFirstDigit+ CountOtherDigits + CountRest;
}
int GetCount(int n)
{
    if(n <= 0)
       return 0;
    char str[15];
    _itoa(n,str,10);//将输入的数字转为字符串，为了方便编写程序
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
