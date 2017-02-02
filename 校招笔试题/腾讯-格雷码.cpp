////��һ�����ı����У��������������ڵĴ���ֻ��һλ����������ͬ�� ������ֱ���Ϊ������(Gray Code)��
//���дһ��������ʹ�õݹ�ķ�������Nλ�ĸ����롣
//����һ������n���뷵��nλ�ĸ����룬˳��Ϊ��0��ʼ��
class GrayCode {  
public:  
    vector<string> getGray(int n) {  
        // write code here  
        vector<string> grayCode;  
        if (n == 1)  
        {  
            grayCode.push_back("0");  
            grayCode.push_back("1");  
            return grayCode;  
        }  
        vector<string> last = getGray(n-1);  
        for (int i = 0; i < last.size(); ++i)  
        {  
            grayCode.push_back("0"+last[i]);  
        }  
        for (int i = last.size()-1; i >= 0 ; --i)  
        {  
            grayCode.push_back("1" + last[i]);  
        }  
        return grayCode;  
    }  
};  
