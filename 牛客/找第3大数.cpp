#include<iostream>
using namespace std;
#include<vector>

class Heap
{
public:
	Heap(const int* a, size_t size)
	{
		if (a != NULL && size > 0)
		{
			for (size_t i = 0; i < size; ++i)
			{
				_v.push_back(a[i]);
			}
			//向下调整
			for (int i = (size - 2) / 2; i >= 0; --i)
			{
				_AdjustDown(i);
			}
		}
	}
	void Pop()
	{
		if (_v.size() == 0)
			return;
		swap(_v[0],_v[_v.size()-1]);
		_v.pop_back();
		_AdjustDown(0);
	}
	const int& Top()
	{
		return _v[0];
	}
protected:
	void _AdjustDown(int root)
	{
		if (_v.size() == 0)
			return;
		int parent = root;
		size_t child = 2 * parent + 1;
		while (child < _v.size())
		{
			if (child + 1 < _v.size() && _v[child] < _v[child + 1])
				++child;
			if (_v[parent] < _v[child])
			{
				swap(_v[parent], _v[child]);
				parent = child;
				child = 2 * parent - 1;
			}
			else
				break;
		}
	}

private:
	vector<int> _v;
};

class Solution 
{
public:
	Solution(const int* a, size_t size)
		:_h(a,size)
	{}
	int thirdMax()
	{
		int count = 2;
		int ThirdMax = _h.Top();
		_h.Pop();
		while (count > 0)
		{
			if (_h.Top() != ThirdMax)
			{
				count--;
				ThirdMax = _h.Top();
				_h.Pop();
			}
			else
				_h.Pop();
		}
		return ThirdMax;
	}
private:
	Heap _h;
};
void test()
{
	int a[] = { 2,3,14,12,12,11 };
	Solution s(a,6);
	cout << s.thirdMax() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}