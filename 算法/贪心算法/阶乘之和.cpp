//����һ���Ǹ�������n���ж�n�ǲ���һЩ������Щ���������ظ�ʹ�ã���Ϊ�������Ľ׳�֮�ͣ�
//��9=1��+2!+3!������ǣ������Yes���������No��
//��һ����һ������0<m<100,��ʾ��m��������ݣ�ÿ�����������һ��������n<1000000;
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
              index--;//�������ݲ����ظ����������ۼ��Ľ���Ƿ����0��index��Ҫǰ��
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
