//��ĿҪ�󣺲�ʹ��ѭ���������жϣ���Ŀ�����ʵ��1+2+3+....+n
#include<iostream>
using namespace std;
//���캯��
class Sum
{
public:
	Sum()
	{
		++n;
		sum += n;
	}
	static void ShowSum()//�����Ǿ�̬��Ա����
	{
		cout << sum << endl;
	}
private:
	static size_t sum;
	static size_t n;
};
size_t Sum::sum = 0;
size_t Sum::n = 0;
int main()
{
	Sum* a = new Sum[100];
	delete[] a;
	a = NULL;
	Sum::ShowSum();
	system("pause");
	return 0;
}

//�麯��
class A
{
public:
	virtual size_t Sum(size_t n)
	{
		return 0;
	}
};
A* Array[2];
class B :public A
{
public:
	virtual size_t Sum(size_t n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};
int main()
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int sum = Array[1]->Sum(100);
	cout << sum << endl;
	system("pause");
	return 0;
}
//����ָ��ʵ��
typedef size_t(*fun)(size_t);
size_t sum1(size_t n)
{
	return 0;
}
size_t sum2(size_t n)
{
	fun f[2] = { sum1,sum2 };
	return n + f[!!n](n-1);
}
int main()
{
	cout<<sum2(100)<<endl;
	system("pause");
	return 0;
}
//ģ��ʵ��
template<size_t n>
struct Sum
{
	enum Value
	{
		N = Sum<n - 1>::N + n
	};
};
template<>
struct Sum<1>
{
	enum Value
	{
		N = 1
	};
};
int main()
{
	cout << Sum<100>::N << endl;
	system("pause");
	return 0;
}