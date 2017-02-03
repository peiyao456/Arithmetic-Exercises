#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
//�˿���˳��
bool IsContinuous(vector<int> v)
{
	if (v.size() < 1)
		return false;
	//����
	sort(v.begin(),v.end());
	//ͳ�Ƴ�v��0�ĸ���
	int count = 0;
	int index = 0;
	while (v[index] == 0)
	{
		++count;
		++index;
	}
	//��������֮��ļ��
	int small = index;
	int big = index + 1;
	int diff = 0;
	while (big < v.size())
	{
		if (v[small] == v[big])//�ж��ӳ���
			return false;
		//������
		diff += (v[big] - v[small] - 1);
		small = big;
		++big;
	}
	if (diff == count || diff == 0)
		return true;
	return false;
}
int main()
{
	int arr[5] = { 1,2,3,0,0 };
	vector<int> v(arr,arr+5);
	cout << IsContinuous(v) << endl;
	system("pause");
	return 0;
}
