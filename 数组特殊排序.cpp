//输入一个数组的值,求出各个值从小到大排序后的次序。 

#include <iostream>
#include <algorithm>
using namespace std;
void Sort(int num)
{
	int count = 0;
	int temp;
	int j;
	int* ptr = new int[num];
	int* copyPtr = new int[num];
	for (int i = 0; i < num; i++) 
	{
		cin >> ptr[i];
		copyPtr[i] = ptr[i];
	}
	sort(copyPtr,copyPtr + num );
	for (int i = 0; i < num; i++) 
	{
		if (ptr[i] > copyPtr[0]) 
		{
			count = 2;
			temp = copyPtr[0];
		}
		else
			count = 1;
		j = 1;
		while(ptr[i] > copyPtr[j])
		{
			if (copyPtr[j] > temp) 
			{
				count ++;
				temp = copyPtr[j];
			}
			j++;
		}
		if (i == 0) 
			cout << count;
		else 
			cout << " " << count;
		count = 0;
	}
	cout << endl;
}
int main() 
{
	int num;
	while(cin >> num) 
	{
		Sort(num);
	}
	return 0;
}