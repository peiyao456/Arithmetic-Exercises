//���������ַ���S1��S2���ϲ���һ���µ��ַ���S�� 
//�ϲ�����Ϊ��S1�ĵ�һ���ַ�ΪS�ĵ�һ���ַ�����S2�����һ���ַ���ΪS�ĵڶ����ַ���
//��S1�ĵڶ����ַ���ΪS�ĵ������ַ���
//��S2�ĵ����ڶ����ַ���ΪS�ĵ��ĸ��ַ����Դ����ơ�

#include<iostream>
using namespace std;
#include<string>
string MergeString(string s1,string s2)
{
	if(s1.size() != s2.size())
		return string();
	string s;
	for(int i = 0; i < s1.size(); ++i)
	{
		s.push_back(s1[i]);
		s.push_back(s2[s1.size()-i - 1]);
	}
	return s;
}
int main()
{
	string s1,s2,ret;
	while(cin>>s1>>s2)
	{
		ret = MergeString(s1,s2);
		cout<<ret<<endl;
	}
	return 0;
} 