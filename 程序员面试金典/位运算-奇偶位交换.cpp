//���д���򽻻�һ�����Ķ����Ƶ�����λ��ż��λ����ʹ��Խ�ٵ�ָ��Խ�ã�
//����һ��int x���뷵�ؽ��������int��
class Exchange {
public:
    int exchangeOddEven(int x) {
        // write code here
        int odd = (x & 0xAAAAAAAA);//��ȡx������λ��Ϣ
        int even = (x & 0x55555555);//ż��λ��Ϣ
        return (odd >> 1) + (even << 1);
    }
};
