class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next) return head;
		if (head->next->val == head->val)//如果head要删除
		{
			while (head->next && head->next->val == head->val)
			{
				head = head->next;//找到第一个同值结点
			}
			head = deleteDuplicates(head->next);
		}
		else
		{
			head->next = deleteDuplicates(head->next);
		}
		return head;
	}
};
