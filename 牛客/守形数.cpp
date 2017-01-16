//守形数是这样一种整数，它的平方的低位部分等于它本身。
// 比如25的平方是625，低位部分是25，因此25是一个守形数。
 //编一个程序，判断N是否为守形数。 
 
 
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