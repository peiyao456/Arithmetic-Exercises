//��һ�����鰴�ո������±�������򣬽�ʹ�����������ķ�ʽ��Ҫ���ܶ�����������ݣ��������ٵĶ���ռ䡣
//�磺ԭ����ΪA��B��C,D,E�ָ�������λ��Ϊ3,0,1,4,2��ô�����ΪD,A,B,E,C��

#include<iostream>
using namespace std;

void SwapSort(int a[],int pos[],int n)
{
	int count = 0;//������¼�Ѿ������Ԫ�صĸ���
	int tmp = 0;
	int flag = 0;//��¼tmp�д洢Ԫ�ص��±�
	int index = 0;
	//�ҵ���һ����
	if(pos[0] != 0)
	{
		swap(a[0],tmp);
		flag = 0;
	}
	int i = 0;
	while(count < n)
	{
		a[i] = a[pos[i]];
		if(pos[i] == flag)
		{
			a[i] = tmp;
			pos[i] = i;
			++count;
			if(count == n)
				break;
			//Ҫ�ҵ���һ����
			for(int j = 0; j < n; ++j)
			{
				if(pos[j] != j)
				{
					flag = j;//�ı���λ
					tmp = a[j];
					i = j;
					break;
				}
			}
		}

		else
		{
			index = i;	
			i = pos[i];
			pos[index] = index;//�ı�pos���飬����֮������һ����
			++count;
		}
		
		
	}
	for(int i = 0; i < n; ++i)
	{
		cout<<a[i]<<endl;
	}
}
void TestSwapSort()
{
	int a[] = {'A','B','C','D','E','F','G','H','I'};
	int pos[] = {3,0,1,4,2,6,5,8,7};
	/*char a[] = {'A','B','C','D','E'};
	int pos[] = {3,0,1,4,2};*/
	SwapSort(a,pos,9);
}
int main()
{
	TestSwapSort();
	system("pause");
	return 0;
}