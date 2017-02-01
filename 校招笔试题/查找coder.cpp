//请设计一个高效算法，再给定的字符串数组中，找到包含”Coder”的字符串(不区分大小写)，并将其作为一个新的数组返回。
//结果字符串的顺序按照”Coder”出现的次数递减排列，若两个串中”Coder”出现的次数相同，则保持他们在原数组中的位置
//关系。 
// 给定一个字符串数组A和它的大小n，请返回结果数组。保证原数组大小小于等于300,其中每个串的长度小于等于200。
//同时保证一定存在包含coder的字符串。 

bool Compare(const pair<string, int>& l, const pair<string, int>& r) {
    return l.second > r.second;
}
class Coder {
    string change(string str) {
        string ans = str;
        for (int i = 0;i<str.length();i++)
            if (str[i] >= 'A'&&str[i] <= 'Z')
                ans[i] = str[i] + 32;
        return ans;
    }
    int Count(const string& s) {
        string str = change(s);
        int count = 0;
        string substr = "coder";
        for (int i = 0; i < str.size(); ++i) {
            int found = str.find(substr, i);
            if (found != -1){
                count++;
                i =  found + 1;
            }
            else
                break;
        }
        return count;
    }

public:
    vector<string> findCoder(vector<string> A, int n) {
        // write code here
        if (A.size() < 1)
            return A;
        vector<pair<string, int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back(make_pair(A[i], Count(A[i])));
        }
        stable_sort(v.begin(), v.end(),Compare);
        vector<string> ret;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].second > 0)
                ret.push_back(v[i].first);
            if (v[i].second == 0)
                break;
        }
        return ret;
    }
};