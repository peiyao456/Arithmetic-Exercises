//��Ŀ�������Ը�����һ���ַ������ҳ����ظ����ַ�����������λ�ã�
//�磺abcaaAB12ab12 �����a��1��a��4��a��5��a��10��b��2��
//b��11��1��8��1��12�� 2��9��2��13��

#include<iostream>
using namespace std;
#include<string>

void GetPos(string s)
{
	bool first = false;
	for(int i = 0; i < s.size()-1; ++i)
	{
		if(s[i] == '#')//�����Ѿ��������ֵ���Ͳ���Ҫѭ����
			continue;
		first = false;
		for(int j = i + 1; j < s.size(); ++j)
		{
			if(s[j] == s[i])
			{
				if(!first)//����s[i]��ֻ��Ҫ��ӡһ�Σ�����֮��Ķ���ǲ���Ҫ��ӡ��
				{
					cout<<s[i]<<":"<<i;
					first = true;
				}
				cout<<","<<s[j]<<":"<<j;
				s[j] = '#';//���Ѿ��ҵ���λ�õ�ֵ����ǣ�֮��Ͳ���Ҫ�����ˡ�
			}
		}
		if(first)
			cout<<endl;
	}
}
int main()
{
	string s;
	while(cin>>s)
	{
		GetPos(s);
	}
	system("pause");
	return 0;
}