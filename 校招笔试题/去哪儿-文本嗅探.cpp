//������һ���ַ����б���һ���ؼ����б������һ����Ч�㷨���������ؼ����б��йؼ���(һ������)���ַ�����
//�����ַ�������A�����Ĵ�Сn�Լ��ؼ�������key�����Ĵ�Сm���뷵��һ���ź���ĺ��ؼ��ʵ��ַ�����ŵ��б�
//��֤�����ַ�������С�ڵ���100���ؼ��ʸ���С�ڵ���100���ַ�������С�ڵ���200��
//��֤�����ַ���ȫ����СдӢ���ַ���ɡ��������ں��ؼ��ֵ��ַ������뷵��һ��ֻ��-1�����顣
class KeywordDetect {
public:
	vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m) {
		// write code here
		vector<int> ret;
		if (n <= 0 || m <= 0)
			return ret;
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			index = 0;
			int found = 0;
			while (index < m)
			{
				found = A[i].find(keys[index]);
				if (found != -1)
				{
					ret.push_back(i);//A[i]�к���key
					break;
				}
				else
				{
					++index;
				}
			}	
		}
        if(ret.size() == 0)
            ret.push_back(-1);
        else
			sort(ret.begin(),ret.end());
		return ret;
	}
};