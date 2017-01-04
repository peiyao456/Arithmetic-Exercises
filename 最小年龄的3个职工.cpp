//职工有职工号，姓名，年龄.输入n个职工的信息，找出3个年龄最小的职工打印出来。
//输出结果行数为N和3的较小值，分别为年龄最小的职工的信息。
//关键字顺序：年龄>工号>姓名，从小到大。

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

struct Person
{
	int _num;
	string _name;
	int _age;
	friend istream& operator>>(istream& is,Person& p)
	{
		is>>p._num>>p._name>>p._age;
		return is;
	}
	friend ostream& operator<<(ostream& os,Person& p)
	{
		os<<p._num<<" "<<p._name<<" "<<p._age;
		return os;
	}
};
struct Compare
{
	bool operator()(const Person& l,const Person& r)
	{
		if(l._age < r._age)
		{
			return true;
		}
		else if(l._age > r._age)
		{
			return false;
		}
		else
		{
			if(l._num < r._num)
				return true;
			else if(l._num > r._num)
				return false;
			else
				return l._name < r._name;
		}
	}
};
void Print(Person* p,int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout<<p[i]<<endl;
	}
}
void GetThree(Person* p,int n)
{
	sort(p,p+n,Compare());
	if(n < 3)
		Print(p,n);
	else
		Print(p,3);
}
int main()
{
	int n = 0;
	while(cin >> n)
	{
		Person* p = new Person[n];
		for(int i = 0; i < n; ++i)
		{
			cin>>p[i];
		}
		GetThree(p,n);
	}
	return 0;
}