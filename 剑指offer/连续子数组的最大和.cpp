//����һ���������飬������������Ҳ�и�����
//������һ�������������������һ�������飬
//������������͵����ֵ��ʱ�临�Ӷ�ΪO(N)��

#include<iostream>
using namespace std;

bool isInvalid = false;//�Ƿ����� 
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
		cout<<"�Ƿ�����"<<endl;
		return 0;
	}	
	cout<<ret<<endl;
	system("pause");
	return 0;
}