//������������һ������������ƽ���ĵ�λ���ֵ���������
// ����25��ƽ����625����λ������25�����25��һ����������
 //��һ�������ж�N�Ƿ�Ϊ�������� 
 
 
 #include<iostream>
using namespace std;

bool ObserveShapeNum(int n)
{
	int Pow = n * n;
	if(Pow % 100 == n || Pow %10 == n)
		return true;
	return false;
}
int main()
{
	int n = 0;
	bool ret = 0;
	while(cin>>n)
	{
		if(n >=2 && n < 100)
		{
			ret = ObserveShapeNum(n);
			if(ret)
				cout<<"Yes!"<<endl;
			else
				cout<<"No!"<<endl;
		}
	}
	return 0;
}