class Solution {
public:
	ListNode *swapPairs(ListNode *head) 
	{
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

		ListNode *result = NULL; 
		ListNode *p = NULL; //prev 

		ListNode *c = head; // curr
		ListNode *t = head->next;//temp

		for (int i = 0;; i = i + 2)
		{
			if (i == 0)
			{
				result = head->next;// result points to the 2nd node as new head
			}
		
			c->next = t->next;
			if (i != 0) 
				p->next = t;
			t->next = c;
			p = c;
			c = c->next;
			if (c==NULL ||c->next == NULL) 
			{
				return result;
			}
			
			t = c->next;
			
		}
	}
};
