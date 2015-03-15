/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		//在head之前插入一个新建的节点
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;

		ListNode *p = dummy, *q = dummy;
		for (int i = 0; i < n; i++) // q 先走n 步
			q = q->next;
		while (q->next) { // 一起走
			p = p->next;
			q = q->next;
		}
		ListNode *tmp = p->next;
		p->next = p->next->next;
		delete tmp;
		return dummy->next;
	}
}; 
