////在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，
//请编写一个函数，使用递归的方法生成N位的格雷码。
//给定一个整数n，请返回n位的格雷码，顺序为从0开始。
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
