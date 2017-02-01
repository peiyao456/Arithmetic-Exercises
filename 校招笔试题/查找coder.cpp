//�����һ����Ч�㷨���ٸ������ַ��������У��ҵ�������Coder�����ַ���(�����ִ�Сд)����������Ϊһ���µ����鷵�ء�
//����ַ�����˳���ա�Coder�����ֵĴ����ݼ����У����������С�Coder�����ֵĴ�����ͬ���򱣳�������ԭ�����е�λ��
//��ϵ�� 
// ����һ���ַ�������A�����Ĵ�Сn���뷵�ؽ�����顣��֤ԭ�����СС�ڵ���300,����ÿ�����ĳ���С�ڵ���200��
//ͬʱ��֤һ�����ڰ���coder���ַ����� 

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