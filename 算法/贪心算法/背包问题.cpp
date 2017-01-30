#include<iostream>
using namespace std;
#include<cassert>
#include<algorithm>
//��������
struct Object
{
       int _num;//��Ʒ�����
       int _weight;
       int _value;
       float _valuePerWeight;//ÿ�����ļ�ֵ
};
bool Compare(const Object& l, const Object& r)
{
       return l._valuePerWeight > r._valuePerWeight;
}
void Knapsack(Object objects[], int n,int capacity)
{
       assert(objects && n && capacity);
       int index = 0;
       int value = 0;
       //̰���㷨ʵ��
       while (index < n)
       {
              if (objects[index]._weight <= capacity)
              {
                     printf("������ȫװ��ȥ��%d����Ʒ\n", objects[index]._num);
                     capacity -= objects[index]._weight;
                     value += objects[index]._value;
                     ++index;
              }      
              else//װ����һ������Ʒ�����
              {
                     float proportion = (float)capacity / objects[index]._weight;
                     printf("ֻ��װ����%d����Ʒ��%f\n", objects[index]._num, proportion);
                     value += (proportion*objects[index]._value);
                     break;
              }
       }
       printf("��������װ��Ʒ�ļ�ֵ�ܺ�Ϊ��%d\n", value);
}
int main()
{
       int capacity = 0;//�������ܳ��ܵ�����
       cout << "�������ܳ��ܵ�����>:";
       cin >> capacity;
       int nObjects = 0;
       cout << "��Ҫװ�������Ʒ��>:";
       cin >> nObjects;//��Ҫװ�������Ʒ��
       Object* objects = new Object[nObjects];
       cout << "��������ÿ����Ʒ�������ͼ�ֵ"<<endl;
       for (int i = 0; i < nObjects; ++i)
       {
              objects[i]._num = i + 1;
              cin >> objects[i]._weight >> objects[i]._value;
              objects[i]._valuePerWeight = (float)(objects[i]._value) / (objects[i]._weight);
       }
       sort(objects, objects + nObjects, Compare);
       Knapsack(objects, nObjects,capacity);
       delete[] objects;
       system("pause");
       return 0;
}
