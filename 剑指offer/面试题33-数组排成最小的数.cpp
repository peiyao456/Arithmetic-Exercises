//����һ�������������飬�����������������ƴ�������ų�һ������
//��ӡ��ƴ�ӳ���������������С��һ�����������㷨��֤����
//�����������飬{3��32��321}�����ӡ����3���������ų�����С��������321323.

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
    string* pArr = new string[n];//����string���飬�洢ÿ�����ֶ�Ӧ���ַ���
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

