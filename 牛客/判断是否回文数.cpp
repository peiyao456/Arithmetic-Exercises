#include<iostream>
using namespace std;
class Palindrome
{
public:
	Palindrome(const int& x)
		:_data(x)
	{}
	bool isPalindrome()
	{
		if (_data < 0)
			return false;
		if (_data == 0)
			return true;
		else
		{
			int finish = _data;
			int y = 0;
			while (finish != 0)
			{
				y = y * 10 + finish % 10;
				finish = finish / 10;
			}
			return _data == y ? true : false;
		}
	}
private:
	int _data;
};
void test()
{
	Palindrome num1(123454321);
	Palindrome num2(1234);
	cout << num1.isPalindrome() << endl;//1
	cout << num2.isPalindrome() << endl;//0
}
int main()
{
	test();
	system("pause");
	return 0;
}