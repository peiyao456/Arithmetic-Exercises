//题目一：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
//为简单起见，标点符号和普通字符一样处理。比如输入字符串"I am a student."
//输出字符串"student.  a am I".#include<iostream>
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
            }//遇到了空格或者字符串结束了
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
//题目二：字符串的左旋转操作是把字符串的前边若干个字符移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。比如输入字符串“abcdefg”和数字2，则输出“cdefgab”.
#include<iostream>
using namespace std;
#include<cassert>
//左旋
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
              //先翻转前n
              ReverseWord(str, str + n - 1);
              //翻转后边的字符
              ReverseWord(str + n, str + len - 1);
              //翻转整体
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


