//��Ŀһ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
//Ϊ������������ź���ͨ�ַ�һ���������������ַ���"I am a student."
//����ַ���"student.  a am I".#include<iostream>
using namespace std;
#include<cassert>
void ReverseWord(char* begin, char* end)
{
       assert(begin && end);
       while (begin < end)
       {
              char tmp = *begin;
              *begin = *end;
              *end = tmp;
              begin++; 
              end--;
       }
}
void ReverseSentence(char* str,int len)
{
     assert(str);
     char* start = str;
     char* end = str;
     ReverseWord(start, str + len - 1);
     //
     while (*end != '\0')
     {
            while (*end != ' ' && *end != '\0')
            {
                   ++end;
            }//�����˿ո�����ַ���������
           ReverseWord(start, end - 1);
           if (*end != '\0')
            {
                   start = end + 1;
                   end = start;
            }
    }
}

int main()
{
       char str[] = "I am a student";
       ReverseSentence(str,sizeof(str)/sizeof(str[0])-1);
       cout << str << endl;
       system("pause");
       return 0;
}
//��Ŀ�����ַ���������ת�����ǰ��ַ�����ǰ�����ɸ��ַ��Ƶ��ַ�����β����
//�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ�����abcdefg��������2���������cdefgab��.
#include<iostream>
using namespace std;
#include<cassert>
//����
void ReverseWord(char* begin, char* end)
{
       assert(begin && end);
       while (begin < end)
       {
              char tmp = *begin;
              *begin = *end;
              *end = tmp;
              begin++;
              end--;
       }
}
void LeftRotate(char* str, int n)
{
       assert(str);
       int len = strlen(str);
       if (n < len && n > 0 && len > 0)
       {
              //�ȷ�תǰn
              ReverseWord(str, str + n - 1);
              //��ת��ߵ��ַ�
              ReverseWord(str + n, str + len - 1);
              //��ת����
              ReverseWord(str, str + len - 1);
       }
       
}
int main()
{
       char str[] = "abcdef";
       LeftRotate(str,2);
       cout << str << endl;
       system("pause");
       return 0;
}


