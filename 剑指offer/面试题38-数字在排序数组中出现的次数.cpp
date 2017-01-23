//�������������������г��ֵĴ���
#include<iostream>
using namespace std;

//˼·�����ֲ��ҵķ������ҵ���һ��k�����һ��k��Ȼ��������
int GetFirstKIndex(int arr[], int length, int k, int start, int end)
{
	if(start > end)//û���ҵ�
		return -1;
	//int mid = start + ((end - start)>>1);
	int mid = (start + end) /2;
	//�м�����ݾ���k
	if(arr[mid] == k)
	{
		//���Ƿ��ǵ�һ��k
		if((mid > 0 && arr[mid - 1] != k) || mid == 0)//���ǵ�һ��k
			return mid;
		else
			end = mid - 1;
	}
	//�м�����ݴ���k
	else if(arr[mid] > k)
		end = mid - 1;
	else
		start = mid + 1;
	return GetFirstKIndex(arr,length,k,start,end);
}
int GetLastKIndex(int arr[],int length, int k, int start, int end)
{
	if(start > end)//û���ҵ�
		return -1;
	int mid = start + ((end - start)>>1);
	//�м�����ݾ���k
	if(arr[mid] == k)
	{
		//�����һ��k
		if((mid < length - 1 && arr[mid + 1] != k) || mid == length - 1)
			return mid;
		//�������һ��k
		else
			start = mid + 1;
	}
	//�м�����ݴ���k
	else if(arr[mid] > k)
		end = mid - 1;
	else
		start = mid + 1;
	return GetLastKIndex(arr,length,k,start,end);
}
int GetCountK(int arr[],int length,int k)
{
	int count = 0;
	if(arr != NULL && length > 0)
	{
		int first = GetFirstKIndex(arr,length, k, 0,length - 1);
		int last = GetLastKIndex(arr,length, k, 0,length - 1);
		if(first > -1 && last > -1)
			count = last - first + 1;
	}
	return count;
}
int main()
{
	int arr[] = {1,2,3,3,3,3,4,5};
	//int ret = GetCountK(arr,sizeof(arr)/sizeof(arr[0]),3);
	//int ret = GetCountK(arr,sizeof(arr)/sizeof(arr[0]),5);
	int ret = GetCountK(arr,sizeof(arr)/sizeof(arr[0]),8);
	cout<< ret<<endl;
	system("pause");
	return 0;
}