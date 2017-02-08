//请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
//给定一个int x，请返回交换后的数int。
class Exchange {
public:
    int exchangeOddEven(int x) {
        // write code here
        int odd = (x & 0xAAAAAAAA);//换取x的奇数位信息
        int even = (x & 0x55555555);//偶数位信息
        return (odd >> 1) + (even << 1);
    }
};
