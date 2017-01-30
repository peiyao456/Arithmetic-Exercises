//给你一个非负数整数n，判断n是不是一些数（这些数不允许重复使用，且为正数）的阶乘之和，
//如9=1！+2!+3!，如果是，则输出Yes，否则输出No；
//第一行有一个整数0<m<100,表示有m组测试数据；每组测试数据有一个正整数n<1000000;
#include<iostream>
using namespace std;
bool IsSum(int num)
{
       if (num <= 0)
              return false;
       int  factorialArr[] = { 1,2,6,24,120,720,5040,40320,362880 };
       int index = 8;
       while (num > 0 && index >= 0)
       {
              if (num - factorialArr[index] >= 0)
                     num -= factorialArr[index];
              index--;//由于数据不能重复，所以无论减的结果是否大于0，index都要前移
       }
       if (num == 0)
              return true;
       else
              return false;
}
int main()
{
       int n = 0;
       cin >> n;
       while (n--)
       {
              int num = 0;
              cin >> num;
              if (IsSum(num))
              {
                     cout << "Yes" << endl;
              }
              else
                     cout << "No" << endl;
       }
       system("pause");
       return 0;
}
