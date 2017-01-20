//输入一个正整数的数组，把数组里的所有数字拼接起来排成一个数，
//打印能拼接出的所有数字中最小的一个。并给出算法的证明。
//比如输入数组，{3，32，321}，则打印出这3个数字能排出的最小的数字是321323.

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
bool Compare(const string& str1,const string& str2)
{
    string s1 = str1+str2;
    string s2 = str2+str1;
    return s1<s2;
}
void GetMin(int arr[],int n)
{
    string* pArr = new string[n];//定义string数组，存储每个数字对应的字符串
    for(int i = 0; i < n; ++i)
    {
       char buffer[10];
       _itoa(arr[i],buffer,10);
       pArr[i] = buffer;
    }
    sort(pArr,pArr+n,Compare);
    for(int i = 0; i < n; ++i)
    {
       cout<<pArr[i];
    }
    cout<<endl;
}
int main()
{
    //int arr[] = {32,321,1};
    int arr[] = {3,32,321};
    GetMin(arr,sizeof(arr)/sizeof(arr[0]));
    system("pause");
    return 0;
}

