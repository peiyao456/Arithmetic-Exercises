//有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，
//返回“Error”。
//给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
class BinDecimal {
public:
#define exp pow(10,-7)
    string printBin(double num) {
        // write code here
        string ret;
        if (num >= 1)
            return ret;
        int count = 0;
        ret.push_back('0');
        ret.push_back('.');
        while (!(num > -exp && num < exp))
        {
            num = num * 2;
            if (num >= 1.0)
            {
                ++count;
                ret.push_back('1');
                num -= 1.0;
            }   
            else
            {
                ++count;
                ret.push_back('0');
            }
            if (count == 32){
              return "Error";
            }

        }
        return ret;
    }
};
