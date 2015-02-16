class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		int n = lists.size();
		if (n == 0) return NULL;
		while(n>1)
		{
			int mid = (n + 1) / 2;
			for (int i = 0; i < n / 2; ++i)
				lists[i] = mergeTwoLists(lists[i], lists[i + mid]);
			n = mid;
		}
		return lists[0];

	}

	
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		//creat a dummy head *dh
		ListNode *dh = new ListNode(0);
		ListNode *tmp = dh;

		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				tmp->next = l1;
				l1 = l1->next;
			}
			else{
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		if (l1 != NULL)
			tmp->next = l1;
		if (l2 != NULL)
			tmp->next = l2;

		tmp = dh;
		dh = dh->next;
		delete tmp;

		return dh;

	}
};
