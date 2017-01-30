#include<iostream>
using namespace std;
#include<cassert>
#include<algorithm>
//背包问题
struct Object
{
       int _num;//物品的序号
       int _weight;
       int _value;
       float _valuePerWeight;//每重量的价值
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
       //贪心算法实现
       while (index < n)
       {
              if (objects[index]._weight <= capacity)
              {
                     printf("可以完全装进去第%d件物品\n", objects[index]._num);
                     capacity -= objects[index]._weight;
                     value += objects[index]._value;
                     ++index;
              }      
              else//装不下一整件物品的情况
              {
                     float proportion = (float)capacity / objects[index]._weight;
                     printf("只能装进第%d件物品的%f\n", objects[index]._num, proportion);
                     value += (proportion*objects[index]._value);
                     break;
              }
       }
       printf("背包所能装物品的价值总和为：%d\n", value);
}
int main()
{
       int capacity = 0;//背包所能承受的容量
       cout << "背包所能承受的容量>:";
       cin >> capacity;
       int nObjects = 0;
       cout << "需要装入包的物品数>:";
       cin >> nObjects;//需要装入包的物品数
       Object* objects = new Object[nObjects];
       cout << "依次输入每个物品的重量和价值"<<endl;
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
