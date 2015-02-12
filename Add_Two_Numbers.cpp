class Solution {
public:
	int flag = 0;//是否进位
	int sumDigit(int n1, int n2)
	{
		int sum = 0;
		int tmp = n1 + flag + n2;
		if (tmp / 10 > 0)
		{
			flag = 1;//进位
			sum = tmp % 10;
		}
		else
		{
			flag = 0;//不进位
			sum = tmp;
		}
		return sum;
	}

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *result = l1;
		ListNode *prev1 = l1;
		ListNode *prev2 = l2;

		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		while (l1 != NULL && l2 != NULL)
		{
			l1->val = sumDigit(l1->val, l2->val);
			prev1 = l1;
			prev2 = l2;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1 == NULL && l2 == NULL)
		{
			if (flag != 0)
				prev1->next = new ListNode(1);
		}
		if (l1 == NULL && l2 != NULL)
		{
			prev1->next = l2;
			prev2->next = NULL;
			while (l2 != NULL)
			{
				if (flag != 0)
					l2->val = sumDigit(l2->val, 0);
				prev1 = l2;
				l2 = l2->next;
			}
			if (flag != 0)
				prev1->next = new ListNode(1);
		}
		if (l1 != NULL && l2 == NULL)
		{
			while (l1 != NULL)
			{
				if (flag != 0)
					l1->val = sumDigit(l1->val, 0);
				prev1 = l1;
				l1 = l1->next;
			}
			if (flag != 0)
				prev1->next = new ListNode(1);
		}
		return result;
	}
};
