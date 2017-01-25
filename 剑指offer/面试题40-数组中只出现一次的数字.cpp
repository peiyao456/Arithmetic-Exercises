//一个整形数组中除了两个数字外，其他数字都出现了两次，
//请找出这两个只出现一次的数字。时间复杂度为O（N），空间复杂度为O（1）。
#include<iostream>
using namespace std;
//数组中只出现一次的数字
void GetAppearOnce(int arr[], int n, int* pNum1, int* pNum2)
{
    if(arr == NULL || n <= 0 || pNum1 == NULL || pNum2 == NULL)
       return;
    //异或所有的数字
    int XORresult = 0;//所有数字异或出来的结果
    for(int i = 0; i < n; ++i)
    {
       XORresult ^= arr[i];
    }
    if(XORresult == 0)
    {
       cout<<"数组中没有出现一次的数字"<<endl;
       return;
    }
    //找出XORresult中为的一位
    int index = 0;
    while((XORresult & (1 << index)) == 0)
    {
       index++;
    }
    //XORresult中第index位是，按照第index位是还是进行分组
    for(int i = 0; i < n; ++i)
    {
       if(arr[i] & (1 << index))
           (*pNum1) ^= arr[i];
    }
    //
    (*pNum2) = XORresult ^ *pNum1;
}
int main()
{
    int arr[] = {2,5};//没有重复的数字
    //int arr[] = {2,5,6,8,8,2};
    int num1 = 0;
    int num2 = 0;
    GetAppearOnce(arr,sizeof(arr)/sizeof(arr[0]),&num1, &num2);
    cout<<num1 <<" "<<num2<<endl;
    system("pause");
    return 0;
}
