#include<iostream>
using namespace std;
#include<stack>
class Conversion
{
public:
	Conversion(const int& data)
		:_data(data)
	{}
	void Convert()
	{
		while (_data)
		{
			s.push(_data % 2);
			_data = _data / 2;
		}
	}
	void Print()
	{
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
	}
private:
	int _data;
	stack<int> s;
};
int main()
{
	Conversion con(10);
	con.Convert();
	con.Print();
	system("pause");
	return 0;
}