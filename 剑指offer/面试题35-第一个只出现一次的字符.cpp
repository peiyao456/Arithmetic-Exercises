//在字符串中找出第一个只出现1次的字符。如输入“abaccdeff”，输出b。
#include<iostream>
using namespace std;
#include<map>
#include<string>
//利用数组存储统计结果：
char GetFirstNotRepeating(const string& s)
{
    if(s.size() == 0)
       return '\0';
    int HashArray[256] = {0};
    //统计字符出现的次数
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
//利用map去存储统计结果：
char GetFirstNotRepeating(const string& s)
{
    if(s.size() == 0)
       return '\0';
    map<char,int> m;
    map<char,int>::iterator it = m.begin();
    for(int i = 0; i < s.size(); ++i)
    {
       m[s[i]]++;//operator[],没有则进行插入，有则返回value的引用
    }
    for(int i = 0; i < s.size(); ++i)
    {
       it = m.find(s[i]);//如果找到，返回当前位置的迭代器。否则返回map::end
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

//相关题目
//1.从第一个字符串中删除第2个字符串中出现过的所有字符。
//比如输入第一个字符串"you are good",第二个字符串"root",输出"yu ae gd".
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
    cin>>s2;*///尽量不要这样写
    getline(cin,s1);
    getline(cin,s2);
    Erase(s1,s2);
    system("pause");
    return 0;
}
//2.删除字符串中所有重复出现的字符。比如输入"google",输出"gole"。
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
//3.判断两个单词是否互为变位词。
//变位词就是如果两个单词出现的字母相同并且字母出现的次数也相同，那么这两个单词互为变位词。
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
