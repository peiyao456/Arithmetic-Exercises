//һ�����������г������������⣬�������ֶ����������Σ�
//���ҳ�������ֻ����һ�ε����֡�ʱ�临�Ӷ�ΪO��N�����ռ临�Ӷ�ΪO��1����
#include<iostream>
using namespace std;
//������ֻ����һ�ε�����
void GetAppearOnce(int arr[], int n, int* pNum1, int* pNum2)
{
    if(arr == NULL || n <= 0 || pNum1 == NULL || pNum2 == NULL)
       return;
    //������е�����
    int XORresult = 0;//���������������Ľ��
    for(int i = 0; i < n; ++i)
    {
       XORresult ^= arr[i];
    }
    if(XORresult == 0)
    {
       cout<<"������û�г���һ�ε�����"<<endl;
       return;
    }
    //�ҳ�XORresult��Ϊ��һλ
    int index = 0;
    while((XORresult & (1 << index)) == 0)
    {
       index++;
    }
    //XORresult�е�indexλ�ǣ����յ�indexλ�ǻ��ǽ��з���
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
    int arr[] = {2,5};//û���ظ�������
    //int arr[] = {2,5,6,8,8,2};
    int num1 = 0;
    int num2 = 0;
    GetAppearOnce(arr,sizeof(arr)/sizeof(arr[0]),&num1, &num2);
    cout<<num1 <<" "<<num2<<endl;
    system("pause");
    return 0;
}
