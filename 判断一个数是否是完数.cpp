//��Ŀ˵�������һ����ǡ�õ�����������֮�ͣ���ô������������
//���磺6��������1,2,3����6 = 1+2+3 ������6��������
#include<iostream>
using namespace std;
bool CompleteNumber(int n)
{
	int count = 0;
	for(int i = 1 ; i <= n/2; ++i)
	{
		if(n % i == 0)
			count += i;
	}
	if(count == n)
		return true;
	else
		return false;
}
int main()
{
	int n = 0;
	cin >> n;
	int ret = CompleteNumber(n);
	if(ret)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	system("pause");
	return 0;
}