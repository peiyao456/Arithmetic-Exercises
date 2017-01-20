//���ַ������ҳ���һ��ֻ����1�ε��ַ��������롰abaccdeff�������b��
#include<iostream>
using namespace std;
#include<map>
#include<string>
//��������洢ͳ�ƽ����
char GetFirstNotRepeating(const string& s)
{
    if(s.size() == 0)
       return '\0';
    int HashArray[256] = {0};
    //ͳ���ַ����ֵĴ���
    for(size_t i = 0; i < s.size(); ++i)
    {
       HashArray[s[i]]++;
    }
    for(size_t i = 0; i < s.size(); i++)
    {
       if(HashArray[s[i]] == 1)
           return s[i];
    }
    return '\0';
}
int main()
{
    string s;
    getline(cin,s);
    char ret = GetFirstNotRepeating(s);
    cout<<ret<<endl;
    system("pause");
    return 0;
}
//����mapȥ�洢ͳ�ƽ����
char GetFirstNotRepeating(const string& s)
{
    if(s.size() == 0)
       return '\0';
    map<char,int> m;
    map<char,int>::iterator it = m.begin();
    for(int i = 0; i < s.size(); ++i)
    {
       m[s[i]]++;//operator[],û������в��룬���򷵻�value������
    }
    for(int i = 0; i < s.size(); ++i)
    {
       it = m.find(s[i]);//����ҵ������ص�ǰλ�õĵ����������򷵻�map::end
       if(it->second == 1)
           return s[i];
    }
    return '\0';
}
int main()
{
    string s;
    getline(cin,s);
    char ret = GetFirstNotRepeating(s);
    cout<<ret<<endl;
    system("pause");
    return 0;
}

//�����Ŀ
//1.�ӵ�һ���ַ�����ɾ����2���ַ����г��ֹ��������ַ���
//���������һ���ַ���"you are good",�ڶ����ַ���"root",���"yu ae gd".
void Erase(string s1,const string& s2)
{
    if(s1.size() == 0 || s2.size() == 0)
       return;
    string::iterator it = s1.begin();
    bool hash[256]={false};
    for(int i = 0; i < s2.size(); ++i)
    {
       hash[s2[i]] = true;
    }
    for(int i = 0; i < s1.size();)
    {
       if(hash[s1[i]] == true)
           s1.erase(it + i);
       else
           ++i;
    }
    cout<<s1<<endl;
}
int main()
{
    string s1;
    string s2;
    /*cin>>s1;
    cin>>s2;*///������Ҫ����д
    getline(cin,s1);
    getline(cin,s2);
    Erase(s1,s2);
    system("pause");
    return 0;
}
//2.ɾ���ַ����������ظ����ֵ��ַ�����������"google",���"gole"��
void EraseRepeating(const string& s)
{
    if(s.size() == 0)
       return;
    bool hash[256] = {false};
    for(int i = 0; i < s.size(); ++i)
    {
       hash[s[i]] = true;
    }
    string tmp;
    for(int i = 0; i < s.size(); ++i)
    {
       if(hash[s[i]] == true)
           tmp.push_back(s[i]);
       hash[s[i]] = false;
    }
    cout<<tmp<<endl;
}
int main()
{
    string s;
    getline(cin,s);
    EraseRepeating(s);
    system("pause");
    return 0;
}
//3.�ж����������Ƿ�Ϊ��λ�ʡ�
//��λ�ʾ�������������ʳ��ֵ���ĸ��ͬ������ĸ���ֵĴ���Ҳ��ͬ����ô���������ʻ�Ϊ��λ�ʡ�
bool IsAnagram(const string& s1,const string& s2)
{
    if(s1.size() == 0 || s2.size() == 0)
       return true;
    int hash[256] = {0};
    for(int i = 0; i < s1.size(); ++i)
    {
       hash[s1[i]]++;
    }
    for(int i = 0; i < s2.size(); ++i)
    {
       hash[s2[i]]--;
    }
    for(int i = 0; i < 256; ++i)
    {
       if(hash[i] != 0)
           return false;
    }
    return true;
}
int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    bool ret = IsAnagram(s1,s2);
    cout<<ret<<endl;
    system("pause");
    return 0;
}
