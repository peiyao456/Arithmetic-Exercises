//有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
//给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
class CloseNumber {
public:
    int Count(int x)
    {
        int count = 0;
        while (x)
        {
            ++count;
            x = x & (x - 1);
        }
        return count;
    }
    vector<int> getCloseNumber(int x) {
        // write code here
        int countOne = Count(x);
        vector<int> ret;
        for (int i = x - 1; i > 0; --i)
        {
            if (Count(i) == countOne)
            {
                ret.push_back(i);
                break;
            }   
        }
        for (int i = x + 1; ;++i)
        {
            if (Count(i) == countOne)
            {
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
