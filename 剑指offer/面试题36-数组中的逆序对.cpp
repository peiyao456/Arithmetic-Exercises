#include<iostream>
using namespace std;
//数组中的逆序对
long long GetMergePairsBetween(int* arr,int* copy,int start,int mid,int end)
{
    //合并两个子数组，并计算逆序对个数
    int final1 = mid;//第一个数组的最后一位
    int final2 = end;//第二个数组的最后一位
    int index = end;//辅助数组的最后一位
    long long count = 0;
    while(final1 >= start && final2 >= mid+1)//两个数组都没有处理完
    {
       if(arr[final1] > arr[final2])
       {
           //如果第一个数组的元素大于第二个数组的任何元素，
           //则第一个数组的元素一定大于第个数组中final2之前的所有元素
           count += (final2 - mid);
           //将final1处的元素拷贝至copy数组
           //index和final1都向前移动
           copy[index--] = arr[final1--];
       }
       else
       {
           //第一个数组的元素小于第二个数组的元素
           //第二个数组的元素拷贝至copy数组
           //并将index和final2前移
           copy[index--] = arr[final2--];
       }
    }
    while(final1 >= start)//第一个数组的元素没有处理完
    {
       copy[index--] = arr[final1--];
    }
    while(final2 >= mid + 1)//第一个数组的元素没有处理完
    {
       copy[index--] = arr[final2--];
    }
    for(int i = end; i > index;i--) 
        arr[i] = copy[i];
    return count;
}
long long GetMergePairs(int* arr,int* copy,int start,int end)
{
    long long ret = 0;
    if(start < end)
    {
       int mid = start + ((end - start)>>1);
       ret += GetMergePairs(arr,copy,start,mid);
       ret += GetMergePairs(arr,copy,mid+1,end);
       ret += GetMergePairsBetween(arr,copy,start,mid,end);
    }
    return ret;
}
long long GetTotalPairs(int arr[],int n)
{
    if(arr == NULL || n < 2)
       return 0;
    int* copy = new int[n];
    long long sum = GetMergePairs(arr,copy,0,n-1);
    return sum;
}
int main()
{
    int arr[] = {7,5,6,4};
    int ret = GetTotalPairs(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<ret<<endl;
    system("pause");
    return 0;
}
