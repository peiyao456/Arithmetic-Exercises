#include<iostream>
using namespace std;
//����������ĵ�һ���ڵ�
//����ָ�뷨
struct ListNode
{
	int _data;
	ListNode* _pNext;
	ListNode(int x = 0)
		:_data(x)
		,_pNext(NULL)
	{}
};
ListNode* Create(int arr[],int n)
{
	ListNode* head = new ListNode(arr[0]);
	ListNode* prev = head;
	ListNode* cur = prev;
	for(int i = 1; i < n; ++i)
	{
		cur = new ListNode(arr[i]);
		prev->_pNext = cur;
		prev = cur;
	}
	return head;
}
size_t GetLength(ListNode* head)
{
	size_t len = 0;
	ListNode* cur = head;
	while(cur)
	{
		++len;
		cur = cur->_pNext;
	}
	return len;
}
ListNode* GetFirstCommonNode(ListNode* head1,ListNode* head2)
{
	size_t len1 = GetLength(head1);
	size_t len2 = GetLength(head2);
	ListNode* pLong = head1;
	ListNode* pShort = head2;
	int diff = len1 - len2;
	if(diff < 0)//��һ������ȵڶ��������
	{
		pLong  = head2;
		pShort = head1;
		diff = len2 - len1;
	}
	//�ó�����������diff��
	for(int i = 0; i < diff; ++i)
	{
		pLong = pLong->_pNext;
	}
	//��������һ��������ҵ�һ������
	while(pLong != NULL && pShort != NULL && pLong != pShort)
	{
		pLong = pLong->_pNext;
		pShort = pShort->_pNext;
	}
	if(pLong && pShort == 0)//û���ҵ��������
		return NULL;
	else
		return pShort;
}
void Destroy(ListNode* head)
{
	ListNode* cur = head;
	ListNode* del = NULL;
	while(cur)
	{
		del = cur;
		cur = cur->_pNext;
		delete del;
	}
}
ListNode* FindNode(ListNode* head,int data)
{
	ListNode* cur = head;
	while(cur)
	{
		if(cur->_data == data)
			return cur;
		cur = cur->_pNext;
	}
	return NULL;
}
int main()
{
	int arr1[] = {3,4,5,6,7,8};
	int arr2[] = {8,7};
	//��������
	ListNode* head1 = Create(arr1,sizeof(arr1)/sizeof(arr1[0]));
	ListNode* head2 = Create(arr2,sizeof(arr2)/sizeof(arr2[0]));
	//���콻��
	ListNode* Node1 = FindNode(head1,6);
	ListNode* Node2 = FindNode(head2,7);
	Node2->_pNext = Node1;
	//�󽻵�
	ListNode* ret = GetFirstCommonNode(head1,head2);
	if(ret)
		cout<<"�����ֵ�ǣ�"<<ret->_data <<endl;
	else
		cout<<"û�н���"<<endl;
	//��ɢ����������
	Destroy(head1);
	Node2->_pNext = NULL;
	Destroy(head2);
	system("pause");
	return 0;
}