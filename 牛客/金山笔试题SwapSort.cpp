//对一个数组按照给定的下标进行排序，仅使用两两交换的方式，要求不能对数组进行扩容，尽可能少的额外空间。
//如：原数组为A，B，C,D,E现给定的新位置为3,0,1,4,2那么排序后为D,A,B,E,C。

#include<iostream>
using namespace std;

void SwapSort(int a[],int pos[],int n)
{
	int count = 0;//用来记录已经处理的元素的个数
	int tmp = 0;
	int flag = 0;//记录tmp中存储元素的下标
	int index = 0;
	//找到第一个坑
	if(pos[0] != 0)
	{
		swap(a[0],tmp);
		flag = 0;
	}
	int i = 0;
	while(count < n)
	{
		a[i] = a[pos[i]];
		if(pos[i] == flag)
		{
			a[i] = tmp;
			pos[i] = i;
			++count;
			if(count == n)
				break;
			//要找到下一个坑
			for(int j = 0; j < n; ++j)
			{
				if(pos[j] != j)
				{
					flag = j;//改变标记位
					tmp = a[j];
					i = j;
					break;
				}
			}
		}

		else
		{
			index = i;	
			i = pos[i];
			pos[index] = index;//改变pos数组，方便之后找下一个坑
			++count;
		}
		
		
	}
	for(int i = 0; i < n; ++i)
	{
		cout<<a[i]<<endl;
	}
}
void TestSwapSort()
{
	int a[] = {'A','B','C','D','E','F','G','H','I'};
	int pos[] = {3,0,1,4,2,6,5,8,7};
	/*char a[] = {'A','B','C','D','E'};
	int pos[] = {3,0,1,4,2};*/
	SwapSort(a,pos,9);
}
int main()
{
	TestSwapSort();
	system("pause");
	return 0;
}