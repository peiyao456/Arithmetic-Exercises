#include<iostream>
using namespace std;
//和为s的两个数字
bool FindNumsWithSum(int arr[], int len, int sum, int& num1, int& num2)
{
	bool found = false;
	if(len <= 1 || arr == NULL)
		return found;
	int head = 0;
	int tail = len - 1;
	while(head <= tail)
	{
		if(arr[head] + arr[tail] < sum)
			++head;
		else if(arr[head] + arr[tail] > sum)
			--tail;
		else//找到和为sum的两个数
		{
			num1 = arr[head];
			num2 = arr[tail];
			found = true;
			break;
		}
	}
	return found;
}
int main()
{
	int arr[] = {1, 2, 4, 7, 11, 15};
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	cin >> sum;
	bool ret = FindNumsWithSum(arr, sizeof(arr)/sizeof(arr[0]), sum, num1, num2);
	if(ret)
		cout<<num1 << " "<< num2<<endl;
	else
		cout<<"没有找到"<<endl;
	system("pause");
	return 0;
}

//和为s的连续正数序列
void PrintNums(int small, int big)
{
	for(int i = small; i <= big; ++i)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}
void FindContinuousPositive(const int& sum)
{
	if(sum <= 2)
	{
		cout<<"不能找到连续的正数序列"<<endl;
		return;
	}
	int small = 1;
	int big = 2;
	int mid = (1 + sum) / 2;
	int curSum = small + big;
	while(small < mid)
	{ 
		if(curSum == sum)
		{
			PrintNums(small,big);
		}
		
		while(curSum > sum && small < mid)
		{
			curSum -= small;
			++small;
			if(curSum == sum)
			{
				PrintNums(small,big);
			}
		}
		//curSum < sum
		++big;
		curSum += big;


		//while(curSum < sum && small < mid)
		//{
		//	++big;
		//	curSum += big;
		//	
		//	if(curSum == sum)
		//	{
		//		PrintNums(small,big);
		//	}
		//}
		////curSum > sum
		//curSum -= small;
		//++small;
	}
}
int main()
{
	int sum = 0;
	cin >> sum;
	FindContinuousPositive(sum);
	system("pause");
	return 0;
}