//输入一个整形数组，数组中有正数也有负数。
//数组中一个或多个连续的整数组成一个子数组，
//求所有子数组和的最大值，时间复杂度为O(N)。

#include<iostream>
using namespace std;

bool isInvalid = false;//非法输入 
int FindMaxSum(int arr[],int n)
{
	if(arr == NULL || n <= 0)
	{
		isInvalid = true;
		return 0;
	}
	int curSum = 0;
	int maxSum = 0;
	for(int i = 0; i < n; ++i)
	{
		if(curSum < 0)
			curSum = arr[i];
		else
			curSum += arr[i];
		if(curSum > maxSum)
			maxSum = curSum;
	}
	return maxSum;
}
int main()
{
	//int arr[] = {1,-2,3,10,-4,7,2,-5};
	int arr[] = {1,-2,3,4,-2,5,-4};
	//int ret = FindMaxSum(arr,7);
	int ret = FindMaxSum(arr,0);
	if(isInvalid)
	{
		cout<<"非法输入"<<endl;
		return 0;
	}	
	cout<<ret<<endl;
	system("pause");
	return 0;
}