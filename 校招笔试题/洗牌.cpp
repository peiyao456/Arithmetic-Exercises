//ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ�
//��3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n��
//���°�ѣ������žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵĵ����ڶ���
//�ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ����Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ��
//��������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1������
//�������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� 
//���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С� 

#include<iostream>
using namespace std;
#include<vector>
#include<stack>
void Shuffle(vector<int> v,int k)
{
	stack<int> s;
	stack<int> s1;
	stack<int> s2;
	while (k--)
	{
		size_t i = 0;
		for (i = 0; i < v.size() / 2; ++i)
		{
			s1.push(v[i]);
		}
		for (i = v.size() / 2; i < v.size(); ++i)
		{
			s2.push(v[i]);
		}
		v.clear();
		while (!s1.empty() || !s2.empty())
		{
			s.push(s2.top());
			s2.pop();
			s.push(s1.top());
			s1.pop();
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
	}
	cout << v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		cout << " " << v[i];
	}
    cout<<endl;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;//2n����
		int k = 0;
		cin >> n >> k;
		vector<int> v;
		n *= 2;
		while (n--)
		{
			int tmp;
			cin >>tmp;
			v.push_back(tmp);
		}
		Shuffle(v, k);
	}
	return 0;
}