//��һ������0��1֮���ʵ��������Ϊdouble���������Ķ����Ʊ�ʾ������������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ��
//���ء�Error����
//����һ��double num����ʾ0��1��ʵ�����뷵��һ��string����������Ķ����Ʊ�ʾ���ߡ�Error����
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
