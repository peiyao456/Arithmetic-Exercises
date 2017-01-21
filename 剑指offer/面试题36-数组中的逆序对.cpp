#include<iostream>
using namespace std;
//�����е������
long long GetMergePairsBetween(int* arr,int* copy,int start,int mid,int end)
{
    //�ϲ����������飬����������Ը���
    int final1 = mid;//��һ����������һλ
    int final2 = end;//�ڶ�����������һλ
    int index = end;//������������һλ
    long long count = 0;
    while(final1 >= start && final2 >= mid+1)//�������鶼û�д�����
    {
       if(arr[final1] > arr[final2])
       {
           //�����һ�������Ԫ�ش��ڵڶ���������κ�Ԫ�أ�
           //���һ�������Ԫ��һ�����ڵڸ�������final2֮ǰ������Ԫ��
           count += (final2 - mid);
           //��final1����Ԫ�ؿ�����copy����
           //index��final1����ǰ�ƶ�
           copy[index--] = arr[final1--];
       }
       else
       {
           //��һ�������Ԫ��С�ڵڶ��������Ԫ��
           //�ڶ��������Ԫ�ؿ�����copy����
           //����index��final2ǰ��
           copy[index--] = arr[final2--];
       }
    }
    while(final1 >= start)//��һ�������Ԫ��û�д�����
    {
       copy[index--] = arr[final1--];
    }
    while(final2 >= mid + 1)//��һ�������Ԫ��û�д�����
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
