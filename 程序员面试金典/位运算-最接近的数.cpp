//��һ�������������ҳ�������Ʊ�ʾ��1�ĸ�����ͬ���Ҵ�С��ӽ�������������(һ���Դ�һ����С)
//����������int x���뷵��һ��vector�������������������С����ǰ������֤�𰸴��ڡ�
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
