//我们把只包含因子2，3，5的数称为丑数，求按照从小到大的顺序的第1500个丑数。
//例如6，8都是丑数，但14不是，因为14含有因子7.我们习惯上把1当做第一个丑数。

//方法1这样的方法实现起来比较容易，并且在面试中一般不会得到面试官的喜爱，所以这里只给出后2中方法的实现。
//方法2：
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
//方法3：
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
