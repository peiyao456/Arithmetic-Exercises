//Sort a linked list using insertion sort
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
         if(head==NULL)
            return head;
        ListNode* newHead = head;
        ListNode* cur = head->next;
		ListNode* prev = head;
		while(cur)
		{
			if(cur->val >= prev->val)
			{
               cur = cur->next;
				prev = prev->next;				
			}
			else if(cur->val < newHead->val)
			{
				prev->next = cur->next;//移除结点cur
				cur->next = newHead;//cur头插到链表中
               newHead = cur;//改变排序链表的head
				cur = prev->next;
			}
			else
			{
				head = newHead;
				while(head->next->val < cur->val)//head对应的结点的值小于cur的值
				{
					head = head->next;
				}
				prev->next = cur->next;
				cur->next = head->next;
				head->next = cur;
				cur = prev->next;
			}
		}
		return newHead;         
    }
};