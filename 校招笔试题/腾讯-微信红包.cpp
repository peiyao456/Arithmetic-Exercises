//�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺������
//��һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
//����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ���û�н���������һ�룬����0�� 
class Gift {  
public:  
    int getValue(vector<int> gifts, int n) {  
        // write code here  
        if (n <= 0)  
            return 0;  
        map<int, int> m;  
        for (int i = 0; i < n; ++i)  
        {  
            m[gifts[i]]++;  
        }  
        map<int, int>::iterator itMap = m.begin();  
        while (itMap != m.end())  
        {  
            if (itMap->second > n / 2)  
                break;  
            else  
                ++itMap;  
        }  
        if (itMap == m.end())  
            return 0;  
        else  
            return itMap->first;  
    }  
};  
