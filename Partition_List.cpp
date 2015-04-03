class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
	    if(!head || !(head->next)) return head;
		ListNode *head1 = NULL;
		ListNode *cur1 = NULL;
		ListNode *head2 = NULL;
		ListNode *cur2= NULL;
		ListNode *cur=head;
		int flag1 = 0;
		int flag2 = 0;
		while (cur)
		{
			if (cur->val < x)
			{
				if (flag1 == 0)
				{
					head1 = cur;
					cur1 = cur;
				}
				else
				{
					cur1->next = cur;
					cur1 = cur;
				}
				flag1 = 1;
			}
			else
			{
				if (flag2 == 0)
				{
					head2 = cur;
					cur2 = cur;
				}
				else
				{
					cur2->next = cur;
					cur2 = cur;
				}
				flag2 = 1;
			}
			cur = cur->next;
		}
		if(!cur1 || !cur2) return head;
		cur1->next = head2;
		cur2->next = NULL;
		return head1;
	}
};
