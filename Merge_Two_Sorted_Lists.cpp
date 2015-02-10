/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
public:
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
