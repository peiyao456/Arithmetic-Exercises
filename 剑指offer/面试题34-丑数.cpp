//���ǰ�ֻ��������2��3��5������Ϊ���������մ�С�����˳��ĵ�1500��������
//����6��8���ǳ�������14���ǣ���Ϊ14��������7.����ϰ���ϰ�1������һ��������

//����1�����ķ���ʵ�������Ƚ����ף�������������һ�㲻��õ����Թٵ�ϲ������������ֻ������2�з�����ʵ�֡�
//����2��
#include<iostream>
using namespace std;
int Min(int x,int y,int z)
{
    int min = (x < y)?x : y;
    return min < z ? min : z;
}
int GetUglyNumber(int index)
{
    if(index <= 0)
       return 0;
    int* pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int NextUglyNumbers = 1;
    int* pUgly2 = pUglyNumbers;
    int* pUgly3 = pUglyNumbers;
    int* pUgly5 = pUglyNumbers;
    while(NextUglyNumbers < index)
    {
       int min = Min(*pUgly2*2,*pUgly3*3,*pUgly5*5);
       pUglyNumbers[NextUglyNumbers++] = min;
       while(*pUgly2 * 2 <= min)
           pUgly2++;
       while(*pUgly3 * 3 <= min)
           pUgly3++;
       while(*pUgly5 * 5 <= min)
           pUgly5++;
    }
    int ugly = pUglyNumbers[index - 1];
    delete[] pUglyNumbers;
    return ugly;
}
int main()
{
    int index = 0;
    cin>>index;
    cout<<GetUglyNumber(index)<<endl;
    system("pause");
    return 0;
}
//����3��
#include<iostream>
using namespace std;
#include<limits.h>
#include<set>
int GetUglyNumber(int index)
{
    if(index <= 0)
       return 0;
    set<int,less<int>> s;
    set<int,less<int>>::iterator it;
    s.insert(1);
    for(int i = 1; i < index * 6 /*INT_MAX/5*/; ++i)
    {
       s.insert(i * 2);
       s.insert(i * 3);
       s.insert(i * 5);
    }
    int i = 0;
    for(it = s.begin(),i = 1; it != s.end()&&i < index; ++it,++i)
    {}
    cout<<*it<<endl;
}
int main()
{
    int index = 0;
    cin>>index;
    GetUglyNumber(index);
    system("pause");
    return 0;
}
